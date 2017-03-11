#ifndef TRUNK_EXECUTOR
#define TRUNK_EXECUTOR

#include <stdint.h>
#include "../../drivers/actuators/analog_servo/analog_servo.h"

#define OPEN_TRUNK_TIMER 1
#define OPEN_TRUNK_TIMER_CHANNEL TIM_CHANNEL_1
#define OPEN_TRUNK_VALUE 0
#define CLOSE_TRUNK_VALUE 100

#define INCREASE_TRUNK_TIMER 2
#define INCREASE_TRUNK_TIMER_CHANNEL TIM_CHANNEL_1
#define INCREASE_TRUNK_VALUE 0
#define REDUCE_TRUNK_VALUE 100

/**
 * \fn void trunk_open(void)
 * \brief Opens trunk to unload the ores
 */
void trunk_open(void);
void trunk_close(void);
/**
 * \fn void trunk_increase(void)
 * \brief Extends the trunk
 *
 * Allows for much more space inside the robot
 * needed for storing the ores.
 */
void trunk_increase(void);
void trunk_reduce(void);
void trunk_init(void);

#endif /* ifndef TRUNK_EXECUTOR */
