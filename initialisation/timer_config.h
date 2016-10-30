#ifndef TIMER_CONFIG
#define TIMER_CONFIG

#include <libopencm3/stm32/timer.h>

void static timer1_config(void);
void static timer2_config(void);
void static timer3_config(void);
void static timer4_config(void);
void static timer9_config(void);
void static timer10_config(void);

void static timer_clock_config(void);

#endif /* ifndef TIMER_CONFIG */
