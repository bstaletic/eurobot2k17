#include "motion_command.h"

void set_xy_cmd(int16_t x, int16_t y, int16_t orientation)
{
	struct set_xy_cmd_struct command_struct;
	command_struct.id = SET_XY;
	command_struct.x = x;
	command_struct.y = y;
	command_struct.orientation = orientation;
	motion_queue_push(&command_struct);
}

void read_status_cmd(void)
{
	struct read_status_cmd_struct command_struct;
	command_struct.id = READ_STATUS;
	motion_queue_push(&command_struct);
}

void move_forward_cmd(int16_t dist)
{
	struct move_forward_cmd_struct command_struct;
	command_struct.id = MOVE_FORWARD;
	command_struct.dist = dist;
	motion_queue_push(&command_struct);
}

void rotate_for_cmd(int16_t angle)
{
	struct rotate_for_cmd_struct command_struct;
	command_struct.id = ROTATE_FOR;
	command_struct.angle = angle;
	motion_queue_push(&command_struct);
}

void rotate_to_cmd(int16_t angle)
{
	struct rotate_for_cmd_struct command_struct;
	command_struct.id = ROTATE_TO;
	command_struct.angle = angle;
	motion_queue_push(&command_struct);
}

void goto_xy_cmd(int16_t x, int16_t y, int8_t direction, uint8_t use_pf)
{
	struct goto_xy_cmd_struct command_struct;
	command_struct.id = GOTO_XY;
	command_struct.x = x;
	command_struct.y = y;
	command_struct.direction = direction;
	command_struct.use_pf = use_pf;
	motion_queue_push(&command_struct);
}

void curve_cmd(int16_t x, int16_t y, int8_t angle, int8_t angle_direction,
		int8_t direction)
{
	struct curve_cmd_struct command_struct;
	command_struct.id = CURVE;
	command_struct.x = x;
	command_struct.y = y;
	command_struct.angle = angle;
	command_struct.angle_direction = angle_direction;
	command_struct.direction = direction;
	motion_queue_push(&command_struct);
}

void hard_stop_cmd(void)
{
	struct hard_stop_cmd_struct command_struct;
	command_struct.id = HARD_STOP;
	motion_queue_push(&command_struct);
}

void soft_stop_cmd(void)
{
	struct soft_stop_cmd_struct command_struct;
	command_struct.id = HARD_STOP;
	motion_queue_push(&command_struct);
}

void reset_driver_cmd(void)
{
	struct reset_driver_cmd_struct command_struct;
	command_struct.id = HARD_STOP;
	motion_queue_push(&command_struct);
}

void stuck_enable_cmd(void)
{
	struct stuck_enable_cmd_struct command_struct;
	command_struct.id = HARD_STOP;
	motion_queue_push(&command_struct);
}

void stuck_disable_cmd(void)
{
	struct stuck_disable_cmd_struct command_struct;
	command_struct.id = HARD_STOP;
	motion_queue_push(&command_struct);
}

void set_motion_speed_cmd(uint8_t speed)
{
	struct set_motion_speed_cmd_struct command_struct;
	command_struct.id = SET_SPEED;
	command_struct.speed = speed;
	motion_queue_push(&command_struct);
}
