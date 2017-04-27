#include "task_mngr.h"


//this functions are in-line because they are run only from task manager at one place.
inline void run_systemtasks_preexecute(void);
inline void run_systemtasks_postexecute(void);
inline void run_calculate_priority(void);
inline void run_usertasks(void);
task_t* find_next_task();

task_t* task_user_active = NULL;
task_t* task_user_list[] = {[0 ... (TASK_USER_LIST_SIZE-1)] = NULL};
task_t* task_system_preexecute[] = {[0 ... (TASK_SYSTEM_PREEXECUTE_LIST_SIZE-1)] = NULL};
task_t* task_system_postexecute[]= {[0 ... (TASK_SYSTEM_POSTEXECUTE_LIST_SIZE-1)] = NULL};
task_t* task_user_backproc[] = {[0 ... (TASK_USER_BACKPROC_LIST_SIZE-1)] = NULL};

static int task_user_couter = 0;
static int task_system_preexecute_couter = 0;
static int task_system_postexecute_couter = 0;
static int task_user_backproc_couter = 0;
static uint8_t tasks_ready_boolean = 1;

extern volatile uint32_t system_time;// workd state;

void task_mngr_run(){

	if(task_user_couter == 0 &&
			task_system_postexecute_couter == 0 &&
			task_system_preexecute_couter == 0){
		error("there are not task in list");
		return;
	}
	//*************** Task manager main loop ***********************
	info("starting task manager!");
	while(1){

		// 1. run pre-executed system tasks from list
		if(task_system_preexecute_couter > 0){
			run_systemtasks_preexecute();
		}

		// 2. run currently active task. If there is no active task chose one with biggest priority.
		if(task_user_couter > 0 && tasks_ready_boolean == 1){
			run_usertasks();
		}

		//3. run post-executed system tasks
		if(task_system_postexecute_couter > 0){
			run_systemtasks_postexecute();
		}

		//		for(int i = 0; i < 100000000; i++);
		taskYIELD();
	}
}


void run_usertasks(void){
	// active task is active run his run callback

	if(task_user_active == NULL){
		task_user_active = find_next_task();
		// if task is NULL then there is no active tasks
		if(task_user_active == NULL)return;
		//run init of  task
		task_user_active->init(task_user_active->data);
		//set task to active
		task_user_active->data->state = TASK_ACTIVE;
	}

	if(task_user_active->data->state == TASK_ACTIVE){
		task_user_active->run(task_user_active->data);

		// if active task is waiting to motion
	}else if(task_user_active->data->state == TASK_ACTIVE_WTM){

		task_user_active->run(task_user_active->data);

	}else if(task_user_active->data->state == TASK_BLOCKED){

		// find next task that will be executed
		task_user_active = find_next_task();
		// if task is NULL then there is no active tasks
		if(task_user_active == NULL)return;
		// run init of task
		task_user_active->init(task_user_active->data);
		// set status of task to active
		task_user_active->data->state = TASK_ACTIVE;

	}else{
		if(task_user_active->finish != NULL){
			task_user_active->finish(task_user_active->data);
		}else{
			error("task %s, has no finish task", task_user_active->task_name);
		}

		// find next task that will be executed
		task_user_active = find_next_task();
		// if task is NULL then there is no active tasks
		if(task_user_active == NULL)return;
		// set status of task to active
		task_user_active->data->state = TASK_ACTIVE;
	}
}

void run_systemtasks_preexecute(void){
	for(int i = 0; i < TASK_SYSTEM_PREEXECUTE_LIST_SIZE; i++){
		if(task_system_preexecute[i] != NULL){
			task_system_preexecute[i]->run(task_system_preexecute[i]->data);
		}
	}
}


void run_systemtasks_postexecute(void){
	for(int i = 0; i < TASK_SYSTEM_POSTEXECUTE_LIST_SIZE; i++){
		if(task_system_postexecute[i] != NULL){
			task_system_postexecute[i]->run(task_system_postexecute[i]->data);
		}
	}
}

void run_calculate_priority(void){
	for(int i = 0; i < TASK_USER_LIST_SIZE; i++){
		if(task_user_list[i] != NULL){
			if(task_user_list[i]->data->state != TASK_DONE)
				task_user_list[i]->calculate_priority(task_user_list[i]->data);
		}
	}
}

/**
 * @brief sets _task to active task
 * @param _task to be set as active
 */
void set_start_task(task_t *_task){
	task_user_active->data->state = TASK_ACTIVE;
	task_user_active = _task;
}

/**
 * @brief adds task to corresponding lists of tasks
 * @param _task pointer to task that should be added
 */
void add_task(task_t *_task){

	//set pointer to time in every task to same int time

	_task->data->time = &system_time;
	_task->data->colour = colour_switch;

	if(_task->type == TASK_USER){
		if(task_user_couter < TASK_USER_LIST_SIZE){
			task_user_list[task_user_couter++] = _task;
		}else{
			error("TASK_USER_LIST is to small, skipping task adding");
		}
	}else if(_task->type == TASK_SYSTEM_PREEXECUTE){
		if(task_system_preexecute_couter < TASK_SYSTEM_PREEXECUTE_LIST_SIZE){
			task_system_preexecute[task_system_preexecute_couter++] = _task;
		}else{
			error("TASK_SYSTEM_PREEXECUTE_LIST is to small, skipping task adding");
		}
	}else if(_task->type == TASK_SYSTEM_POSTEXECUTE){
		if(task_system_postexecute_couter < TASK_SYSTEM_POSTEXECUTE_LIST_SIZE){
			task_system_postexecute[task_system_postexecute_couter++] = _task;
		}else{
			error("TASK_SYSTEM_POSTEXECUTE_LIST is to small, skipping task adding");
		}
	}else if(_task->type == TASK_BACKPROC){
		if(task_user_backproc_couter < TASK_USER_BACKPROC_LIST_SIZE){
			task_user_backproc[task_user_backproc_couter++] = _task;
		}else{
			error("TASK_USER_BACKPROC_LIST is to small, skipping task adding");
		}
	}else{
		error("Task manager: adding task: unknown task type");
	}
	taskYIELD();
}

/*
 * @brief finds ready task (TASK_READY status) with biggest priority.
 * @param _task pointer to task
 */
task_t* find_next_task(void){
	task_t *_task = NULL;
	int state = 0;

	// update priority and status of tasks
	run_calculate_priority();

	// find task with biggest priority
	for(int i = 0; i < task_user_couter; i++){
		switch (state) {
		case 0:{
			if(task_user_list[i]->data->state == TASK_READY){
				_task = task_user_list[i];
				state++;
			}
		}break;

		default:{
			if(_task->data->priority < task_user_list[i]->data->priority &&
					task_user_list[i]->data->state == TASK_READY){
				_task = task_user_list[i];
			}
		}
		} // end switch
	}
	if(_task != NULL) {
		info("Starting task: %s, by priority: %d",_task->task_name, _task->data->priority);
	}else{
		error("No Ready task in list ! exiting");
		tasks_ready_boolean = 0;
	}
	return _task;
}
