#ifndef UART_CONFIG
#define UART_CONFIG

#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/common/usart_common_v2.h>

static void usart2_config(void);
static void usart3_config(void);
static void uart4_config(void);

static void usart_clock_config(void);

#endif /* ifndef UART_CONFIG */
