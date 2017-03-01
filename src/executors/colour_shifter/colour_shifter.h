#ifndef COLOUR_SHIFTER
#define COLOUR_SHIFTER

#include "drivers/sensors/colour/colour.h"
#include "drivers/actuators/ax12/ax12.h"

#define COLOUR_SHIFTER_ID 5

/**
 * \brief Rotates the cilinder until the correct colour is found
 *
 * \param [in] colour BLUE or YELLOW, depending on the colour of the team
 *
 * The sensor is placed on the outside of the revolver
 * so it needs to find the opposite colour of the team's colour.
 * That way, when the sensor detects the appropriate colour
 * and the revolver moves it down to throw it out
 * at the top of the cilinder is the same colour as the team's colour.
 *
 */
void colour_shift(colour_enum_t colour);

#endif /* ifndef COLOUR_SHIFTER */
