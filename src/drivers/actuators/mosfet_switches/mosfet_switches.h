#ifndef MOSFET_SWITCH
#define MOSFET_SWITCH

#include <initialisation/gpio_config.h>

void switch_set(uint8_t id);
void switch_clear(uint8_t id);
void switch_toggle(uint8_t id);

#endif /* ifndef MOSFET_SWITCH */
