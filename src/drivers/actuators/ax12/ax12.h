#ifndef AX12_DRIVER
#define AX12_DRIVER

#include <libopencm3/stm32/usart.h>
#include <stdint.h>

#define AX12 UART4

#define GOAL_LENGTH 5
#define GOAL_SP_LENGTH 7
#define GOAL_SPEED_LENGTH 5
#define RESET_LENGTH 2
#define ID_LENGTH 4
#define RESET_LENGTH 2
#define BAUDRATE_LENGTH 4
#define AL_LENGTH 7

#define START 255
#define GOAL_POSITION_L 30
#define RESET 6
#define ID 3
#define BAUDRATE 4
#define ANGLE_LIMIT 6
#define GOAL_SPEED_L 32

#define WRITE_DATA 3

/** \file ax12.h
 * AX12 function
 */

/** \fn void move(uint8_t id, uint16_t position)
 * \brief Rotates AX12 to specified position
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param position [in] Desired position of AX12 Possible values are [0,1023]
 */
void move(uint8_t id, uint16_t position);
/** \fn void move_speed(uint8_t id, uint16_t position, uint16_t speed)
 * \brief Rotates AX12 to specified position at the specified speed
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param position [in] Desired position of AX12 Possible values are [0,1023]
 * @param speed [in] Rotate at desired speed Possible values are [0,255]
 */
void move_speed(uint8_t id, uint16_t position, uint16_t speed);
/** \fn void set_speed(uint8_t id, uint16_t speed)
 * \brief Sets the speed of AX12 for future use
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param speed [in] Rotate at desired speed Possible values are [0,255]
 */
void set_speed(uint8_t id, uint16_t speed);
/** \fn void factory_reset(uint8_t id)
 * \brief Restes the AX12 to factory defaults
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 */
void factory_reset(uint8_t id);
/** \fn void set_id(uint8_t id, uint8_t new_id)
 * \brief Sets the id of AX12 for future use
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param new_id [in] The desired new id of AX12.
 */
void set_id(uint8_t id, uint8_t new_id);
/** \fn void set_baudrate(uint8_t id, uint32_t baudrate)
 * \brief Sets the baudrate of AX12 for future use
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param baudrate [in] Specifies the baudrate at which the AX12 communicates
 */
void set_baudrate(uint8_t id, uint32_t baudrate);
/** \fn void set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit)
 * \brief Sets the angle limits for rotating both clockwise and counter clockwise
 *
 * @param id [in] Uniquely identifies the AX12. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param cw_limit [in] Limits the maximum angle for clockwise rotation
 * @param ccw_limit [in] Limits the maximum angle for counter clockwise rotation
 *
 * If both angle limits are set to 0 AX12 is being used in wheel mode
 */
void set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit);

#endif /* ifndef AX12_DRIVER */
