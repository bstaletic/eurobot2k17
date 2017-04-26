#ifndef OPTICAL_SENSOR
#define OPTICAL_SENSOR

#include <stm32f4xx_it.h>
#include "../../../initialisation/gpio.h"

extern volatile uint8_t optical_sensor_1, optical_sensor_3, optical_sensor_5;

void EXTI0_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI9_5_IRQHandler(void);

#endif /* ifndef OPTICAL_SENSOR */
