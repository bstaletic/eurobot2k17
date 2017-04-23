#ifndef TASKS_CLOCK_UPDATE_H
#define TASKS_CLOCK_UPDATE_H

#include "../core/task_mngr.h"
#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

extern RTC_HandleTypeDef hrtc;

void ctor_time_update(void);

#endif // TASKS_CLOCK_UPDATE_H
