#include <drivers/sensors/digital/optical_sensors.h>

/* ISR for Sensor0 */
void exti0_isr(void){

	if (gpio_get(GPIOB, GPIO0)){

		/* Here goes code when something is detected */

	}

	else {

		/* Here goes code when there is not anything in front of the sensor */

	}

	exti_reset_request(EXTI0);
}

/* ISR for Sensor3 */
void exti2_isr(void){

	if (gpio_get(GPIOB, GPIO2)){

		/* Here goes code when something is detected */
	}

	else {

		/* Here goes code when there is not anything in front of the sensor */
	}

	exti_reset_request(EXTI2);
}

/* ISR for Sensor5 */
void exti9_5_isr(void){

	if (gpio_get(GPIOE, GPIO8)){

		/* Here goes code when something is detected */
	}

	else {

		/* Here goes code when there is not anything in front of the sensor */
	}

	exti_reset_request(EXTI9|EXTI8|EXTI7|EXTI6|EXTI5);

}

/* ISR for Sensor8, Sensor10 and Sensor12 */
void exti15_10_isr(void){

	if (exti_get_flag_status(EXTI11)){

		if (gpio_get(GPIOE, GPIO11)){

			/* Here goes code when something is detected */
		}

		else {

			/* Here goes code when there is not anything in front of the sensor */
		}
	}

	else if (exti_get_flag_status(EXTI13)){

		if (gpio_get(GPIOE, GPIO13)){

			/* Here goes code when something is detected */

		}

		else {

			/* Here goes code when there is not anything in front of the sensor */

		}
	}

	else if (exti_get_flag_status(EXTI15)){

		if (gpio_get(GPIOE, GPIO15)){

			/* Here goes code when something is detected */

		}

		else {

			/* Here goes code when there is not anything in front of the sensor */

		}

	}

	exti_reset_request(EXTI11|EXTI13|EXTI15);
}
