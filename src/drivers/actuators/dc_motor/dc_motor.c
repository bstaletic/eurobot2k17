#include "dc_motor.h"

void dc_motor_switch(int8_t power)
{
	if (power)
		timer_set_oc_value(DC_TIMER, DC_CHANNEL, DC_PWM);
	else
		timer_set_oc_value(DC_TIMER, DC_CHANNEL, 0);
}

void dc_motor_direction(dc_direction direction)
{
	if (direction == DC_FORWARD)
	{

		mosfet_set(DC_MOSFET_ID1);
		mosfet_clear(DC_MOSFET_ID2);

	}
	else
	{

		mosfet_clear(DC_MOSFET_ID1);
		mosfet_set(DC_MOSFET_ID2);

	}
}
