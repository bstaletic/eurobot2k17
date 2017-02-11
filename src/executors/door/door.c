#include "door.h"

void door_close(void)
{
    analog_servo_move(SERVO_DOOR, DOOR_CLOSED_POSITION);
}

void door_open(void)
{
    analog_servo_move(SERVO_DOOR, DOOR_OPEN_POSITION);
}

void poke_init(void)
{
    analog_servo_move(SERVO_POKE, POKE_INIT_POSITION);
}

void poke_module(void)
{
    analog_servo_move(SERVO_POKE, POKE_MODULE_POSITION);
}
