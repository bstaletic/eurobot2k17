#ifndef TIMER_CONFIG
#define TIMER_CONFIG

#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <stdint.h>

#define COLOUR_SENSOR_TIMER TIM12

void timer_config(void);
void delay(uint32_t clocks);

#endif /* ifndef TIMER_CONFIG */
