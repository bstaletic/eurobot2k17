#include "logger.h"


char logger_buffer[] = {[0 ... (LOGGER_BUFFER_SIZE-1)] = '\0'};
char logger_buffer_tmp[] = {[0 ... (LOGGER_BUFFER_SIZE-1)] = '\0'};
int logger_buffer_couter = 0;

static const char header_debug[] = { " [D] "};
static const char header_info[] = {" [info] "};
static const char header_error[] = {" [ERROR] "};
static const int header_debug_size = 5;
static const int header_info_size = 8;
static const int header_error_size = 9;


void clean_buffer(int _clean_size);
void send_buffer_to_uart(int _buff_lenght);

void print_header(void){
	send_buffer_to_uart(1);
	send_buffer_to_uart(1);
	send_buffer_to_uart(1);
	send_buffer_to_uart(1);

	strncpy(logger_buffer,"  ____________",14);
	send_buffer_to_uart(14);
	strncpy(logger_buffer," /_  __/ ____/",14);
	send_buffer_to_uart(14);
	strncpy(logger_buffer,"  / / / __/",11);
	send_buffer_to_uart(13);
	strncpy(logger_buffer," / / / /___",11);
	send_buffer_to_uart(12);
	strncpy(logger_buffer,"/_/ /_____/ Team Engage Novi Sad",32);
	send_buffer_to_uart(32);
	strncpy(logger_buffer,"            Eurobot 2017",24);
	send_buffer_to_uart(24);

	send_buffer_to_uart(1);
}



void error(const char* format, ...){
	va_list list;
	int buffer_size;

	va_start(list, format);
	buffer_size = vsnprintf(0, 0, format, list);
	vsprintf(logger_buffer+header_error_size, format, list);

	memcpy(logger_buffer,header_error,header_error_size);

	send_buffer_to_uart(header_error_size+buffer_size);
	va_end(list);
}

void debug(const char* format, ...){
	va_list list;
	int buffer_size;

	va_start(list, format);
	buffer_size = vsnprintf(0, 0, format, list);

	vsprintf(logger_buffer+header_debug_size, format, list);

	memcpy(logger_buffer,header_debug,header_debug_size);

	send_buffer_to_uart(buffer_size+header_debug_size);
	va_end(list);
}

void info(const char* format, ...){
	va_list list;
	int buffer_size;

	va_start(list, format);
	buffer_size = vsnprintf(0, 0, format, list);
	vsprintf(logger_buffer+header_info_size, format, list);

	memcpy(logger_buffer,header_info,header_info_size);

	send_buffer_to_uart(buffer_size+header_info_size);
	va_end(list);
}


void clean_buffer(int _clean_size){
	for (int i = 0; i < _clean_size+1; i++)
		logger_buffer[i] = '\0';
}


void send_buffer_to_uart(int _buff_lenght){
	logger_buffer[++_buff_lenght] = '\n';
	for(int i = 0; i <= _buff_lenght; i++){
//		usart_send_blocking(USART3,logger_buffer[i]);
	}
	clean_buffer(_buff_lenght);
}
