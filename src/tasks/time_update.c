#include "time_update.h"

int counter = 0;
task_t task;
task_arguments_t arguments;

void run_ck(task_arguments_t* argv){
//	argv->time = 10;
	counter++;

//	if(counter > 10){
		debug("time update, time %d", argv->time);
//		counter = 0;
		argv->time ++;

//	}
}

void ctor_time_update(void){

	task.run = (task_callback)&run_ck;
	task.type = TASK_SYSTEM_PREEXECUTE;
	strncpy(task.task_name,"time update\0",12);

	arguments.time = 0;


	task.data = &arguments;

	add_task(&task);
}
