#include "colour_shifter.h"

void colour_shift(void)
{
	while (read_colour() != colour_switch)
		ax12_set_speed(COLOUR_SHIFTER_ID, 100);
	ax12_set_speed(COLOUR_SHIFTER_ID, 0);
}
