#ifndef UART_CONFIG
#define UART_CONFIG

#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/common/usart_common_v2.h>
#include <libopencm3/cm3/nvic.h>

void usart2_config(void);
void usart3_config(void);
void uart4_config(void);

#endif /* ifndef UART_CONFIG */
