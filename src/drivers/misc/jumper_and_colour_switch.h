#ifndef JUMPER_AND_COLOUR_SWITCH
#define JUMPER_AND_COLOUR_SWITCH

#include <stm32f4xx_it.h>
#include "gpio.h"
#include "../drivers/sensors/colour/colour.h"

extern volatile uint8_t jumper;
extern volatile colour_enum_t colour_switch;


void EXTI15_10_IRQHandler(void);

#endif /* ifndef JUMPER_AND_COLOUR_SWITCH */
