#include "analog_servo.h"

const analog_servo servo8={1, TIM_CHANNEL_1};

void analog_servo_move(analog_servo as, int16_t angle)
{
	set_pwm(as.timer, as.channel, angle);
}
