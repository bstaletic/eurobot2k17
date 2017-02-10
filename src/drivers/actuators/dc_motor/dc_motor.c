#include "dc_motor.h"

void dc_motor_on(int8_t power_on)
{
	if (power_on)
		timer_set_oc_value(DC_TIMER, DC_CHANNEL, DC_PWM);
	else
		timer_set_oc_value(DC_TIMER, DC_CHANNEL, 0);
}

void dc_motor_direction(dc_direction direction)
{
	if (direction == DC_INWARDS)
		mosfet_set(DC_MOSFET_ID);
	else
		mosfet_clear(DC_MOSFET_ID);
}
