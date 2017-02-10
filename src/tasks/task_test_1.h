#ifndef TASKS_TASK_TEST_1_H
#define TASKS_TASK_TEST_1_H

#include "core/task_mngr.h"
#include "utils/logger.h"



void task_test_1_run(task_arguments_t* argv);
void task_test_1_init(task_arguments_t* argv);
void task_test_1_finish(task_arguments_t* argv);
void task_test_1_resume(task_arguments_t* argv);
void task_test_1_calculate_priority(task_arguments_t* argv);


void ctor_test_1(void);

#endif
