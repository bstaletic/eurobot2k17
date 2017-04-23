#ifndef TASKS_TASK_HEADERS_H
#define TASKS_TASK_HEADERS_H

#include "../core/task_mngr.h"
#include "cmsis_os.h"

#include "../executors/colour_shifter/colour_shifter.h"
#include "../executors/common/common.h"
#include "../executors/door/door.h"
#include "../executors/front_rollers/front_rollers.h"
#include "../executors/motion/motion_command.h"
#include "../executors/revolver/revolver.h"
#include "../executors/rocket/rocket.h"
#include "../executors/trunk/trunk.h"

void ctor_task_headers(void);

#endif
