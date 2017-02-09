#include "dc_motor.h"

void dc_motor_move(int16_t speed)
{
	timer_set_oc_value(DC_TIMER, DC_CHANNEL, speed);
}

void dc_motor_direction(int8_t direction)
{
	if (direction)
		mosfet_set(DC_MOSFET_ID);
	else
		mosfet_clear(DC_MOSFET_ID);
}
