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

void move(uint8_t id, uint16_t position);
void move_speed(uint8_t id, uint16_t position, uint16_t speed);
void set_speed(uint8_t id, uint16_t speed);
void factory_reset(uint8_t id);
void set_id(uint8_t id, uint8_t new_id);
void set_baudrate(uint8_t id, uint32_t baudrate);
void set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit);

#endif /* ifndef AX12_DRIVER */
