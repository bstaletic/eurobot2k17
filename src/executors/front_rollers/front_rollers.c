#include "front_rollers.h"

void rollers_off(void)
{
    dc_motor_switch_off();
}

void rollers_reverse(void)
{
    dc_motor_direction(DC_REVERSE);
}

void rollers_forward(void)
{
    dc_motor_direction(DC_FORWARD);
}
