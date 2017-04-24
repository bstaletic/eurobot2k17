#include "funny_action_task.h"

task_t funny_action_task;
task_arguments_t funny_action_task_arguments;

//wating for rtc to be figured out

void funny_action_task_run(task_arguments_t* argv){
	debug("funny_action_task run method ");
	osDelay(1000);
	argv->state = TASK_DONE;

}
void funny_action_task_init(task_arguments_t* argv){
	debug("funny_action_task_init");
}
void funny_action_task_finish(task_arguments_t* argv){
	debug("funny_action_task_finish");
}

void funny_action_task_calculate_priority(task_arguments_t* argv){
	debug("funny_action_task_calc_pri");
}


void ctor_test_1(void){

	debug("funny_action_task ctor");

	funny_action_task.run = (task_callback)&funny_action_task_run;
	funny_action_task.init = (task_callback)&funny_action_task_init;
	funny_action_task.finish = (task_callback)&funny_action_task_finish;
	funny_action_task.calculate_priority = (task_callback)&funny_action_task_calculate_priority;
	strncpy(funny_action_task.task_name,"Test Task 1\0",12);

	funny_action_task_arguments.estimated_time = 50;
	funny_action_task_arguments.priority = 100;
	funny_action_task_arguments.state = TASK_READY;

	funny_action_task.data = &funny_action_task_arguments;

	add_task(&funny_action_task);
}