#ifndef ANALOG_SERVO
#define ANALOG_SERVO

#include <initialisation/tim.h>

typedef struct {
	uint32_t timer;
	uint32_t channel;
} analog_servo;

//const analog_servo servo1, servo2, servo4, servo5, servo6, servo7, servo8;

/**
 * \fn void analog_servo_move(analog_servo as, int16_t angle)
 * \brief Rotate analog servo to desired position
 */
void analog_servo_move(analog_servo as, int16_t angle);

#endif /* ifndef ANALOG_SERVO */
