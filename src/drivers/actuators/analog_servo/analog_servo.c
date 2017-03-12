#include "analog_servo.h"

const analog_servo servo1={9, TIM_CHANNEL_2};
const analog_servo servo2={9, TIM_CHANNEL_1};
const analog_servo servo4={4, TIM_CHANNEL_2};
const analog_servo servo5={3, TIM_CHANNEL_2};
const analog_servo servo6={3, TIM_CHANNEL_1};
const analog_servo servo7={2, TIM_CHANNEL_1};
const analog_servo servo8={1, TIM_CHANNEL_1};

void analog_servo_move(analog_servo as, int16_t angle)
{
	set_pwm(as.timer, as.channel, angle);
}
