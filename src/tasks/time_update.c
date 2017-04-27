#include "time_update.h"

int counter = 0;
static task_t task_time_update;
static task_arguments_t arguments_task_time_update;
RTC_TimeTypeDef stime;
uint32_t test_time = 0;


static void run_ck(task_arguments_t* argv){
//	HAL_RTC_GetTime(&hrtc,&stime,RTC_FORMAT_BCD);

//	int time = (stime.Minutes * 60) + stime.Seconds;
//	info("time update: %d ", system_time);

	if(test_time != system_time){
		test_time = system_time;
		info("time update: %d ", test_time);
	}
}

void ctor_time_update(void){

	task_time_update.run = (task_callback)&run_ck;
	task_time_update.type = TASK_SYSTEM_PREEXECUTE;
	strncpy(task_time_update.task_name,"time update\0",12);

	arguments_task_time_update.time = 0;


	task_time_update.data = &arguments_task_time_update;

	add_task(&task_time_update);
}
