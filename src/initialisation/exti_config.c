#include <initialisation/exti_config.h>

void exti_config(void)
{
	/*Note: if a sensor input is not used, it should be disabled here */

	/* Enable EXTI interrupt. */
	nvic_enable_irq(NVIC_EXTI0_IRQ);
	nvic_enable_irq(NVIC_EXTI2_IRQ);
	nvic_enable_irq(NVIC_EXTI9_5_IRQ);
	nvic_enable_irq(NVIC_EXTI15_10_IRQ);

	/* Configure the EXTI subsystem. */
	exti_select_source(EXTI0|EXTI2, GPIOB);
	exti_select_source(EXTI8|EXTI11|EXTI13|EXTI15, GPIOE);
	exti_set_trigger(EXTI0|EXTI2|EXTI8|EXTI11|EXTI13|EXTI15, EXTI_TRIGGER_BOTH);
	exti_enable_request(EXTI0|EXTI2|EXTI8|EXTI11|EXTI13|EXTI15);
}
