#include "funny_action_task.h"

static task_t funny_action_task;
static task_arguments_t funny_action_task_arguments;

//wating for rtc to be figured out

void funny_action_task_run(task_arguments_t* argv){

	if(*argv->time > 90){
		debug("IT IS GONNA FLY ");
		soft_stop_cmd();
		reset_driver_cmd();
		rocket_launch();
		argv->state = TASK_DONE;
	}else{
		taskYIELD();
	}

}
void funny_action_task_init(task_arguments_t* argv){

	debug("funny_action_task_init");
}
void funny_action_task_finish(task_arguments_t* argv){
	debug("funny_action_task_finish");
}

void funny_action_task_calculate_priority(task_arguments_t* argv){
	//	debug("funny_action_task_calc_pri");
	if(*argv->time > 89){
		debug("IT IS TIME FOR FUNNY ACTION");
		argv->priority = 999;
	}
}


void ctor_funny_action_task(void){

	debug("funny_action_task ctor");
	debug("funny_action_task ctor");
	debug("funny_action_task ctor");

	funny_action_task.run = (task_callback)&funny_action_task_run;
	funny_action_task.init = (task_callback)&funny_action_task_init;
	funny_action_task.finish = (task_callback)&funny_action_task_finish;
	funny_action_task.calculate_priority = (task_callback)&funny_action_task_calculate_priority;
	strncpy(funny_action_task.task_name,"FUNNY ACTION\0",13);

	funny_action_task_arguments.estimated_time = 50;
	funny_action_task_arguments.priority = 100;
	funny_action_task_arguments.state = TASK_READY;

	funny_action_task.data = &funny_action_task_arguments;

	add_task(&funny_action_task);


	debug("MOVING SERVO");
	rocket_init();
}
