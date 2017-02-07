#include <drivers/sensors/digital/optical_sensors.h>

/* ISR for Sensor0 */
void exti0_isr(void){

	exti_reset_request(EXTI0);
}

/* ISR for Sensor3 */
void exti2_isr(void){

	exti_reset_request(EXTI2);
}

/* ISR for Sensor5 */
void exti9_5_isr(void){

	exti_reset_request(EXTI9|EXTI8|EXTI7|EXTI6|EXTI5);

}

/* ISR for Sensor8, Sensor11 and Sensor13 */
void exti15_10_isr(void){

	if (exti_get_flag_status(EXTI11)){
		gpio_toggle(GPIOD, GPIO14);
	}

	else if (exti_get_flag_status(EXTI13)){
		gpio_toggle(GPIOD, GPIO15);

	}

	else if (exti_get_flag_status(EXTI15)){

	}

	exti_reset_request(EXTI11|EXTI13|EXTI15);

}
