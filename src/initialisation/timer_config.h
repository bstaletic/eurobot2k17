#ifndef TIMER_CONFIG
#define TIMER_CONFIG

#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <stdint.h>

#define COLOUR_SENSOR_TIMER TIM5

extern volatile int32_t colour_sensor_frequency;
extern volatile int32_t colour_sensor_counter_value_ready;

void timer1_config(void);
void timer2_config(void);
void timer3_config(void);
void timer4_config(void);
void timer5_config(void);
void timer6_config(void);
void timer9_config(void);
void timer10_config(void);

#endif /* ifndef TIMER_CONFIG */
