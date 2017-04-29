#ifndef START_TASK
#define START_TASK

#include "../core/task_mngr.h"
#include "../drivers/misc/jumper_and_colour_switch.h"
#include "tim.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

#include "task_headers.h"

void ctor_start_task(void);

#endif /* ifndef START_TASK */
