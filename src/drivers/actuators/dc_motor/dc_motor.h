#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <stdint.h>
#include "../../../initialisation/timer_config.h"
#include "../mosfet_switches/mosfet_switches.h"

#define DC_TIMER TIM2
#define DC_CHANNEL TIM_OC1

/* Maximum PWM for DC motor 800 */
#define DC_PWM 800

#define DC_ON 1
#define DC_OFF 0

#define DC_MOSFET_ID1 1
#define DC_MOSFET_ID2 2

typedef enum { DC_FORWARD, DC_REVERSE } dc_direction;

/**
 * \fn void dc_motor_move(dc_motor dc, int16_t speed);
 * \brief Set dc motor speed
 */
void dc_motor_move(int16_t speed);

/**
 * \fn void dc_motor_direction(dc_motor dc, int8_t direction);
 * \brief Set dc motor direction
 */
void dc_motor_direction(dc_direction direction);

#endif /* ifndef DC_MOTOR_H */
