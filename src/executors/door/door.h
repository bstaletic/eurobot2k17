#ifndef DOOR_EXECUTOR
#define DOOR_EXECUTOR

#include "../drivers/actuators/ax12/ax12.h"

///servos to "poke" lunar module and get it off the revolver
#define SERVO_TOP 5
#define SERVO_FRONT 6
#define POKE_INIT_POSITION 1000
#define POKE_MODULE_POSITION_TOP 2000
#define POKE_MODULE_POSITION_FRONT 2000


void door_close(void);
void door_open(void);

void poke_init(void);
void poke_module(uint8_t servo_id);

#endif /* ifndef DOOR_EXECUTOR */
