#include <initialisation/gpio_config.h>

void gpio_config(void)
{

	/* GPIO setup for every timer */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO3|GPIO8|GPIO15);
	gpio_mode_setup(GPIOB,
					GPIO_MODE_AF,
					GPIO_PUPD_NONE,
					GPIO4|GPIO5|GPIO7|GPIO8);
	gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO5|GPIO6);
	/* Set alt function for TIM1 and TIM2 both CH1 */
	gpio_set_af(GPIOA, GPIO_AF1, GPIO8|GPIO15);
	/* Set alt function for TIM3 CH1 and CH2 */
	gpio_set_af(GPIOB, GPIO_AF2, GPIO4|GPIO5);
	/* Set alt function for TIM4 CH1 */
	gpio_set_af(GPIOB, GPIO_AF2, GPIO7);
	/* Set alt function for TIM5 CH4 */
	gpio_set_af(GPIOA, GPIO_AF2, GPIO3);
	/* Set alt function for TIM9 CH1 and CH2 */
	gpio_set_af(GPIOE, GPIO_AF3, GPIO5|GPIO6);
	/* Set alt function for TIM10 CH1 */
	gpio_set_af(GPIOB, GPIO_AF3, GPIO8);

	/* GPIO for the two digital outputs for colour sensor */
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO6|GPIO7);
	gpio_set(GPIOD, GPIO6|GPIO7);

	/* Timer PWM GPIO output setup */
	gpio_set_output_options(GPIOA,
							GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ,
							GPIO8|GPIO15);
	gpio_set_output_options(GPIOB,
							GPIO_OTYPE_PP,
							GPIO_OSPEED_100MHZ,
							GPIO4|GPIO5|GPIO7|GPIO8);
	gpio_set_output_options(GPIOE,
							GPIO_OTYPE_PP,
							GPIO_OSPEED_100MHZ,
							GPIO5|GPIO6);

	/* USART2 GPIO setup */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);

	/* USART3 GPIO setup */
	gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11);
	gpio_set_af(GPIOB, GPIO_AF7, GPIO11);
	gpio_mode_setup(GPIOD, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO8);
	gpio_set_af(GPIOD, GPIO_AF7, GPIO8);

	/* USART4 GPIO setup */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO0|GPIO1);
	gpio_set_af(GPIOA, GPIO_AF8, GPIO0|GPIO1);

	/* Configure GPIO for external interrupts (sensors) */
	/* NOTE: only inputs with bodge pull down resistors are used */

	/* EXTI0 PB0, EXTI0 PB2 GPIO setup */
	gpio_mode_setup(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0|GPIO2);

	/* EXT8 PE8, EXT11 PE11. EXT13 PE13, EXT15 PE15 */
	gpio_mode_setup(GPIOE, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO8|GPIO11|GPIO13|GPIO15);

	/* Mosfets switch config */

	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, GPIO0|GPIO1|GPIO2|GPIO3);
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, GPIO6|GPIO8|GPIO9|GPIO11);

	/*LEDs output GPIO setup */
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12|GPIO13|GPIO14|GPIO15);
	
}
