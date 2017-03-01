#include "colour_shifter.h"

void colour_shift(colour_enum_t colour)
{
	if (colour == BLUE)
	{
		while (read_colour() != YELLOW)
		{
			ax12_set_speed(COLOUR_SHIFTER_ID, 100);
		}
	}
	else if (colour == YELLOW)
	{
		while (read_colour() != BLUE)
		{
			ax12_set_speed(COLOUR_SHIFTER_ID, 100);
		}
	}
}
