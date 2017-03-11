#ifndef MOTION
#define MOTION

#include <stdint.h>
#include "usart.h"
#include "tim.h"
#include "stm32f4xx_it.h"

#define MOTION_DRIVER UART4

/** \file motion.h
 * \brief Motion driver functions
 */

/** \fn void set_position_and_orientation(int16_t
 *                                       x,
 *                                       int16_t
 *                                       y,
 *                                       int16_t
 *                                       orientation)
 * \brief Sets the postion and orientation. Useful for correcting the driver itself.
 *
 * Corrects the driver by telling it the coordinates and orientation.
 * `x` and `y` are the new coordinates sent to the driver and the `orientation`
 * is the new orientation of the driver.
 *
 * NOTE: This function does NOT move the robot,
 * just corrects the driver on what it reports.
 * @param [in] x Sets x coordinate
 * @param [in] y Sets y coordinate
 * @param [in] orientation Sets orientation
 */
void set_position_and_orientation(int16_t  x, int16_t y, int16_t orientation);
/** \fn void read_status_and_position(void)
 * \brief Read data provided by the driver
 *
 * Receives seven bytes of data:
 *
 * 1. state - possible values: stuck, moving, rotating, error and idle
 * 2. X coordinate - only the higher 8 bits
 * 3. X coordinate - only the lower 8 bits
 * 4. Y coordinate - only the higher 8 bits
 * 5. Y coordinates - only the lower 8 bits
 * 6. Orientation - only the higher 8 bits
 * 7. Orientation - only the lower 8 bits
 */
void read_status_and_position(void);
/** \fn move_forward(int16_t dist, int8_t end_speed)
 * \brief Move the robot forward by `dist` millimeters
 *
 * @param dist [in] Distance to travel in millimeters
 * @param end_speed [in] Speed at which the movement is finished. Must be zero.
 */
void move_forward(int16_t dist, int8_t end_speed);
/** \fn void rotate_for(int16_t angle)
 * \brief Rotate the robot for the desired angle
 *
 * @param angle [in] Rotate for angle degrees
 */
void rotate_for(int16_t angle);
/** \fn void rotate_to(int16_t angle)
 * \brief Rotate the robot to the desired angle
 *
 * @param angle [in] Rotate to orientation specified by angle.
 */
void rotate_to(int16_t angle);
/** \fn void goto_xy(int16_t x, int16_t y, int8_t end_speed, int8_t direction)
 * \brief Let the driver calculate how to get to coordinates (x,y)
 *
 * This works by driver rotating the robot so it faces the (x,y)
 * and moving forward to it.
 * @param x [in] X coordinate of the point where robot should go
 * @param y [in] Y coordinate of the point where robot should go
 * @param end_speed [in] Speed at which the movement is finished. Must be zero.
 * @param direction [in] If positive, move forwards, otherwise move backwards
 */
void goto_xy(int16_t x, int16_t y, int8_t end_speed, int8_t direction);
/** \fn void curve(int16_t x, int16_t y, int8_t angle, int8_t angle_direction, int8_t direction)
 * \brief Move along a curve
 *
 * @param x [in] X coordinate of the center of rotation
 * @param y [in] Y coordinate of the center of rotation
 * @param angle [in] Angle by which robot should be rotated around center
 * @param angle_direction [in] 0 means counter clockwise, otherwise clockwise
 * @param direction [in] negative means backwards, positive forward
 */
void curve(int16_t x, int16_t y, int8_t angle,
		int8_t angle_direction, int8_t direction);
/** \fn void hard_stop(void)
 * \brief Stop moving the robot, but hold position
 */
void hard_stop(void);
/** \fn void soft_stop(void)
 * \brief Stop moving the robot and turn off the PWM
 */
void soft_stop(void);
/** \fn void reset_driver(void)
 * Resets the position and orientation of the driver to 0
 */
void reset_driver(void);
/** \fn void stuck_enable(void)
 * Enables stuck detection feature of the driver
 */
void stuck_enable(void);
/** \fn void stuck_disable(void)
 * Disables stuck detection feature of the driver
 */
void stuck_disable(void);
/** \fn void set_motion_speed(int8_t speed)
 * \brief Set robot's speed
 *
 * Speed actually sets the PWM and has a maximum value of 255.
 * Maximum value should be avoided as it essetially disables
 * any possibility of regulating the robot's position.
 *
 * @param speed [in] Sets the speed of robots motion
 *
 */
void set_motion_speed(int8_t speed);

#endif /* ifndef MOTION */
