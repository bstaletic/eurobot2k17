#ifndef CORE_TASK_MNGR_H
#define CORE_TASK_MNGR_H

#include "task.h"
#include <stddef.h>
#include "utils/logger.h"

#define TASK_USER_LIST_SIZE 50
#define TASK_SYSTEM_PREEXECUTE_LIST_SIZE 20
#define TASK_SYSTEM_POSTEXECUTE_LIST_SIZE 20
#define TASK_USER_BACKPROC_LIST_SIZE 20


/**
 * @brief taks manager main function. While(1) function that runs tasks according to their priorities
 */
void task_mngr_run();

void set_start_task(task_t *_task);

void add_task(task_t *_task);




#endif
