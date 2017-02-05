#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <stdint.h>
#include <initialisation/timer_config.h>
#include <initialisation/gpio_config.h>

#define DC_TIMER TIM12
#define DC_CHANNEL TIM_OC1

#define DC_GPIO GPIOC
#define DC_PIN GPIO6

/**
 * \fn void dc_motor_move(dc_motor dc, int16_t speed);
 * \brief Set dc motor speed
 */
void dc_motor_move(int16_t speed);

/**
 * \fn void dc_motor_direction(dc_motor dc, int8_t direction);
 * \brief Set dc motor direction
 */
void dc_motor_direction(int8_t direction);

#endif /* ifndef DC_MOTOR_H */
