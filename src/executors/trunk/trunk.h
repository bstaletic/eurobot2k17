#ifndef TRUNK_EXECUTOR
#define TRUNK_EXECUTOR

#include <stdint.h>
#include <drivers/actuators/analog_servo/analog_servo.h>

#define OPEN_TRUNK_TIMER TIM1
#define OPEN_TRUNK_TIMER_CHANNEL TIM_OC1
#define OPEN_TRUNK_VALUE 0
#define CLOSE_TRUNK_VALUE 100

#define INCREASE_TRUNK_TIMER TIM2
#define INCREASE_TRUNK_TIMER_CHANNEL TIM_OC1
#define INCREASE_TRUNK_VALUE 0
#define REDUCE_TRUNK_VALUE 100

/**
 * \fn void open_trunk(void)
 * \brief Opens trunk to unload the ores
 */
void open_trunk(void);
void close_trunk(void);
/**
 * \fn void increase_trunk(void)
 * \brief Extends the trunk
 *
 * Allows for much more space inside the robot
 * needed for storing the ores.
 */
void increase_trunk(void);
void reduce_trunk(void);

#endif /* ifndef TRUNK_EXECUTOR */
