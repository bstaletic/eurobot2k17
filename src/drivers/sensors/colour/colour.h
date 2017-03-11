#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include <stdint.h>
#include <usart.h>
#include <stm32f4xx_it.h>

#include "tim.h"
#include "../../actuators/mosfet_switches/mosfet_switches.h"

typedef enum { BLUE, YELLOW, WHITE, UNKNOWN } colour_enum_t;

// Reading the sensor with blue LED selected
#define BLUE_CHANNEL_BLUE_RANGE_START 7625 // Minimum frequency when reading blue colour
#define BLUE_CHANNEL_BLUE_RANGE_END 15708 // Maximum frequency when reading blue colour
#define BLUE_CHANNEL_WHITE_RANGE_START 500 // Minimum frequency when reading white colour
#define BLUE_CHANNEL_WHITE_RANGE_END 500 // Maximum frequency when reading white colour
#define BLUE_CHANNEL_YELLOW_RANGE_START 500 // Minimum frequency when reading yellow colour
#define BLUE_CHANNEL_YELLOW_RANGE_END 500 // Maximum frequency when reading yellow colour

// Reading the sensor with green LED selected
#define GREEN_CHANNEL_BLUE_RANGE_START 2750
#define GREEN_CHANNEL_BLUE_RANGE_END 8041
#define GREEN_CHANNEL_WHITE_RANGE_START 400
#define GREEN_CHANNEL_WHITE_RANGE_END 400
#define GREEN_CHANNEL_YELLOW_RANGE_START 400
#define GREEN_CHANNEL_YELLOW_RANGE_END 400

// Reading the sensor with red LED selected
#define RED_CHANNEL_BLUE_RANGE_START 0
#define RED_CHANNEL_BLUE_RANGE_END 1122
#define RED_CHANNEL_WHITE_RANGE_START 400
#define RED_CHANNEL_WHITE_RANGE_END 500
#define RED_CHANNEL_YELLOW_RANGE_START 400
#define RED_CHANNEL_YELLOW_RANGE_END 500

/**
 * \fn colour_enum_t read_colour(void)
 * \brief Reads sensor and returns the approrpriate colour
 *
 * Returns BLUE, YELLOW, WHITE or UNKNOWN
 */
colour_enum_t read_colour(void);
void TIM6_DAC_IRQHandler(void);

#endif /* ifndef COLOUR_SENSOR */
