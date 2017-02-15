#include "colour.h"

static uint32_t read_colour_channel(colour_channel_enum_t channel);

colour_enum_t read_colour(void)
{
	colour_enum_t colour;
	uint32_t colour_channel_red_frequency;
	uint32_t colour_channel_green_frequency;
	uint32_t colour_channel_blue_frequency;
	colour_channel_red_frequency = read_colour_channel(RED_CHANNEL);
	colour_channel_green_frequency = read_colour_channel(GREEN_CHANNEL);
	colour_channel_blue_frequency = read_colour_channel(BLUE_CHANNEL);
	if (colour_channel_red_frequency >= RED_CHANNEL_WHITE_RANGE_START &&
		colour_channel_red_frequency <= RED_CHANNEL_WHITE_RANGE_END &&
		colour_channel_blue_frequency >= BLUE_CHANNEL_WHITE_RANGE_START &&
		colour_channel_blue_frequency <= BLUE_CHANNEL_WHITE_RANGE_END &&
		colour_channel_green_frequency >= GREEN_CHANNEL_WHITE_RANGE_START &&
		colour_channel_green_frequency <= GREEN_CHANNEL_WHITE_RANGE_END)
		colour = WHITE;
	else if (colour_channel_red_frequency >= RED_CHANNEL_YELLOW_RANGE_START &&
		colour_channel_red_frequency <= RED_CHANNEL_YELLOW_RANGE_END &&
		colour_channel_blue_frequency >= BLUE_CHANNEL_YELLOW_RANGE_START &&
		colour_channel_blue_frequency <= BLUE_CHANNEL_YELLOW_RANGE_END &&
		colour_channel_green_frequency >= GREEN_CHANNEL_YELLOW_RANGE_START &&
		colour_channel_green_frequency <= GREEN_CHANNEL_YELLOW_RANGE_END)
		colour = YELLOW;
	else if (colour_channel_red_frequency >= RED_CHANNEL_BLUE_RANGE_START &&
		colour_channel_red_frequency <= RED_CHANNEL_BLUE_RANGE_END &&
		colour_channel_blue_frequency >= BLUE_CHANNEL_BLUE_RANGE_START &&
		colour_channel_blue_frequency <= BLUE_CHANNEL_BLUE_RANGE_END &&
		colour_channel_green_frequency >= GREEN_CHANNEL_BLUE_RANGE_START &&
		colour_channel_green_frequency <= GREEN_CHANNEL_BLUE_RANGE_END)
		colour = BLUE;
	else
		colour = UNKNOWN;

	return colour;
}

// This should reenable TIM6 interrupt when called, read the frequency and then
// disable the interrupt again
static uint32_t read_colour_channel(colour_channel_enum_t channel)
{
	uint32_t channel_frequency_value;
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
	}
	// Enable TIM6 interrupt
	nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
	timer_enable_irq(TIM6, TIM_DIER_UIE);

	// Wait for sensor to read
	while (!colour_sensor_value_ready);

	channel_frequency_value = colour_sensor_frequency;

	// Disable TIM6 interrupt
	nvic_disable_irq(NVIC_TIM6_DAC_IRQ);
	timer_disable_irq(TIM6, TIM_DIER_UIE);

	return channel_frequency_value;
}
