#include "dc_motor.h"

void dc_motor_move(int16_t speed)
{
	timer_set_oc_value(DC_TIMER, DC_CHANNEL, speed);
}

void dc_motor_direction(int8_t direction)
{
	if (direction)
		gpio_set(DC_GPIO, DC_PIN);
	else
		gpio_reset(DC_GPIO, DC_PIN);
}
