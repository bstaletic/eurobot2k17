#include "idle.h"

static task_t task;
static task_arguments_t arguments;

void idle_run(task_arguments_t* argv){
	error("running IDLE task, time %d", *argv->time);
	osThreadYield();
	argv->state = TASK_DONE;
}
void idle_init(task_arguments_t* argv){
	argv->estimated_time = 200;
}
void idle_finish(task_arguments_t* argv){
	error("finishing IDLE task, time %d", *argv->time);
}

void idle_cp(task_arguments_t* argv){
	// #todo remove, testing purpose
	if(argv->priority != 0){
		argv->priority = 0;
	}
}


void ctor_task_idle(void){

	task.run = (task_callback)&idle_run;
	task.init = (task_callback)&idle_init;
	task.finish = (task_callback)&idle_finish;
	task.calculate_priority = (task_callback)&idle_cp;
	strncpy(task.task_name,"IDLE\0",5);

	arguments.estimated_time = 50;
	arguments.priority = 0;
	arguments.state = TASK_READY;

	task.data = &arguments;

	add_task(&task);
}
