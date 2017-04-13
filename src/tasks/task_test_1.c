#include "task_test_1.h"

task_t task_test_1;
task_arguments_t task_test_1_arguments;

void task_test_1_run(task_arguments_t* argv){
	debug("task_test_1 run method ");
	osDelay(1000);
	argv->state = TASK_DONE;

}
void task_test_1_init(task_arguments_t* argv){
	debug("task_test_1_init");
}
void task_test_1_finish(task_arguments_t* argv){
	debug("task_test_1_finish");
}

void task_test_1_calculate_priority(task_arguments_t* argv){
	debug("task_test_1_calc_pri");
}


void ctor_test_1(void){

	debug("test 1 ctor");

	task_test_1.run = (task_callback)&task_test_1_run;
	task_test_1.init = (task_callback)&task_test_1_init;
	task_test_1.finish = (task_callback)&task_test_1_finish;
	task_test_1.calculate_priority = (task_callback)&task_test_1_calculate_priority;
	strncpy(task_test_1.task_name,"Test Task 1\0",12);

	task_test_1_arguments.estimated_time = 50;
	task_test_1_arguments.priority = 100;
	task_test_1_arguments.state = TASK_READY;

	task_test_1.data = &task_test_1_arguments;

	add_task(&task_test_1);
}
