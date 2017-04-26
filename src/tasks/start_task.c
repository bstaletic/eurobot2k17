#include "start_task.h"

task_t task;
task_arguments_t arguments;

static void start_match(task_arguments_t* argv)
{
	// Wait for jumper to be unplugged
	while(jumper);
	//start TIM11
	HAL_TIM_Base_Start(&htim11);
	HAL_TIM_Base_Start_IT(&htim11);
}

void ctor_start_task(void)
{
	task.run = (task_callback)&start_match;
	task.type = TASK_SYSTEM_PREEXECUTE;
	strncpy(task.task_name, "Start match", 12);

	arguments.time = 0;

	task.data = &arguments;

	set_start_task(task);
}
