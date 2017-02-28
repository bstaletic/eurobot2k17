#include "colour.h"

volatile uint32_t colour_sensor_red_value, colour_sensor_green_value, colour_sensor_blue_value;
volatile uint8_t colour_sensor_step = 0, colour_sensor_value_ready = 0;

static void set_channel(colour_channel_enum_t channel);

// TIM6 interrupt - should fire every millisecond
// and read the colour sensor
// There's probably better way of doing this (best kind of comments, btw)

void tim6_dac_isr(void)
{
	if (timer_get_flag(TIM6, TIM_SR_UIF)) {
		/* Clear overflow interrupt flag. */
		timer_clear_flag(TIM6, TIM_SR_UIF);
		/* Read counter and treat it as kHz value */

		switch(colour_sensor_step){

			case 0:
				timer_set_counter(COLOUR_SENSOR_TIMER, 0);
				set_channel(RED_CHANNEL);
				colour_sensor_step++;
				break;

			case 1:
				colour_sensor_red_value=timer_get_counter(COLOUR_SENSOR_TIMER);
				timer_set_counter(COLOUR_SENSOR_TIMER, 0);
				set_channel(GREEN_CHANNEL);
				colour_sensor_step++;
				break;

			case 2:
				colour_sensor_green_value=timer_get_counter(COLOUR_SENSOR_TIMER);
				timer_set_counter(COLOUR_SENSOR_TIMER, 0);
				set_channel(BLUE_CHANNEL);
				colour_sensor_step++;
				break;

			case 3:
				colour_sensor_blue_value=timer_get_counter(COLOUR_SENSOR_TIMER);
				colour_sensor_step=0;
				colour_sensor_value_ready=1;
				break;

		}
	}
}

colour_enum_t read_colour(void)
{
	colour_enum_t colour;

	// Enable TIM6 interrupt
	colour_sensor_value_ready=0;

	nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
	timer_enable_irq(TIM6, TIM_DIER_UIE);

	while(!colour_sensor_value_ready);

	// Disable TIM6 interrupt
	nvic_disable_irq(NVIC_TIM6_DAC_IRQ);
	timer_disable_irq(TIM6, TIM_DIER_UIE);

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
