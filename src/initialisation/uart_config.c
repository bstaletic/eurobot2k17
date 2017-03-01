#include <initialisation/uart_config.h>

volatile uint16_t x_coordinate;
volatile uint16_t y_coordinate;
volatile uint16_t orientation;
volatile char status;
volatile motion_state state;

void usart2_config(void)
{
	/* Setup USART2 parameters. */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	// TODO: Find out why doesn't the libopencm3 function work
	USART_CR3(USART2) |= USART_CR3_HDSEL;
	//usart_enable_halfduplex(USART2);
	// Oversampling

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void usart3_config(void)
{
	/* Setup USART3 parameters. */
	usart_set_baudrate(USART3, 115200);
	usart_set_databits(USART3, 8);
	usart_set_stopbits(USART3, USART_STOPBITS_1);
	usart_set_mode(USART3, USART_MODE_TX_RX);
	usart_set_parity(USART3, USART_PARITY_NONE);
	usart_set_flow_control(USART3, USART_FLOWCONTROL_NONE);
	// Oversampling

	/* Finally enable the USART. */
	usart_enable(USART3);
}

void uart4_config(void)
{
	/* Setup UART4 parameters. */
	usart_set_baudrate(UART4, 57600);
	usart_set_databits(UART4, 8);
	usart_set_stopbits(UART4, USART_STOPBITS_1);
	usart_set_mode(UART4, USART_MODE_TX_RX);
	usart_set_parity(UART4, USART_PARITY_NONE);
	usart_set_flow_control(UART4, USART_FLOWCONTROL_NONE);
	// Oversampling

	nvic_enable_irq(NVIC_UART4_IRQ);
	usart_enable_rx_interrupt(UART4);
	/* Finally enable the USART. */
	usart_enable(UART4);
}


void uart4_isr(void)
{
	if ((UART4_CR1 & USART_CR1_RXNEIE) && (UART4_SR & USART_SR_RXNE)) {




		/* Special char X for defining polling status and position message,
		this message is to be recieved every 10 ms */
		if (usart_recv_blocking(UART4)=='X'){

			state.status = usart_recv_blocking(UART4);
			state.x = (usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);
			state.y = (usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);
			state.orientation = ( usart_recv_blocking(UART4) << 8 ) | (usart_recv_blocking(UART4) & 0xff);
		}

		/* Clear the RXNE flag */
		UART4_SR &= ~USART_SR_RXNE;

	}
}
