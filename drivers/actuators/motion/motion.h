#ifndef MOTION
#define MOTION

#include <libopencm3/stm32/usart.h>

#define MOTION_DRIVER USART3

void set_position_and_orientation(int16_t  x, int16_t y, int16_t o);
void read_status_and_position(void);
void move_forward(int16_t dist, int8_t end_position);
void rotate_for(int16_t angle);
void rotate_to(int16_t angle);
void goto_xy(int16_t x, int16_t y, int8_t end_speed, int8_t direction);
void curve(int16_t x, int16_t y, int8_t angle,
		int8_t angle_direction, int8_t direction);
void hard_stop(void);
void soft_stop(void);
void reset_driver(void);
void stuck_enable(void);
void stuck_disable(void);
void read_state(void);

enum status { IDLE, MOVING, ROTATING, STUCK, ERROR };

typedef struct state {
	int16_t x = 0;
	int16_t y = 0;
	int16_t orientation = 0;
	enum status status = IDLE;
} motion_state_t;

motion_state_t driver_state;

#endif /* ifndef MOTION */
