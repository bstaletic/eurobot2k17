#include <drivers/sensors/colour/colour.h>

colour_enum_t read_colour(void)
{
	int32_t sensor_value_raw = timer_get_counter(COLOUR_SENSOR_TIMER);
	colour_enum_t colour;
	if (sensor_value_raw >= WHITE_RANGE_START &&
             sensor_value_raw <= WHITE_RANGE_END)
		colour = WHITE;
	else if (sensor_value_raw >= WHITE_RANGE_START &&
             sensor_value_raw <= WHITE_RANGE_END)
		colour = YELLOW;
	else if (sensor_value_raw >= BLUE_RANGE_START &&
             sensor_value_raw <= BLUE_RANGE_END)
		colour = BLUE;
	else
		colour = UNKNOWN;

	return colour;
}
