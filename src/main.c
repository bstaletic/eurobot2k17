#include <initialisation/clock_config.h>
#include <initialisation/gpio_config.h>
#include <initialisation/uart_config.h>
#include <initialisation/timer_config.h>

#include <drivers/actuators/ax12/ax12.h>
#include <drivers/actuators/motion/motion.h>

void main(void)
{
	clock_config();
	gpio_config();

	usart2_config();
	usart3_config();
	uart4_config();

	timer1_config();
	timer2_config();
	timer3_config();
	timer4_config();
	timer9_config();
	timer10_config();

	while (1) {

	}

}
