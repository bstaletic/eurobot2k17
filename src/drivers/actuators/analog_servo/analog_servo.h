#ifndef ANALOG_SERVO
#define ANALOG_SERVO

#include <tim.h>

#include "../utils/timer_utils.h"

typedef struct {
	uint8_t timer;
	uint32_t channel;
} analog_servo;

const analog_servo servo8;

/**
 * \fn void analog_servo_move(analog_servo as, int16_t angle)
 * \brief Rotate analog servo to desired position
 */
void analog_servo_move(analog_servo as, int16_t angle);

#endif /* ifndef ANALOG_SERVO */
