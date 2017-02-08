#include <drivers/actuators/mosfet_switches/mosfet_switches.h>

const analog_servo servo1={TIM9, TIM_OC2};
const analog_servo servo2={TIM9, TIM_OC1};
const analog_servo servo4={TIM4, TIM_OC2};
const analog_servo servo5={TIM3, TIM_OC2};
const analog_servo servo6={TIM3, TIM_OC1};
const analog_servo servo7={TIM2, TIM_OC1};
const analog_servo servo8={TIM1, TIM_OC1};

void analog_servo_move(analog_servo as, int16_t angle)
{
	timer_set_oc_value(as.timer, as.channel, angle);
}
