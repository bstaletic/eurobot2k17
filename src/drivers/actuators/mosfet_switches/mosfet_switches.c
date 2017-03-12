#include "mosfet_switches.h"

void mosfet_set(uint8_t id)
{
	switch(id){

		case 1:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
			break;

		case 2:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			break;

		case 3:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
			break;

		case 4:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
			break;

		case 5:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
			break;

		case 6:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
			break;

		case 7:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			break;

		case 8:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
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

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
			break;

		case 2:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			break;

		case 3:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
			break;

		case 4:

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
			break;

		case 5:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);
			break;

		case 6:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
			break;

		case 7:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
			break;

		case 8:

			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
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

			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_3);
			break;

		case 2:

			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
			break;

		case 3:

			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_1);
			break;

		case 4:

			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_0);
			break;

		case 5:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_11);
			break;

		case 6:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			break;

		case 7:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
			break;

		case 8:

			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_6);
			break;

		default:
			/* Error handling */
			;

	}

}
