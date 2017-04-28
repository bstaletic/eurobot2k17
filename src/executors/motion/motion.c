#include "motion.h"
#include "motion_command.h"

static void refresh_state(void);
static void motion_command_reset(void);
static void current_motion_resume(void);
static void motion_command_pause(void);
static uint8_t enemy_detected(motion_state state);
static uint8_t can_retry(void);
static uint8_t is_in_field(point_t enemy);
static double to_radian(int16_t angle);
static void process_motion_command(void);
static point_t calculate_curve_destination(struct curve_cmd_struct* cmd_struct);

static uint8_t current_motion_command_set = 0;
static uint8_t command_paused = 0;
static uint8_t motion_command_suspended = 0;
static uint8_t giveUp = 0;
static void* motion_queue[MAX_MOTION_QUEUE_LENGTH];
static uint8_t commands_in_queue;
static uint8_t can_use_pf = 0;
static point_t current_destination = { 0, 0 };
static point_t previous_destination;
static const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
static uint8_t shouldStop = 0;

typedef enum { FORWARD, BACKWARD } motion_direction;
static motion_direction direction = FORWARD;

osMutexDef(motion_mutex_def);
osMutexId (motion_mutex);

void motion_main(void){
	int shouldStop = 0;
	debug("Motion executor started");
	debug("Resetting motion command");
	motion_command_reset();
	while(1)
	{
		if (shouldStop)
		{
			motion_command_reset();
			break;
		}
		// Check if robot can go where the robot is headed
		if (current_motion_command_set)
		{
			if (enemy_detected(state))
			{
				if (motion_command_suspended)
				{
					if (!can_retry())
					{
						// Commented out - path finding not ready
//						giveUp = 1;
//						if (can_use_pf && should_use_pf)
//						{
//							//path finding
//						}
//						if (giveUp)
//						{
						error("Canceling motion - enemy won't move away");
						motion_command_reset();
//						}
					}
				}
				else
				{
					info("Enemy detected - pausing motion");
					motion_command_pause();
				}
			}
			else if (motion_command_suspended)
			{
				info("Resuming motion - way ahead is clear");
				current_motion_resume();
			}
		}
		// Process next command
		if (motion_queue[0] != NULL && state.status == MOTION_IDLE && current_motion_command_set == 0)
		{
			osDelay(1);
			refresh_state();
			process_motion_command();
		}
		// Refresh state data
		if (state_refresh_needed)
			refresh_state();
		// Say that you're done moving
		if (state.status == MOTION_IDLE && current_motion_command_set && !command_paused)
			current_motion_command_set = 0;
		if ((state.status == MOTION_ERROR || state.status == MOTION_STUCK) && current_motion_command_set)
		{
			if (state.status == MOTION_ERROR) error("Motion command error");
			if (state.status == MOTION_STUCK) error("Motion stuck!");
			motion_command_reset();
		}
		osDelay(6);
	} // while(1)
}

static void current_motion_resume(void)
{
	current_destination = previous_destination;
	motion_command_suspended = 0;
	goto_xy(current_destination.x, current_destination.y, direction);
}

static void motion_command_reset(void)
{
	debug("motion_command_reset");
	current_motion_command_set = 0;
	hard_stop();
}

static void motion_command_pause(void)
{
	debug("motion_command_pause");
	hard_stop();
	previous_destination = current_destination;
	motion_command_suspended = 1;
	command_paused = 1;
}

static uint8_t enemy_detected(motion_state state)
{
	if (state.status == MOTION_ROTATING)
		return 0;
	// If nothing on the moving side
	if ((direction == FORWARD && !(FRONT_LEFT_SENSOR ||
			FRONT_RIGHT_SENSOR)) ||
			(direction == BACKWARD && !BACK_SENSOR))
		return 0;

	return 1;
}

void motion_queue_push(void* command)
{
	if (commands_in_queue >= MAX_MOTION_QUEUE_LENGTH)
	{
		error("Motion queue already full.\n"
				"Currently in queue: %d", commands_in_queue);

		vPortFree(command);
	}
	else
	{
		if (osMutexWait(motion_mutex, MOTION_MUTEX_WAIT_MS) == osOK)
		{
			motion_queue[commands_in_queue] = command;
			commands_in_queue++;

			//			osDelay(1);

			osMutexRelease(motion_mutex);

			osThreadYield();
		}
		else
		{
			error("MOTION CAN'T GET MUTEX - PUSH");
		}
	}

}

void* motion_queue_pull(void)
{
	void* command = NULL;
	if (!commands_in_queue)
	{
		info("No commands in queue");
	}
	else
	{
		if (osMutexWait(motion_mutex, MOTION_MUTEX_WAIT_MS) == osOK)
		{
			command = motion_queue[0];
			//memmove(motion_queue, motion_queue + 1, commands_in_queue - 1);
			for (int i = 0; i < commands_in_queue - 1; ++i)
				motion_queue[i] = motion_queue[i + 1];
			commands_in_queue--;
			motion_queue[commands_in_queue] = NULL;

			osMutexRelease(motion_mutex);

			osThreadYield();
		}
		else
		{
			error("MOTION CAN'T GET MUTEX - PULL");
		}
	}
	return command;
}

uint8_t can_retry(void)
{
	static uint16_t retry_count;
	if (retry_count >= MAX_RETRY_COUNT)
	{
		retry_count = 0;
		return 0;
	}
	else
	{
		retry_count++;
		return 1;
	}
}

uint8_t is_in_field(point_t enemy)
{
	if (enemy.x > X_MIN && enemy.x < X_MAX && enemy.y > Y_MIN && enemy.y < Y_MAX)
	{
		if (enemy.x > START_FIELD_X_MIN && enemy.x < START_FIELD_X_MAX &&
				((enemy.y > ALLY_START_FIELD_Y_MAX && enemy.y < ENEMY_START_FIEL_Y_MIN)))
		{
			debug("Detected enemy is in start field");
			return 0;
		}
		else
		{
			debug("Detencted enemy is in allowed area");
			return 1;
		}
	}
	else
	{
		debug("Detected object is outside the playing field");
		return 0;
	}

}

static double to_radian(int16_t angle)
{
	return angle * pi / 180;
}

static void process_motion_command(void)
{
	// TODO: What if no more commands?
	static int cnt = 0;
	void* cmd_temp = motion_queue_pull();
	motion_cmd_id_t id = ((struct set_xy_cmd_struct*)cmd_temp)->id;
	debug("Motion Command ID = %d\tCnt = %d", id, ++cnt);
	switch (id){
	case SET_XY:
	{
		struct set_xy_cmd_struct* cmd = cmd_temp;
		set_position_and_orientation(cmd->x, cmd->y, cmd->orientation);
		vPortFree(cmd);
		break;
	}
	case READ_STATUS:
	{
		//struct read_status_cmd_struct* cmd = cmd_temp;
		read_status_and_position();
		break;
	}
	case MOVE_FORWARD:
	{
		struct move_forward_cmd_struct* cmd = cmd_temp;
		current_motion_command_set = 1;
		can_use_pf = 0;
		current_destination.x = state.x + cmd->dist * cos(to_radian(state.orientation));
		current_destination.y = state.y + cmd->dist * sin(to_radian(state.orientation));
		if (cmd->dist > 0)
			direction = FORWARD;
		else
			direction = BACKWARD;
		move_forward(cmd->dist);
		vPortFree(cmd);
		break;
	}
	case ROTATE_FOR:
	{
		struct rotate_for_cmd_struct* cmd = cmd_temp;
		debug("rotate for: %d",cmd->angle);
		current_motion_command_set = 1;
		can_use_pf = 0;
		current_destination.x = state.x;
		current_destination.y = state.y;
		// HAL_TIM_Base_Stop_IT(&htim7);
		rotate_for(cmd->angle);
		// HAL_TIM_Base_Start_IT(&htim7);
		vPortFree(cmd);
		break;
	}
	case ROTATE_TO:
	{
		struct rotate_to_cmd_struct* cmd = cmd_temp;
		debug("rotate to: %d",cmd->angle);
		current_motion_command_set = 1;
		can_use_pf = 0;
		current_destination.x = state.x;
		current_destination.y = state.y;
		rotate_to(cmd->angle);
		vPortFree(cmd);
		break;
	}
	case GOTO_XY:
	{
		struct goto_xy_cmd_struct* cmd = cmd_temp;
		debug("go to x: %d, y: %d, direction: %d",cmd->x,cmd->y,cmd->direction);
		current_motion_command_set = 1;
		can_use_pf = cmd->use_pf;
		current_destination.x = cmd->x;
		current_destination.y = cmd->y;
		direction = cmd->direction? FORWARD : BACKWARD;
		goto_xy(cmd->x, cmd->y, cmd->direction);
		vPortFree(cmd);
		break;
	}
	case CURVE:
	{
		struct curve_cmd_struct* cmd = cmd_temp;
		debug("curve: ");
		current_motion_command_set = 1;
		can_use_pf = 0;
		current_destination = calculate_curve_destination(cmd);
		direction = cmd->direction;
		curve(cmd->x, cmd->y, cmd->angle, cmd->angle_direction, cmd->direction);
		vPortFree(cmd);
		break;
	}
	case HARD_STOP:
	{
		//struct hard_stop_cmd_struct* cmd = cmd_temp;
		debug("hard stop");
		hard_stop();
		break;
	}
	case SOFT_STOP:
	{
		//struct soft_stop_cmd_struct* cmd = cmd_temp;
		debug("soft stop");
		soft_stop();
		break;
	}
	case RESET_DRIVER:
	{
		//struct reset_driver_cmd_struct* cmd = cmd_temp;
		debug("reset driver");
		reset_driver();
		break;
	}
	case STUCK_ENABLE:
	{
		//struct stuck_enable_cmd_struct* cmd = cmd_temp;
		debug("stuck enable");
		stuck_enable();
		break;
	}
	case STUCK_DISABLE:
	{
		//struct stuck_disable_cmd_struct* cmd = cmd_temp;
		debug("stuck disable");
		stuck_disable();
		break;
	}
	case SET_SPEED:
	{
		struct set_motion_speed_cmd_struct* cmd = cmd_temp;
		debug("set speed: %d", cmd->speed);
		set_motion_speed(cmd->speed);
		vPortFree(cmd);
		break;
	}
	default:
		error("Unknown motion command id");
	}
}

point_t calculate_curve_destination(struct curve_cmd_struct* cmd_struct)
{
	point_t dest = { 0, 0 };
	return dest;
}

void motion_ctor(void)
{
	motion_mutex = osMutexCreate(osMutex(motion_mutex_def));

	if (motion_mutex == NULL)
	{
		error("Motion mutex not created - exiting");
		shouldStop = 1;
	}
	else
	{
		info("Motion mutex created - All good");
	}
}

void refresh_state(void)
{
	uint8_t temp[7];
	//	debug("sending P");
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"P", 1, 1);
	//	debug("P sent");
	HAL_UART_Receive(MOTION_DRIVER, temp, 7, 50);
	//	debug("got data");
	switch (temp[0])
	{
	case 'I':
		state.status = MOTION_IDLE;
		break;
	case 'M':
		state.status = MOTION_MOVING;
		break;
	case 'R':
		state.status = MOTION_ROTATING;
		break;
	case 'S':
		state.status = MOTION_STUCK;
		break;
	case 'E':
		state.status = MOTION_ERROR;
		break;

	}
	state.x = (temp[1] << 8 ) | (temp[2] & 0xff);
	state.y = (temp[3] << 8 ) | (temp[4] & 0xff);
	state.orientation = (temp[5] << 8) | (temp[6] & 0xff);

	state_refresh_needed = 0;
}

void wait_for_motion(void)
{
	uint8_t motion_free;
	do
	{
		motion_free = motion_queue[0] == NULL && state.status == MOTION_IDLE;
	}
	while(!motion_free);
}
