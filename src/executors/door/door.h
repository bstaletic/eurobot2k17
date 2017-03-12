#ifndef DOOR_EXECUTOR
#define DOOR_EXECUTOR

#include "../../drivers/actuators/analog_servo/analog_servo.h"

//one servo to open door
#define SERVO_DOOR servo1
#define DOOR_CLOSED_POSITION 1000
#define DOOR_OPEN_POSITION 2000

//second servo to "poke" lunar module and get it off the revolver
#define SERVO_POKE servo2
#define POKE_INIT_POSITION 1000
#define POKE_MODULE_POSITION 2000

void door_close(void);
void door_open(void);

void poke_init(void);
void poke_module(void);

#endif /* ifndef DOOR_EXECUTOR */
