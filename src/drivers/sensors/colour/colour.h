#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include <stdint.h>
#include <libopencm3/stm32/gpio.h>

#include "../../../initialisation/timer_config.h"

typedef enum { BLUE, YELLOW, WHITE, UNKNOWN } colour_enum_t;
typedef enum { RED_CHANNEL, GREEN_CHANNEL, BLUE_CHANNEL } colour_channel_enum_t;

#define BLUE_CHANNEL_BLUE_RANGE_START 7625
#define BLUE_CHANNEL_BLUE_RANGE_END 15708
#define BLUE_CHANNEL_WHITE_RANGE_START 500
#define BLUE_CHANNEL_WHITE_RANGE_END 500
#define BLUE_CHANNEL_YELLOW_RANGE_START 500
#define BLUE_CHANNEL_YELLOW_RANGE_END 500

#define GREEN_CHANNEL_BLUE_RANGE_START 2750
#define GREEN_CHANNEL_BLUE_RANGE_END 8041
#define GREEN_CHANNEL_WHITE_RANGE_START 400
#define GREEN_CHANNEL_WHITE_RANGE_END 400
#define GREEN_CHANNEL_YELLOW_RANGE_START 400
#define GREEN_CHANNEL_YELLOW_RANGE_END 400

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

#endif /* ifndef COLOUR_SENSOR */
