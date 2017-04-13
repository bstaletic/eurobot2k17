#include "motion.h"
#include "motion_command.h"

static void motion_command_reset(void);
static void current_motion_resume(void);
static void motion_command_pause(void);
static uint8_t enemy_detected(motion_state state);
static uint8_t can_retry(void);
static uint8_t is_in_field(point_t enemy);
static double to_radian(int16_t angle);
static void process_motion_command(void);
static point_t calculate_curve_destination(struct curve_cmd_struct* cmd_struct);

static uint8_t current_motion_command_set;
static uint8_t motion_command_suspended = 1;
static uint8_t giveUp = 0;
static void* motion_queue[MAX_MOTION_QUEUE_LENGTH] = { NULL };
static uint8_t commands_in_queue;
static uint8_t can_use_pf = 0;
static point_t current_destination;
static point_t previous_destination;
static const double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

typedef enum { FORWARD, BACKWARD } motion_direction;
static motion_direction direction = FORWARD;

osMutexDef(motion_mutex_def);
osMutexId (motion_mutex);

void motion_main(void){
	int shouldStop = 0;
	debug("Motion executor started");
	debug("Resetting motion command");
	motion_command_reset();
	while(1){
		if (shouldStop)
			break;
		// Check if command is set and if so,
		// check if robot can move in that direction
		if (current_motion_command_set)
		{
			if (enemy_detected(state))
			{
				debug("ENEMY DETECTED");
				if (motion_command_suspended)
				{
					if (!can_retry())
					{
						giveUp = 1;
		//***********	PATH FINDING - START	*******************
		//				if (should_use_pf && can_use_pf)
		//				{
		//					debug("Finding path");
		//					pf_lock();
		//					point destination = command_destination;
		//					motion_command_reset();
		//					giveUp = !pf_search(state.position, destination, current_motion_instruction.get_pf_positions());
		//					pf_unlock();
		//					debug("Path found");
		//					if (!giveUp)
		//					{
		//						debug("Moving to next pf point");
		//						current_motion_instruction.move_to_next_pf_point();
		//					}
		//				}
		//***********	PATH FINDING - END	*******************
						if (giveUp)
						{
							debug("Sending error, timeout, enemy detected");
							motion_command_reset();
							hard_stop();
						}
					}
				}
				else
				{
					debug("Pausing motion - enemy detected");
					motion_command_pause();
				}
			}
			else if (motion_command_suspended)
			{
				debug("Resuming motion");
				current_motion_resume();
			}
		} // if (current_motion_command_set)
		else
		{
			if (osMutexWait(motion_mutex, MAX_MOTION_QUEUE_LENGTH) == osOK)
			{
				if (motion_queue[0] == NULL)
				{
					debug("No commands in motion queue");
				}
				else
				{
					debug("Grabbing new command from queue");
					process_motion_command();
				}
			}
			else
			{
				error("MOTION CAN'T GET MUTEX");
			}
		}
		if ((state.status == MOTION_IDLE || state.status == MOTION_STUCK || state.status == MOTION_ERROR) && current_motion_command_set)
		{
			if (state.status == MOTION_IDLE)
			{
				info("Done executin command");
				current_motion_command_set = 0;
			}
			else if (state.status == MOTION_STUCK)
			{
				error("STUCK");
				motion_command_reset();
				hard_stop();
			}
			else if (state.status == MOTION_ERROR)
			{
				error("Error - canceling motion");
				motion_command_reset();
				hard_stop();
			}
		}
		osDelay(6);
	} // while(1)
}

static void current_motion_resume(void)
{
	debug("current_motion_resume");
	current_destination = previous_destination;
	goto_xy_cmd(current_destination.x, current_destination.y, direction, can_use_pf);
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
}

static uint8_t enemy_detected(motion_state state)
{
	debug("enemy_detected");
	if (state.status == MOTION_ROTATING)
		return 0;
	if ((direction == FORWARD && !(FRONT_LEFT_SENSOR ||
                                   FRONT_RIGHT_SENSOR)) ||
		(direction == BACKWARD && !BACK_SENSOR))
		return 0;
	point_t enemy;
	enemy.x = state.x + CENTER_TO_CENTER * cos(to_radian(state.orientation));
	enemy.y = state.y + CENTER_TO_CENTER * sin(to_radian(state.orientation));;
	if (is_in_field(enemy))
		return 1;
	return 0;
}

void motion_queue_push(void* command)
{
	if (commands_in_queue >= MAX_MOTION_QUEUE_LENGTH)
	{
		error("Motion queue already full.\n"
		"Currently in queue: %d", commands_in_queue);
	}
	else
	{
		if (osMutexWait(motion_mutex, MAX_MOTION_QUEUE_LENGTH) == osOK)
		{
			motion_queue[commands_in_queue] = command;
			commands_in_queue++;
		}
		else
		{
			error("MOTION CAN'T GET MUTEX");
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
		if (osMutexWait(motion_mutex, MAX_MOTION_QUEUE_LENGTH) == osOK)
		{
			command = motion_queue[0];
			memmove(motion_queue, motion_queue + 1, commands_in_queue - 1);
			commands_in_queue--;
			motion_queue[commands_in_queue] = NULL;
		}
		else
		{
			error("MOTION CAN'T GET MUTEX");
		}
	}
	return command;
}

uint8_t can_retry(void)
{
	static uint8_t retry_count;
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
	if (enemy.x > 0 && enemy.x < 2000 && enemy.y > 0 && enemy.y < 3000)
	{
		if (enemy.x > 0 && enemy.x < 350 &&
			((enemy.y > 0 && enemy.y < 1050) ||
			 (enemy.y > 1950 && enemy.y < 3000)))
		{
			debug("Detected enemy is in start field");
			return 0;
		}
		else
		{
			debug("Detencted enemy is in allower area");
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
	void* cmd_temp = motion_queue_pull();
	motion_cmd_id_t id = * (motion_cmd_id_t*) cmd_temp;
	switch (id)
	{
		case SET_XY:
			{
				struct set_xy_cmd_struct* cmd = (struct set_xy_cmd_struct*)cmd_temp;
				set_position_and_orientation(cmd->x, cmd->y, cmd->orientation);
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
				break;
			}
		case ROTATE_FOR:
			{
				struct rotate_for_cmd_struct* cmd = cmd_temp;
				current_motion_command_set = 1;
				can_use_pf = 0;
				current_destination.x = state.x;
				current_destination.y = state.y;
				rotate_for(cmd->angle);
				break;
			}
		case ROTATE_TO:
			{
				struct rotate_to_cmd_struct* cmd = cmd_temp;
				current_motion_command_set = 1;
				can_use_pf = 0;
				current_destination.x = state.x;
				current_destination.y = state.y;
				rotate_to(cmd->angle);
				break;
			}
		case GOTO_XY:
			{
				struct goto_xy_cmd_struct* cmd = cmd_temp;
				current_motion_command_set = 1;
				can_use_pf = cmd->use_pf;
				current_destination.x = cmd->x;
				current_destination.y = cmd->y;
				direction = cmd->direction? FORWARD : BACKWARD;
				goto_xy(cmd->x, cmd->y, cmd->direction);
				break;
			}
		case CURVE:
			{
				struct curve_cmd_struct* cmd = cmd_temp;
				current_motion_command_set = 1;
				can_use_pf = 0;
				current_destination = calculate_curve_destination(cmd);
				direction = cmd->direction;
				curve(cmd->x, cmd->y, cmd->angle, cmd->angle_direction, cmd->direction);
				break;
			}
		case HARD_STOP:
			{
				//struct hard_stop_cmd_struct* cmd = cmd_temp;
				hard_stop();
				break;
			}
		case SOFT_STOP:
			{
				//struct soft_stop_cmd_struct* cmd = cmd_temp;
				soft_stop();
				break;
			}
		case RESET_DRIVER:
			{
				//struct reset_driver_cmd_struct* cmd = cmd_temp;
				reset_driver();
				break;
			}
		case STUCK_ENABLE:
			{
				//struct stuck_enable_cmd_struct* cmd = cmd_temp;
				stuck_enable();
				break;
			}
		case STUCK_DISABLE:
			{
				//struct stuck_disable_cmd_struct* cmd = cmd_temp;
				stuck_disable();
				break;
			}
		case SET_SPEED:
			{
				struct set_motion_speed_cmd_struct* cmd = cmd_temp;
				set_motion_speed(cmd->speed);
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
