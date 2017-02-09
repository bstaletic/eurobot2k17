#include <initialisation/clock_config.h>
#include <initialisation/gpio_config.h>
#include <initialisation/uart_config.h>
#include <initialisation/timer_config.h>
#include <initialisation/adc_config.h>
#include <initialisation/exti_config.h>

#include <drivers/actuators/ax12/ax12.h>
#include <drivers/actuators/motion/motion.h>
#include <drivers/sensors/analog/colour.h>


void exti0_isr(void){

	gpio_toggle(GPIOD, GPIO13);

	exti_reset_request(EXTI0);
}	

void main(void)
{
	//_disable_interrupts();
	clock_config();
	gpio_config();
	exti_config();

	usart2_config();
	usart3_config();
	uart4_config();

	timer1_config();
	timer2_config();
	timer3_config();
	timer4_config();
	timer9_config();
	timer10_config();

	int i=0;

	while(1){
		gpio_toggle(GPIOD, GPIO12);	/* LED on/off */
		for (i = 0; i < 10000000; i++) {	/* Wait a bit. */
			__asm__("nop");
		}
		
		
	}

}
