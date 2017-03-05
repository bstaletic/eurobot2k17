#include "motion.h"

volatile uint16_t x_coordinate;
volatile uint16_t y_coordinate;
volatile uint16_t orientation;
volatile char status;

volatile motion_state state;

void tim7_isr(void)
{

	if (timer_get_flag(TIM7, TIM_SR_UIF)) {

			usart_send_blocking(UART4, 'S');
			state.status = usart_recv_blocking(UART4);
			state.x = (usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);
			state.y = (usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);
			state.orientation = ( usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);

			/* Clear overflow interrupt flag. */
			timer_clear_flag(TIM7, TIM_SR_UIF);

	}

}


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
	for (int8_t i = 0; i < 7; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
}

void read_status_and_position(void)
{
	int8_t new_state[7];

	usart_send_blocking(MOTION_DRIVER, 'P');

	for (int8_t i = 0; i < 7; ++i)
		new_state[i] = usart_recv_blocking(MOTION_DRIVER);

	switch (new_state[0])
	{
		case 'I':
			state.status = IDLE;
			break;
		case 'M':
			state.status = MOVING;
			break;
		case 'R':
			state.status = ROTATING;
			break;
		case 'S':
			state.status = STUCK;
			break;
		case 'E':
			state.status = ERROR;
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

	for (int8_t i = 0; i < 2; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
}

void move_forward(int16_t dist, int8_t end_speed)
{
	int8_t out_data[4];

	out_data[0] = 'D';
	out_data[1] = dist>>8;
	out_data[2] = dist&0xff;
	out_data[3] = end_speed;

	for (int8_t i = 0; i < 4; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
}

void rotate_for(int16_t angle)
{
	int8_t out_data[3];

	out_data[0] = 'T';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	for (int8_t i = 0; i < 3; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
}

void rotate_to(int16_t angle)
{
	int8_t out_data[3];

	out_data[0] = 'A';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	for (int8_t i = 0; i < 3; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
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

	for (int8_t i = 0; i < 7; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
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

	for (int8_t i = 0; i < 8; ++i)
		usart_send_blocking(MOTION_DRIVER, out_data[i]);
}

void hard_stop(void)
{
	usart_send_blocking(MOTION_DRIVER, 'S');
}

void soft_stop(void)
{
	usart_send_blocking(MOTION_DRIVER, 's');
}

void reset_driver(void)
{
	usart_send_blocking(MOTION_DRIVER, 'R');
}

void stuck_enable(void)
{
	usart_send_blocking(MOTION_DRIVER, 'Z');
}

void stuck_disable(void)
{
	usart_send_blocking(MOTION_DRIVER, 'z');
}
