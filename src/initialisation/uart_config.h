#ifndef UART_CONFIG
#define UART_CONFIG

#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/common/usart_common_v2.h>
#include <libopencm3/cm3/nvic.h>


extern volatile uint16_t x_coordinate;
extern volatile uint16_t y_coordinate;
extern volatile uint16_t orientation;
extern volatile char status;

void usart2_config(void);
void usart3_config(void);
void uart4_config(void);

typedef enum { IDLE, STUCK, ROTATING, ERROR, MOVING } motion_status;

typedef struct {
	uint16_t x;
	uint16_t y;
	uint16_t orientation;
	motion_status status;
} motion_state;

extern volatile motion_state state;
#endif /* ifndef UART_CONFIG */
