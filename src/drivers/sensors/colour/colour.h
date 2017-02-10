#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include "../../../initialisation/timer_config.h"

typedef enum { BLUE, YELLOW, WHITE, UNKNOWN } colour_enum_t;

#define BLUE_RANGE_START 0
#define BLUE_RANGE_END 100

#define YELLOW_RANGE_START 200
#define YELLOW_RANGE_END 300

#define WHITE_RANGE_START 400
#define WHITE_RANGE_END 500

/**
 * \fn colour_enum_t read_colour(void)
 * \brief Reads sensor and returns the approrpriate colour
 *
 * Returns BLUE, YELLOW, WHITE or UNKNOWN
 */
colour_enum_t read_colour(void);

#endif /* ifndef COLOUR_SENSOR */
