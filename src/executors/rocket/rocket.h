#ifndef ROCKET_EXECUTOR
#define ROCKET_EXECUTOR

#define SERVO_ROCKET servo8
#define ROCKET_INIT_POSITION 1000
#define ROCKET_LAUNCH_POSITION 2000


#include "../drivers/actuators/analog_servo/analog_servo.h"

void rocket_init(void);

void rocket_launch(void);

#endif /* ifndef ROCKET_EXECUTOR */
