#ifndef COLOUR_SENSOR
#define COLOUR_SENSOR

#include <initialisation/timer_config.h>

typedef enum { BLUE, YELLOW, WHITE, ERROR } colour_enum_t;

colour_enum_t read_colour(void);

#endif /* ifndef COLOUR_SENSOR */
