#include "task_test_2.h"

task_t task_test_2;
task_arguments_t task_test_2_arguments;

void test_task_2_run(task_arguments_t* argv){
	debug("test_task_2_run");
	osDelay(10000);
	argv->state = TASK_BLOCKED;
	argv->priority = 50;
}
void test_task_2_init(task_arguments_t* argv){
	debug("test_task_2_init");
}
void test_task_2_finish(task_arguments_t* argv){
	debug("test_task_2_finish");
}

void test_task_2_calculate_priority(task_arguments_t* argv){
	debug("test_task_2_calc_pri");
	argv->state = TASK_READY;
}


void ctor_test_2(void){
	debug("test_task_2_ctor");
	task_test_2.run = (task_callback)&test_task_2_run;
	task_test_2.init = (task_callback)&test_task_2_init;
	task_test_2.finish = (task_callback)&test_task_2_finish;
	task_test_2.calculate_priority = (task_callback)&test_task_2_calculate_priority;
	strncpy(task_test_2.task_name,"Test Task 2\0",12);

	task_test_2_arguments.estimated_time = 50;
	task_test_2_arguments.priority = 120;
	task_test_2_arguments.state = TASK_READY;

	task_test_2.data = &task_test_2_arguments;

	add_task(&task_test_2);
}
