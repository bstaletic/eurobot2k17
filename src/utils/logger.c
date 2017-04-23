#include "logger.h"


typedef struct log_one_t {
	char text[LOGGER_BUFFER_ONE_LOG_SIZE];
	int size;
}log_one_t;

typedef struct log_all_t {
	log_one_t buffer[LOGGER_BUFFER_LOGS_SIZE];
	int size;
}log_all_t;

static log_all_t logs;

osMutexDef(rw_mutex_def);
osMutexId (rw_mutex);

void main_send_to_uart(void);
void main_error_light(void);

void print_header(void){

		logs.size++;
		logs.size++;
		logs.size++;
		logs.size++;

		strncpy(logs.buffer[logs.size].text,"\x1B[34m  ____________",19);
		logs.buffer[logs.size++].size = 19;
		strncpy(logs.buffer[logs.size].text," /_  __/ ____/",14);
		logs.buffer[logs.size++].size = 14;
		strncpy(logs.buffer[logs.size].text,"  / / / __/",13);
		logs.buffer[logs.size++].size = 13;
		strncpy(logs.buffer[logs.size].text," / / / /___",13);
		logs.buffer[logs.size++].size = 13;
		strncpy(logs.buffer[logs.size].text,"/_/ /_____/ Team Engage Novi Sad",32);
		logs.buffer[logs.size++].size = 32;
		strncpy(logs.buffer[logs.size].text,"            Eurobot 2017",24);
		logs.buffer[logs.size++].size = 24;

		logs.size++;
		logs.size++;
}

int error(const char* format, ...){
#ifdef LOGGER_ERROR
	va_list list;

	if (osMutexWait(rw_mutex,LOGGER_MUTEX_WAIT_MS) == osOK){

		va_start(list, format);

		logs.buffer[logs.size].size = vsnprintf(0, 0, format, list) + HEADER_ERROR_SIZE;

		vsprintf(logs.buffer[logs.size].text+HEADER_ERROR_SIZE, format, list);

		memcpy(logs.buffer[logs.size].text, HEADER_ERROR_TEXT, HEADER_ERROR_SIZE);

		logs.size++;

		va_end(list);

		osMutexRelease(rw_mutex);

		osThreadYield();

		return 0;
	}else{
		char error_mssg[35] = "ERROR LOGGER, CANT GET MUTEX!!!\n";
		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 32, 32);

		return -1;
	}
#endif
}

int debug(const char* format, ...){
#ifdef LOGGER_DEBUG
	va_list list;

	if (osMutexWait(rw_mutex,LOGGER_MUTEX_WAIT_MS) == osOK){

		va_start(list, format);

		logs.buffer[logs.size].size = vsnprintf(0, 0, format, list) + HEADER_DEBUG_SIZE;

		vsprintf(logs.buffer[logs.size].text+HEADER_DEBUG_SIZE, format, list);

		memcpy(logs.buffer[logs.size].text, HEADER_DEBUG_TEXT, HEADER_DEBUG_SIZE);

		logs.size++;

		va_end(list);

		osMutexRelease(rw_mutex);

		osThreadYield();

		return 0;
	}else{
		char error_mssg[35] = "ERROR LOGGER, CANT GET MUTEX!!!\n";
		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 32, 32);

		return -1;
	}
#endif
}

int info(const char* format, ...){
#ifdef LOGGER_INFO
	va_list list;

	if (osMutexWait(rw_mutex,LOGGER_MUTEX_WAIT_MS) == osOK){

		va_start(list, format);

		logs.buffer[logs.size].size = vsnprintf(0, 0, format, list) + HEADER_INFO_SIZE;

		vsprintf(logs.buffer[logs.size].text+HEADER_INFO_SIZE, format, list);

		memcpy(logs.buffer[logs.size].text, HEADER_INFO_TEXT, HEADER_INFO_SIZE);

		logs.size++;

		va_end(list);

		osMutexRelease(rw_mutex);

		osThreadYield();

		return 0;
	}else{
		char error_mssg[35] = "ERROR LOGGER, CANT GET MUTEX!!!\n";
		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 32, 32);

		return -1;
	}
#endif
}

void logger_main(void){

	if (osMutexWait(rw_mutex,LOGGER_MUTEX_WAIT_MS) == osOK){

		for(int i = 0; i < logs.size; i++){
			int s = logs.buffer[i].size++;
			logs.buffer[i].text[s++] = '\n';
			HAL_UART_Transmit(&LOGGER_UART_PORT, (unsigned char *)logs.buffer[i].text, s, s);
		}

		logs.size = 0;

		osMutexRelease(rw_mutex);

		osThreadYield();
	}else{
		char error_mssg[35] = "ERROR LOGGER, CANT GET MUTEX!!!\n";
		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 32, 1);
	}

}

void logger_ctor(void){

	rw_mutex = osMutexCreate(osMutex(rw_mutex_def));

	if(rw_mutex == NULL){
		char error_mssg[35] = "ERROR LOGGER, CANT CREATE MUTEX!!!\n";
		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 35, 32);
	}else{
		//		char error_mssg[50] = "MUTEX CREATED\n";
		//		HAL_UART_Transmit(&huart3, (unsigned char *)error_mssg, 20, 1);
	}

	logs.size = 0;
	print_header();
}

void main_send_to_uart(void){

}

void main_error_light(void){

}
