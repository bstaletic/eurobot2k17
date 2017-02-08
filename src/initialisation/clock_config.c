#include <initialisation/clock_config.h>

void clock_config(void)
{
	/* Enable clock for NVIC and stuff */
	rcc_periph_clock_enable(RCC_SYSCFG);

	/* Enable GPIOD clock for all needed ports */
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_GPIOD);
	rcc_periph_clock_enable(RCC_GPIOE);

	/* Enable clocks for USART2. */
	rcc_periph_clock_enable(RCC_USART2);
	/* Enable clocks for USART3. */
	rcc_periph_clock_enable(RCC_USART3);
	/* Enable clocks for USART4. */
	rcc_periph_clock_enable(RCC_UART4);

	rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);

	/* TIM1 clock enable */
	rcc_periph_clock_enable(RCC_TIM1);
	/* TIM2 clock enable */
	rcc_periph_clock_enable(RCC_TIM2);
	/* TIM3 clock enable */
	rcc_periph_clock_enable(RCC_TIM3);
	/* TIM4 clock enable */
	rcc_periph_clock_enable(RCC_TIM4);
	/* TIM9 clock enable */
	rcc_periph_clock_enable(RCC_TIM9);
	/* TIM10 clock enable */
	rcc_periph_clock_enable(RCC_TIM10);

	/* ADC1 clock enable */
	rcc_periph_clock_enable(RCC_ADC1);
}
