#ifndef GPIO_CINFUG
#define GPIO_CINFUG

#include <libopencm3/stm32/gpio.h>

/* LEDs macros for STM32F4 dev board */
#define GREEN_LED GPIOD, GPIO12
#define ORANGE_LED GPIOD, GPIO13
#define RED_LED	GPIOD, GPIO14
#define BLUE_LED GPIOD, GPIO15

/** \file gpio_config.h
 * \brief Configures GPIO pins
 */

/** \fn void gpio_config(void)
 * \brief Configures GPIO pins.
 *
 * TIM1 set as PWM CH1 uses pin GPIOA8
 * TIM2 set as PWM CH1 uses pin GPIOA15
 * TIM3 set as PWM CH1/CH2 uses pins GPIOB4 and GPIO5
 * TIM4 set as PWM CH2 uses pin GPIOB7
 * TIM9 set as PWM CH1/CH2 uses pins GPIOE5 and GPIOE6
 * TIM10 set as PWM CH1 uses pin GPIOB8
 *
 * Timers are set to push/pull output type and GPIO output speed is 100MHz
 *
 * USART2 uses pin GPIOA2 as alternative function 7. Works in halfduplex mode and is used for Dynamixel AX12 motors
 * USART3 uses pins GPIOB11 and GPIOD8 as alternative function 7.
 * UART4 uses pins GPIO0 and GPIIOA1 as alternative function 8. Non synchronous.
 *
 * Peripheral | Pin | Function
 * ---------- | --- | ---------
 *  TIM1      |  A8 |   PWM CH1
 *  TIM2      | A15 |   PWM CH1
 *  TIM3      |  B4 |   PWM CH1
 *  TIM3      |  B5 |   PWM CH2
 *  TIM4      |  B7 |   PWM CH1
 *  TIM9      |  E5 |   PWM CH1
 *  TIM9      |  E6 |   PWM CH2
 *  TIM10     |  B8 |   PWM CH1
 *  USART2    |  A2 | USART2_TX
 *  USART3    | B11 | USART3_RX
 *  USART3    |  D8 | USART3_TX
 *  UART4     |  A0 |  UART4_TX
 *  UART4     |  A1 |  UART4_RX
 *
 */
void gpio_config(void);

#endif /* ifndef GPIO_CINFUG */
