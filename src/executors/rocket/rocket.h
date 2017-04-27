#ifndef ROCKET_EXECUTOR
#define ROCKET_EXECUTOR

#define SERVO_ROCKET 4
#define ROCKET_INIT_POSITION 450
#define ROCKET_LAUNCH_POSITION 200


#include "../drivers/actuators/ax12/ax12.h"

void rocket_init(void);

void rocket_launch(void);

#endif /* ifndef ROCKET_EXECUTOR */
