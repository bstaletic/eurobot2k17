#include "motion.h"

volatile int16_t x_coordinate;
volatile int16_t y_coordinate;
volatile int16_t orientation;
volatile char status = MOTION_IDLE;
volatile motion_state state;
volatile uint8_t state_refresh_needed;

void set_position_and_orientation(int16_t x, int16_t y, int16_t orientation)
{
	uint8_t out_data[7];

	// Build data
	out_data[0] = 'I';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = orientation>>8;
	out_data[6] = orientation&0xff;

	// Send to motion driver
	HAL_UART_Transmit(MOTION_DRIVER, out_data, 7, 14);
}

void read_status_and_position(void)
{
	uint8_t new_state[7];

	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"P", 1, 2);

	HAL_UART_Receive(MOTION_DRIVER, new_state, 7, 14);

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
	uint8_t out_data[2];

	out_data[0] = 'V';
	out_data[1] = speed;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 2, 4);
}

void move_forward(int16_t dist)
{
	uint8_t out_data[4];

	out_data[0] = 'D';
	out_data[1] = dist>>8;
	out_data[2] = dist&0xff;
	out_data[3] = 0;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 4, 8);
}

void rotate_for(int16_t angle)
{
	uint8_t out_data[3];

	out_data[0] = 'T';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 3, 6);
}

void rotate_to(int16_t angle)
{
	uint8_t out_data[3];

	out_data[0] = 'A';
	out_data[1] = angle>>8;
	out_data[2] = angle&0xff;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 3, 6);
}

void goto_xy(int16_t x, int16_t y, int8_t direction)
{
	uint8_t out_data[7];

	out_data[0] = 'G';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = 0;
	out_data[6] = direction;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 7, 14);
}

void curve(int16_t x, int16_t y, int8_t angle, int8_t angle_direction, int8_t direction)
{
	uint8_t out_data[8];

	out_data[0] = 'Q';
	out_data[1] = x>>8;
	out_data[2] = x&0xff;
	out_data[3] = y>>8;
	out_data[4] = y&0xff;
	out_data[5] = angle;
	out_data[6] = angle_direction;
	out_data[7] = direction;

	HAL_UART_Transmit(MOTION_DRIVER, out_data, 8, 16);
}

void hard_stop(void)
{
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"S", 1, 2);
}

void soft_stop(void)
{
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"s", 1, 2);
}

void reset_driver(void)
{
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"R", 1, 2);
}

void stuck_enable(void)
{
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"Z", 1, 2);
}

void stuck_disable(void)
{
	HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"z", 1, 2);
}

/**
* @brief This function handles TIM7 global interrupt.
*/
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */
//	uint8_t temp[7];
  	if (__HAL_TIM_GET_FLAG(&htim7, TIM_FLAG_UPDATE) != RESET) {

//  			HAL_UART_Transmit(MOTION_DRIVER, (unsigned char *)"P", 1, 1);
//			HAL_UART_Receive(MOTION_DRIVER, temp, 7, 1);
//			switch (temp[0])
//			{
//				case 'I':
//					state.status = MOTION_IDLE;
//					break;
//				case 'M':
//					state.status = MOTION_MOVING;
//					break;
//				case 'R':
//					state.status = MOTION_ROTATING;
//					break;
//				case 'S':
//					state.status = MOTION_STUCK;
//					break;
//				case 'E':
//					state.status = MOTION_ERROR;
//					break;
//
//			}
//  			state.x = (temp[1] << 8 ) | (temp[2] & 0xff);
//  			state.y = (temp[3] << 8 ) | (temp[4] & 0xff);
//  			state.orientation = (temp[5] << 8) | (temp[6] & 0xff);
//  			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
			state_refresh_needed = 1;
  			/* Clear overflow interrupt flag. */
  			__HAL_TIM_CLEAR_IT(&htim7, TIM_IT_UPDATE);
  	}

  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

  /* USER CODE END TIM7_IRQn 1 */
}
