#include <drivers/actuators/mosfet_switches/mosfet_switches.h>

void mosfet_set(uint8_t id)
{
	switch(id){

		case 1:

			gpio_set(GPIOD, GPIO3);
			break;

		case 2:

			gpio_set(GPIOD, GPIO2);
			break;

		case 3:

			gpio_set(GPIOD, GPIO1);
			break;

		case 4:

			gpio_set(GPIOD, GPIO0);
			break;

		case 5:

			gpio_set(GPIOC, GPIO11);
			break;

		case 6:

			gpio_set(GPIOC, GPIO9);
			break;

		case 7:

			gpio_set(GPIOC, GPIO8);
			break;

		case 8:

			gpio_set(GPIOC, GPIO6);
			break;

		default:
			/* Error handling */
			;

	}
	
}

void mosfet_clear(uint8_t id)
{
	switch(id){

		case 1:

			gpio_clear(GPIOD, GPIO3);
			break;

		case 2:

			gpio_clear(GPIOD, GPIO2);
			break;

		case 3:

			gpio_clear(GPIOD, GPIO1);
			break;

		case 4:

			gpio_clear(GPIOD, GPIO0);
			break;

		case 5:

			gpio_clear(GPIOC, GPIO11);
			break;

		case 6:

			gpio_clear(GPIOC, GPIO9);
			break;

		case 7:

			gpio_clear(GPIOC, GPIO8);
			break;

		case 8:

			gpio_clear(GPIOC, GPIO6);
			break;

		default:
			/* Error handling */
			;
			
	}
	
}

void mosfet_toggle(uint8_t id)
{
	switch(id){

		case 1:

			gpio_toggle(GPIOD, GPIO3);
			break;

		case 2:

			gpio_toggle(GPIOD, GPIO2);
			break;

		case 3:

			gpio_toggle(GPIOD, GPIO1);
			break;

		case 4:

			gpio_toggle(GPIOD, GPIO0);
			break;

		case 5:

			gpio_toggle(GPIOC, GPIO11);
			break;

		case 6:

			gpio_toggle(GPIOC, GPIO9);
			break;

		case 7:

			gpio_toggle(GPIOC, GPIO8);
			break;

		case 8:

			gpio_toggle(GPIOC, GPIO6);
			break;

		default:
			/* Error handling */
			;
			
	}
	
}
