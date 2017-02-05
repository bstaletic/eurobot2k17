#ifndef TIMER_CONFIG
#define TIMER_CONFIG

#include <libopencm3/stm32/timer.h>
#include <libopencmsis/nvic.h>
#include <stdint.h>

#define COLOUR_SENSOR_TIMER TIM5

extern volatile int32_t colour_sensor_frequency;

void timer1_config(void);
void timer2_config(void);
void timer3_config(void);
void timer4_config(void);
void timer5_config(void);
void timer9_config(void);
void timer10_config(void);
void timer14_config(void);

#endif /* ifndef TIMER_CONFIG */
