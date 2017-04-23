#include "time_update.h"

int counter = 0;
task_t task;
task_arguments_t arguments;
RTC_TimeTypeDef stime;
uint32_t time;


static void run_ck(task_arguments_t* argv){
	HAL_RTC_GetTime(&hrtc,&stime,RTC_FORMAT_BCD);

	int time = (stime.Minutes * 60) + stime.Seconds;

	if(argv->time != (uint32_t)time){
		argv->time = time;
		info("time update: %d ", time);
	}
}

void ctor_time_update(void){

	task.run = (task_callback)&run_ck;
	task.type = TASK_SYSTEM_PREEXECUTE;
	strncpy(task.task_name,"time update\0",12);

	arguments.time = 0;


	task.data = &arguments;

	add_task(&task);
}
