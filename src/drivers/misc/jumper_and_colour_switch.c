#include "jumper_and_colour_switch.h"

volatile uint8_t jumper = 1;
volatile colour_enum_t colour_switch;
volatile uint8_t check_colour = 1;

/**
* @brief This function handles EXTI line[15:10] interrupts.
*/
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
  //colour_switch = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)? 1: 0;
  colour_switch = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11);
  jumper = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13)? 1: 0;
  check_colour = 0;
  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}
