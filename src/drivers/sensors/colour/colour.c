#include "colour.h"

extern TIM_HandleTypeDef htim6;

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
