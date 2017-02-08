#ifndef MOSFET_SWITCH
#define MOSFET_SWITCH

#include <initialisation/gpio_config.h>

void mosfet_set(uint8_t id);
void mosfet_clear(uint8_t id);
void mosfet_toggle(uint8_t id);

#endif /* ifndef MOSFET_SWITCH */
