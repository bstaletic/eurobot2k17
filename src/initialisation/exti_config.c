#include <initialisation/exti_config.h>

void exti_config(void)
{
	/*Note: if a sensor input is not used, it should be disabled here */

	/* Enable EXTI0 interrupt. */
	nvic_enable_irq(NVIC_EXTI0_IRQ);

	/* Configure the EXTI subsystem. */
	exti_select_source(EXTI0, GPIOB);
	exti_set_trigger(EXTI0, EXTI_TRIGGER_RISING);
	exti_enable_request(EXTI0);
}
