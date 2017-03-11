#ifndef FRONT_ROLLERS_EXECUTOR
#define FRONT_ROLLERS_EXECUTOR

#include "../../drivers/actuators/dc_motor/dc_motor.h"

/// \brief Turns rollers on
void rollers_on(void);
/// \brief Turns rollers off
void rollers_off(void);

/// \brief Makes rollers move tube inside
void rollers_reverse(void);
/// \brief Makes rollers move tube outside
void rollers_forward(void);

#endif /* ifndef FRONT_ROLLERS_EXECUTOR */
