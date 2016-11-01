#ifndef AX12_DRIVER
#define AX12_DRIVER

#include <libopencm3/stm32/usart.h>

#define AX12 UART4

#define GOAL_LENGTH 5
#define GOAL_SP_LENGTH 7
#define GOAL_SPEED_LENGTH 5
#define RESET_LENGTH 2
#define ID_LENGTH 4
#define RESET_LENGTH 2
#define BAUDRATE_LENGTH 4

#define START 255
#define GOAL_POSITION_L 30
#define RESET 6
#define ID 3
#define BAUDRATE 4

#define WRITE_DATA 3

void move(int8_t id, int16_t position);
void move_speed(int8_t id, int16_t position, int16_t speed);
void set_speed(int8_t id, int16_t speed);
void factory_reset(int8_t id);
void set_id(int8_t id, int8_t new_id);
void set_baudrate(int8_t id, int32_t baudrate);

#endif /* ifndef AX12_DRIVER */
