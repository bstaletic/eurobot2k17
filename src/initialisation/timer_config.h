#ifndef TIMER_CONFIG
#define TIMER_CONFIG

#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <stdint.h>

#define COLOUR_SENSOR_TIMER TIM12

extern volatile int32_t colour_sensor_frequency; // raw output of sensor, if everything is working should be in kHz
extern volatile int32_t colour_sensor_value_ready; // set to true when reading the sensor is done

void timer1_config(void);
void timer2_config(void);
void timer3_config(void);
void timer4_config(void);
void timer6_config(void);
void timer9_config(void);
void timer10_config(void);
void timer12_config(void);

#endif /* ifndef TIMER_CONFIG */
