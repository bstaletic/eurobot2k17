#include <drivers/actuators/analog_servo/analog_servo.h>

void analog_servo_move(analog_servo as, int16_t angle)
{
	timer_set_oc_value(as.timer, as.channel, angle);
}
