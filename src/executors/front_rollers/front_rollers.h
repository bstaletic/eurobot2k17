#ifndef FRONT_ROLLERS_EXECUTOR
#define FRONT_ROLLERS_EXECUTOR

#define ROLLERS_ON 1
#define ROLLERS_OFF 0

#include "../../drivers/actuators/dc_motor/dc_motor.h"

dc_direction ROLLERS_INWARDS = DC_INWARDS;
dc_direction ROLLERS_OUTWARDS = DC_OUTWARDS;

void rollers_on(void);
void rollers_off(void);

void rollers_inwards(void);
void rollers_outwards(void);

#endif /* ifndef FRONT_ROLLERS_EXECUTOR */
