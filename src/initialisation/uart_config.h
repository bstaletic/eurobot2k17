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

#endif /* ifndef UART_CONFIG */
