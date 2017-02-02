#ifndef CORE_TASK_MNGR_H
#define CORE_TASK_MNGR_H

#include "task.h"

#define TASK_USER_LIST_SIZE 50
#define TASK_SYSTEM_PREEXECUTE_LIST_SIZE 20
#define TASK_SYSTEM_POSTEXECUTE_LIST_SIZE 20


task_t task_user_list[TASK_USER_LIST_SIZE];
task_t task_user_active;
task_t task_system_preexecute[TASK_SYSTEM_PREEXECUTE_LIST_SIZE];
task_t task_system_postexecute[TASK_SYSTEM_PREEXECUTE_LIST_SIZE];

/**
 * @brief taks manager main function. While(1) function that runs tasks according to their priorities
 */
void task_mngr_run();

/**
 * @brief executes all system preexecute tasks
 */
void run_systemtask_preexecute(void);

/**
 * @brief executes all system post execute tasks
 */
void run_systemtask_postexecute(void);

#endif
