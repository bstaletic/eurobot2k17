#include "colour.h"

colour_enum_t read_colour(void)
{
	//enable interrupt
	nvic_enable_irq(NVIC_TIM6_DAC_IRQ);
	timer_enable_irq(TIM6, TIM_DIER_UIE);

	// Wait for sensor to read
	while (!colour_sensor_counter_value_ready);
	colour_enum_t colour;
	if (colour_sensor_frequency >= WHITE_RANGE_START &&
             colour_sensor_frequency <= WHITE_RANGE_END)
		colour = WHITE;
	else if (colour_sensor_frequency >= WHITE_RANGE_START &&
             colour_sensor_frequency <= WHITE_RANGE_END)
		colour = YELLOW;
	else if (colour_sensor_frequency >= BLUE_RANGE_START &&
             colour_sensor_frequency <= BLUE_RANGE_END)
		colour = BLUE;
	else
		colour = UNKNOWN;

	// Disable interrupt
	nvic_disable_irq(NVIC_TIM6_DAC_IRQ);
	timer_disable_irq(TIM6, TIM_DIER_UIE);

	return colour;
}
