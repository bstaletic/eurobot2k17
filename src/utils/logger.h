#ifndef UTILS_LOGGER_H
#define UTILS_LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <usart.h>
#include <string.h>
#include "cmsis_os.h"

#define LOGGER_BUFFER_LOGS_SIZE 200 ///< size of "string" buffer
#define LOGGER_BUFFER_ONE_LOG_SIZE 512 ///< size of one log "string"

#define LOGGER_ERROR ///< if LOGGER_ERROR is defined logger will log error logs (log = send data to debug UART port)
#define LOGGER_INFO  ///< if LOGGER_ERROR is defined logger will log info logs (log = send data to debug UART port)
#define LOGGER_DEBUG ///< if LOGGER_ERROR is defined logger will log debug logs (log = send data to debug UART port)
#define LOGGER_UART_PORT huart3 ///< UART port for logging
#define LOGGER_MUTEX_WAIT_MS 5 ///< wait time of read write mutex to logs

#define HEADER_DEBUG_TEXT "\x1B[0m [D] "
#define HEADER_DEBUG_SIZE 9
#define HEADER_INFO_TEXT "\x1B[32m [info]\x1B[0m "
#define HEADER_INFO_SIZE 17
#define HEADER_ERROR_TEXT "\x1B[31m [ERROR] "
#define HEADER_ERROR_SIZE 14

/**
 * @brief print team info on debug UART. Not thread safe
* @return -1 if log was unsuccessfully otherwise 0
 */
void print_header(void);

/**
 * @brief print error message on debug UART. Thread safe function
 * @return -1 if log was unsuccessfully otherwise 0
 */
int error(const char* format, ...);

/**
 * @brief print debug message on debug UART. Thread safe function
 * @return -1 if log was unsuccessfully otherwise 0
 */
int debug(const char* format, ...);

/**
 * @brief print info message on debug UART. Thread safe function
 * @return -1 if log was unsuccessfully oterhwise 0
 */
int info(const char* format, ...);


/**
 * @brief logger main function that should be run in one thread. It sends data got from all threads
 */
void logger_main(void);

/**
 * @brief logger constructor. Constructor has to be called before thread creation.
 */
void logger_ctor(void);


#endif //UTILS_LOGGER_H
