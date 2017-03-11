#include "motion.h"


void set_position_and_orientation(int16_t x, int16_t y, int16_t orientation)
{
	int8_t out_data[7];

	// Build data
	out_data[0] = 'I';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = orientation>>8;
	out_data[6] = orientation&0xff;

	// Send to motion driver
	TM_USART_Send(UART4, out_data, 7);
}

void read_status_and_position(void)
{
	int8_t new_state[7];

	TM_USART_Putc(MOTION_DRIVER, 'P');

	for (int8_t i = 0; i < 7; ++i)
		new_state[i] = TM_USART_Getc(MOTION_DRIVER);

	switch (new_state[0])
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

	state.x           = new_state[1]<<8 | new_state[2];
	state.y           = new_state[3]<<8 | new_state[4];
	state.orientation = new_state[5]<<8 | new_state[6];

}

void set_motion_speed(int8_t speed)
{
	int8_t out_data[2];

	out_data[0] = 'V';
	out_data[1] = speed;

	TM_USART_Send(UART4, out_data, 2);
}

void move_forward(int16_t dist, int8_t end_speed)
{
	int8_t out_data[4];

	out_data[0] = 'D';
	out_data[1] = dist>>8;
	out_data[2] = dist&0xff;
	out_data[3] = end_speed;

	TM_USART_Send(UART4, out_data, 4);
}

void rotate_for(int16_t angle)
{
	int8_t out_data[3];

	out_data[0] = 'T';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	TM_USART_Send(UART4, out_data, 3);
}

void rotate_to(int16_t angle)
{
	int8_t out_data[3];

	out_data[0] = 'A';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	TM_USART_Send(UART4, out_data, 3);
}

void goto_xy(int16_t x, int16_t y, int8_t end_speed, int8_t direction)
{
	int8_t out_data[7];

	out_data[0] = 'G';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = end_speed;
	out_data[6] = direction;

	TM_USART_Send(UART4, out_data, 7);
}

void curve(int16_t x, int16_t y, int8_t angle, int8_t angle_direction, int8_t direction)
{
	int8_t out_data[8];

	out_data[0] = 'Q';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = angle;
	out_data[6] = angle_direction;
	out_data[7] = direction;

	TM_USART_Send(UART4, out_data, 8);
}

void hard_stop(void)
{
	TM_USART_Putc(MOTION_DRIVER, 'S');
}

void soft_stop(void)
{
	TM_USART_Putc(MOTION_DRIVER, 's');
}

void reset_driver(void)
{
	TM_USART_Putc(MOTION_DRIVER, 'R');
}

void stuck_enable(void)
{
	TM_USART_Putc(MOTION_DRIVER, 'Z');
}

void stuck_disable(void)
{
	TM_USART_Putc(MOTION_DRIVER, 'z');
}
