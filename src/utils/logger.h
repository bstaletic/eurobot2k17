#ifndef UTILS_LOGGER_H
#define UTILS_LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <libopencm3/stm32/usart.h>
#include <string.h>


#define LOGGER_BUFFER_SIZE 512


void print_header(void);

void error(const char* format, ...);
void debug(const char* format, ...);
void info(const char* format, ...);


#endif
