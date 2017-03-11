#ifndef OPTICAL_SENSOR
#define OPTICAL_SENSOR

#include <stm32f4xx_it.h>

void EXTI0_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

#endif /* ifndef OPTICAL_SENSOR */
