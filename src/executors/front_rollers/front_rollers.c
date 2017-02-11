#include "front_rollers.h"

void rollers_on(void)
{
    dc_motor_on(ROLLERS_ON);
}

void rollers_off(void)
{
    dc_motor_on(ROLLERS_OFF);
}

void rollers_inwards(void)
{
    dc_motor_direction(ROLLERS_INWARDS);
}

void rollers_outwards(void)
{
    dc_motor_direction(ROLLERS_OUTWARDS);
}
