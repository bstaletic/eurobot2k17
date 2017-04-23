#ifndef MOTION_COMMAND_H
#define MOTION_COMMAND_H

#include <stdint.h>
#include <stdlib.h>

#include "cmsis_os.h"
#include "usart.h"
#include "../executors/motion/motion.h"

typedef enum {
	SET_XY,
	READ_STATUS,
	MOVE_FORWARD,
	ROTATE_FOR,
	ROTATE_TO,
	GOTO_XY,
	CURVE,
	HARD_STOP,
	SOFT_STOP,
	RESET_DRIVER,
	STUCK_ENABLE,
	STUCK_DISABLE,
	SET_SPEED
} motion_cmd_id_t;

struct set_xy_cmd_struct {
	motion_cmd_id_t id;
	int16_t x;
	int16_t y;
	int16_t orientation;
};

struct read_status_cmd_struct
{
	motion_cmd_id_t id;
};

struct move_forward_cmd_struct
{
	motion_cmd_id_t id;
	int16_t dist;
};

struct rotate_for_cmd_struct
{
	motion_cmd_id_t id;
	int16_t angle;
};

struct rotate_to_cmd_struct
{
	motion_cmd_id_t id;
	int16_t angle;
};

struct goto_xy_cmd_struct
{
	motion_cmd_id_t id;
	int16_t x;
	int16_t y;
	int16_t direction;
	int8_t use_pf;
};

struct curve_cmd_struct
{
	motion_cmd_id_t id;
	int16_t x;
	int16_t y;
	int8_t angle;
	int8_t angle_direction;
	int8_t direction;
};

struct hard_stop_cmd_struct
{
	motion_cmd_id_t id;
};

struct soft_stop_cmd_struct
{
	motion_cmd_id_t id;
};

struct reset_driver_cmd_struct
{
	motion_cmd_id_t id;
};

struct stuck_enable_cmd_struct
{
	motion_cmd_id_t id;
};

struct stuck_disable_cmd_struct
{
	motion_cmd_id_t id;
};

struct set_motion_speed_cmd_struct
{
	motion_cmd_id_t id;
	uint8_t speed;
};

void set_xy_cmd(int16_t x, int16_t y, int16_t orientation);
void read_status_cmd(void);
void move_forward_cmd(int16_t dist);
void rotate_for_cmd(int16_t angle);
void rotate_to_cmd(int16_t angle);
void goto_xy_cmd(int16_t x, int16_t y, int8_t direction, uint8_t use_pf);
void curve_cmd(int16_t x, int16_t y, int8_t angle,
		int8_t angle_direction, int8_t direction);
void hard_stop_cmd(void);
void soft_stop_cmd(void);
void reset_driver_cmd(void);
void stuck_enable_cmd(void);
void stuck_disable_cmd(void);
void set_motion_speed_cmd(uint8_t speed);

#endif /* ifndef MOTION_COMMAND_H */
