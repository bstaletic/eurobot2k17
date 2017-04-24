#include "task_blinky_led.h"

task_t task_blinky_led;
task_arguments_t task_blinky_led_arguments;

void task_blinky_led_run(task_arguments_t* argv){
	debug("task_blinky_led run method ");

		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);

	argv->state = TASK_DONE;

}
void task_blinky_led_init(task_arguments_t* argv){
	debug("task_blinky_led_init");
}
void task_blinky_led_finish(task_arguments_t* argv){
	debug("task_blinky_led_finish");
}

void task_blinky_led_calculate_priority(task_arguments_t* argv){
	debug("task_blinky_led_calc_pri");
}


void blinky_led_test(void){

	debug("blinky led test");

	task_blinky_led.run = (task_callback)&task_blinky_led_run;
	task_blinky_led.init = (task_callback)&task_blinky_led_init;
	task_blinky_led.finish = (task_callback)&task_blinky_led_finish;
	task_blinky_led.calculate_priority = (task_callback)&task_blinky_led_calculate_priority;
	strncpy(task_blinky_led.task_name,"Test Task 1\0",12);

	task_blinky_led_arguments.estimated_time = 50;
	task_blinky_led_arguments.priority = 200;
	task_blinky_led_arguments.state = TASK_READY;

	task_blinky_led.data = &task_blinky_led_arguments;

	add_task(&task_blinky_led);
}
