#include <initialisation/clock_config.h>
#include <initialisation/gpio_config.h>
#include <initialisation/uart_config.h>
#include <initialisation/timer_config.h>
#include <initialisation/adc_config.h>
#include <initialisation/exti_config.h>

#include <drivers/actuators/ax12/ax12.h>
#include <drivers/actuators/motion/motion.h>
#include <drivers/sensors/analog/colour.h>


#include "tasks/task_test_1.h"
#include "tasks/task_test_2.h"
#include "core/task_mngr.h"

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

	ctor_test_1();
	ctor_test_2();

	task_mngr_run();

	while (1) {

	}

}
