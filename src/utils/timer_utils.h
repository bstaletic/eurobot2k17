#ifndef TIMER_UTILS
#define TIMER_UTILS

#include <stdint.h>
#include <tim.h>

void set_pwm(uint8_t tim, uint32_t channel, int16_t pwm_value);

#endif /* ifndef TIMER_UTILS */
