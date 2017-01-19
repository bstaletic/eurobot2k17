#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include <initialisation/timer_config.h>

typedef enum { BLUE, YELLOW, WHITE, ERROR } colour_enum_t;

/**
 * \fn colour_enum_t read_colour(void)
 * \brief Reads sensor and returns the approrpriate colour
 *
 * Returns BLUE, YELLOW, WHITE or ERROR
 */
colour_enum_t read_colour(void);

#endif /* ifndef COLOUR_SENSOR */
