#ifndef AX12_DRIVER
#define AX12_DRIVER

#include <usart.h>
#include <stdint.h>

#define AX12_UART &huart2

#define AX12_AL_LENGTH 7
#define AX12_BAUDRATE_LENGTH 4
#define AX12_GOAL_LENGTH 5
#define AX12_GOAL_SPEED_LENGTH 5
#define AX12_GOAL_SP_LENGTH 7
#define AX12_ID_LENGTH 4
#define AX12_MOVING_LENGTH 4
#define AX12_RESET_LENGTH 2

#define AX12_START 255
#define AX12_GOAL_POSITION_L 30
#define AX12_RESET 6
#define AX12_ID 3
#define AX12_BAUDRATE 4
#define AX12_ANGLE_LIMIT 6
#define AX12_GOAL_SPEED_L 32
#define AX12_BYTE_READ 1
#define AX12_MOVING 46

#define AX12_WRITE_DATA 3
#define AX12_READ_DATA 2

/** \file ax12.h
 * AX12_UART function
 */

/** \fn uint8_t ax12_move(uint8_t id, uint16_t position)
 * \brief Rotates AX12_UART to specified position
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param position [in] Desired position of AX12_UART Possible values are [0,1023]
 */
uint8_t ax12_move(uint8_t id, uint16_t position);
/** \fn uint8_t ax12_move_speed(uint8_t id, uint16_t position, uint16_t speed)
 * \brief Rotates AX12_UART to specified position at the specified speed
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param position [in] Desired position of AX12_UART Possible values are [0,1023]
 * @param speed [in] Rotate at desired speed Possible values are [0,255]
 */
uint8_t ax12_move_speed(uint8_t id, uint16_t position, uint16_t speed);
/** \fn uint8_t ax12_set_speed(uint8_t id, uint16_t speed)
 * \brief Sets the speed of AX12_UART for future use
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param speed [in] Rotate at desired speed Possible values are [0,255]
 */
uint8_t ax12_set_speed(uint8_t id, uint16_t speed);
/** \fn uint8_t ax12_factory_reset(uint8_t id)
 * \brief Restes the AX12_UART to factory defaults
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 */
uint8_t ax12_factory_reset(uint8_t id);
/** \fn uint8_t ax12_set_id(uint8_t id, uint8_t new_id)
 * \brief Sets the id of AX12_UART for future use
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param new_id [in] The desired new id of AX12_UART.
 */
uint8_t ax12_set_id(uint8_t id, uint8_t new_id);
/** \fn uint8_t ax12_set_baudrate(uint8_t id, uint32_t baudrate)
 * \brief Sets the baudrate of AX12_UART for future use
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param baudrate [in] Specifies the baudrate at which the AX12_UART communicates
 */
uint8_t ax12_set_baudrate(uint8_t id, uint32_t baudrate);
/** \fn uint8_t ax12_set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit)
 * \brief Sets the angle limits for rotating both clockwise and counter clockwise
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 * @param cw_limit [in] Limits the maximum angle for clockwise rotation
 * @param ccw_limit [in] Limits the maximum angle for counter clockwise rotation
 *
 * If both angle limits are set to 0 AX12_UART is being used in wheel mode
 */
uint8_t ax12_set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit);
/** \fn uint8_t ax12_read_moving_status(uint8_t id)
 * \brief Read whether AX12_UART has finished moving
 *
 * @param id [in] Uniquely identifies the AX12_UART. Possible values are [0,254] If id is 254 the command is broadcasted to all AX12 servo motors
 */
uint8_t ax12_read_moving_status(uint8_t id);
/** \fn uint8_t ax12_read_response(void)
 * \brief Read response after sending a command to AX12
 */
uint8_t ax12_read_response(void);
#endif /* ifndef AX12_DRIVER */
