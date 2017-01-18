#ifndef ANALOG_SERVO
#define ANALOG_SERVO

#include <initialisation/timer_config.h>

typedef struct {
	uint16_t timer;
	uint16_t channel;
} analog_servo;

/**
 * \fn void analog_servo_move(analog_servo as, int16_t angle)
 * \brief Rotate analog servo to desired position
 */
void analog_servo_move(analog_servo as, int16_t angle);

#endif /* ifndef ANALOG_SERVO */
