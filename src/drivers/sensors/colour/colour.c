#include <drivers/sensors/colour/colour.h>

colour_enum_t read_colour(void)
{
	colour_enum_t colour;
	if (colour_sensor_frequency >= WHITE_RANGE_START &&
             colour_sensor_frequency <= WHITE_RANGE_END)
		colour = WHITE;
	else if (colour_sensor_frequency >= WHITE_RANGE_START &&
             colour_sensor_frequency <= WHITE_RANGE_END)
		colour = YELLOW;
	else if (colour_sensor_frequency >= BLUE_RANGE_START &&
             colour_sensor_frequency <= BLUE_RANGE_END)
		colour = BLUE;
	else
		colour = UNKNOWN;

	return colour;
}
