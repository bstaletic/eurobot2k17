#include "colour.h"

volatile uint32_t colour_sensor_red_value, colour_sensor_green_value, colour_sensor_blue_value;
volatile uint8_t colour_sensor_step = 0, colour_sensor_value_ready = 0;
static void set_channel(colour_channel_enum_t channel);

colour_enum_t read_colour(void)
{
	colour_enum_t colour;

	// Enable TIM6 interrupt
	colour_sensor_value_ready = 0;

	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	HAL_TIM_Base_Start_IT(&htim6);
	while(!colour_sensor_value_ready);

	// Disable TIM6 interrupt
	HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
	HAL_TIM_Base_Stop_IT(&htim6);

	if (colour_sensor_red_value >= RED_CHANNEL_WHITE_RANGE_START &&
		colour_sensor_red_value <= RED_CHANNEL_WHITE_RANGE_END &&
		colour_sensor_blue_value >= BLUE_CHANNEL_WHITE_RANGE_START &&
		colour_sensor_blue_value <= BLUE_CHANNEL_WHITE_RANGE_END &&
		colour_sensor_green_value >= GREEN_CHANNEL_WHITE_RANGE_START &&
		colour_sensor_green_value <= GREEN_CHANNEL_WHITE_RANGE_END)
		colour = WHITE;
	else if (colour_sensor_red_value >= RED_CHANNEL_YELLOW_RANGE_START &&
		colour_sensor_red_value <= RED_CHANNEL_YELLOW_RANGE_END &&
		colour_sensor_blue_value >= BLUE_CHANNEL_YELLOW_RANGE_START &&
		colour_sensor_blue_value <= BLUE_CHANNEL_YELLOW_RANGE_END &&
		colour_sensor_green_value >= GREEN_CHANNEL_YELLOW_RANGE_START &&
		colour_sensor_green_value <= GREEN_CHANNEL_YELLOW_RANGE_END)
		colour = YELLOW;
	else if (colour_sensor_red_value >= RED_CHANNEL_BLUE_RANGE_START &&
		colour_sensor_red_value <= RED_CHANNEL_BLUE_RANGE_END &&
		colour_sensor_blue_value >= BLUE_CHANNEL_BLUE_RANGE_START &&
		colour_sensor_blue_value <= BLUE_CHANNEL_BLUE_RANGE_END &&
		colour_sensor_green_value >= GREEN_CHANNEL_BLUE_RANGE_START &&
		colour_sensor_green_value <= GREEN_CHANNEL_BLUE_RANGE_END)
		colour = BLUE;
	else
		colour = UNKNOWN;


	return colour;
}

/**
 * @brief This function handles TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts.
 * TIM6 interrupt - should fire every millisecond and read the colour sensor
 */
void TIM6_DAC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_DAC_IRQn 0 */
 	if (__HAL_TIM_GET_FLAG(&htim6, TIM_FLAG_UPDATE) != RESET) {
 		/* Clear overflow interrupt flag. */
 		__HAL_TIM_CLEAR_IT(&htim6, TIM_IT_UPDATE);
 		/* Read counter and treat it as kHz value */

  		switch(colour_sensor_step) {

  			case 0:
  				__HAL_TIM_SetCounter(&htim6, 0);
  				set_channel(RED_CHANNEL);
  				colour_sensor_step++;
  				break;

  			case 1:
  				colour_sensor_red_value  =  __HAL_TIM_GET_COUNTER(&htim6);
  				__HAL_TIM_SetCounter(&htim6, 0);
  				set_channel(GREEN_CHANNEL);
  				colour_sensor_step++;
  				break;

  			case 2:
  				colour_sensor_green_value = __HAL_TIM_GET_COUNTER(&htim6);
  				__HAL_TIM_SetCounter(&htim6, 0);
  				set_channel(BLUE_CHANNEL);
  				colour_sensor_step++;
  				break;

  			case 3:
  				colour_sensor_blue_value = __HAL_TIM_GET_COUNTER(&htim6);
  				colour_sensor_step = 0;
  				colour_sensor_value_ready = 1;
  				break;

  		}
 	}

  /* USER CODE END TIM6_DAC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_DAC_IRQn 1 */

  /* USER CODE END TIM6_DAC_IRQn 1 */
}

static void set_channel(colour_channel_enum_t channel)
{
	// Set appropriate gpio values
	switch (channel)
	{
		case RED_CHANNEL:
			mosfet_clear(3);
			mosfet_clear(4);
			break;

		case GREEN_CHANNEL:
			mosfet_set(3);
			mosfet_set(4);
			break;

		case BLUE_CHANNEL:
			mosfet_set(3);
			mosfet_clear(4);
			break;
	}

}
