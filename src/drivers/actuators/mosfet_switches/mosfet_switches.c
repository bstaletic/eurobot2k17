#include <drivers/actuators/mosfet_switches/mosfet_switches.h>

void mosfet_set(uint8_t id)
{
	switch(id){

		case 1:

			GPIO_SetBits(GPIOD, GPIO_PIN_3);
			break;

		case 2:

			GPIO_SetBits(GPIOD, GPIO_PIN_2);
			break;

		case 3:

			GPIO_SetBits(GPIOD, GPIO_PIN_1);
			break;

		case 4:

			GPIO_SetBits(GPIOD, GPIO_PIN_0);
			break;

		case 5:

			GPIO_SetBits(GPIOC, GPIO_PIN_11);
			break;

		case 6:

			GPIO_SetBits(GPIOC, GPIO_PIN_9);
			break;

		case 7:

			GPIO_SetBits(GPIOC, GPIO_PIN_8);
			break;

		case 8:

			GPIO_SetBits(GPIOC, GPIO_PIN_6);
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

			GPIO_ResetBits(GPIOD, GPIO_PIN_3);
			break;

		case 2:

			GPIO_ResetBits(GPIOD, GPIO_PIN_2);
			break;

		case 3:

			GPIO_ResetBits(GPIOD, GPIO_PIN_1);
			break;

		case 4:

			GPIO_ResetBits(GPIOD, GPIO_PIN_0);
			break;

		case 5:

			GPIO_ResetBits(GPIOC, GPIO_PIN_11);
			break;

		case 6:

			GPIO_ResetBits(GPIOC, GPIO_PIN_9);
			break;

		case 7:

			GPIO_ResetBits(GPIOC, GPIO_PIN_8);
			break;

		case 8:

			GPIO_ResetBits(GPIOC, GPIO_PIN_6);
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

			GPIO_ToggleBits(GPIOD, GPIO_PIN_3);
			break;

		case 2:

			GPIO_ToggleBits(GPIOD, GPIO_PIN_2);
			break;

		case 3:

			GPIO_ToggleBits(GPIOD, GPIO_PIN_1);
			break;

		case 4:

			GPIO_ToggleBits(GPIOD, GPIO_PIN_0);
			break;

		case 5:

			GPIO_ToggleBits(GPIOC, GPIO_PIN_11);
			break;

		case 6:

			GPIO_ToggleBits(GPIOC, GPIO_PIN_9);
			break;

		case 7:

			GPIO_ToggleBits(GPIOC, GPIO_PIN_8);
			break;

		case 8:

			GPIO_ToggleBits(GPIOC, GPIO_PIN_6);
			break;

		default:
			/* Error handling */
			;

	}

}
