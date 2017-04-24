#include "dc_motor.h"

void dc_motor_switch_off(void)
{
	mosfet_set(DC_MOSFET_ID1);
	mosfet_set(DC_MOSFET_ID2);

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
