#include "tasks_init.h"

void tasks_main(void){
	// call constructors for all tasks
	ctor_test_1();
	ctor_test_2();
	blinky_led_test();
	ctor_roll_me_up();
	ctor_task_idle();
	ctor_time_update();

	// run task manager
	task_mngr_run();
}
