#ifndef MOSFET_SWITCH
#define MOSFET_SWITCH

#include <stm32f4xx_hal_gpio.h>

void mosfet_set(uint8_t id);
void mosfet_clear(uint8_t id);
void mosfet_toggle(uint8_t id);

#endif /* ifndef MOSFET_SWITCH */
