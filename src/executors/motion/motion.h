#ifndef EXECUTORS_MOTION_H
#define EXECUTORS_MOTION_H

#include "../utils/logger.h"
#include "../utils/common_utils.h"
#include "../drivers/actuators/motion/motion.h"
#include "../drivers/sensors/optical/optical.h"
#include "cmsis_os.h"

#include <math.h>

#define FRONT_LEFT_SENSOR optical_sensor_3
#define FRONT_RIGHT_SENSOR optical_sensor_1
#define BACK_SENSOR optical_sensor_5

#define MOTION_MUTEX_WAIT_MS 2
#define MAX_MOTION_QUEUE_LENGTH 50
#define MAX_RETRY_COUNT 500
#define CENTER_TO_CENTER 450
#define Y_MIN 0
#define Y_MAX 3000
#define X_MIN 0
#define X_MAX 2000
#define START_FIELD_X_MIN 0
#define START_FIELD_X_MAX 350
#define ALLY_START_FIELD_Y_MAX 350
#define ENEMY_START_FIEL_Y_MIN 2650


void motion_queue_push(void* command);
void* motion_queue_pull(void);


/**
 * @brief motion main function. It runs in own thread
 */
void motion_main(void);

void motion_ctor(void);

# endif // EXECUTORS_MOTION_H
