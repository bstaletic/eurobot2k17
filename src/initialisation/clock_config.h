#ifndef CLOCK_CONFIG
#define CLOCK_CONFIG

#include <libopencm3/stm32/rcc.h>

/** \file clock_config.h
 * \brief Clock configuartion file
 */

/** \fn void clock_config(void)
 * \brief Configures the clock for all the peripherals used
 *
 * Enable GPIOA, GPIOB, GPIOD and GPIOE clock.
 *
 * Enables USART2, USART3 and UART4 clock.
 *
 * Enables TIM1, TIM2, TIM3, TIM4, TIM9 and TIM10 clock.
 *
 * Enable ADC1 clock.
 *
 */
void clock_config(void);

#endif /* ifndef CLOCK_CONFIG */
