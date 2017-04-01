#include "tasks_init.h"

void tasks_main(void){
	// call constructors for all tasks
	ctor_test_1();
	ctor_test_2();
	ctor_task_idle();
	ctor_time_update();

	// run task manager
	task_mngr_run();
}
