/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define TIM9_CH1___Door_poke_servo_Pin GPIO_PIN_5
#define TIM9_CH1___Door_poke_servo_GPIO_Port GPIOE
#define TIM9_CH2___Door_servo_Pin GPIO_PIN_6
#define TIM9_CH2___Door_servo_GPIO_Port GPIOE
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define UART4_TX_Pin GPIO_PIN_0
#define UART4_TX_GPIO_Port GPIOA
#define UART4_RX_Pin GPIO_PIN_1
#define UART4_RX_GPIO_Port GPIOA
#define USART2_TX_Pin GPIO_PIN_2
#define USART2_TX_GPIO_Port GPIOA
#define CLK_IN_Pin GPIO_PIN_10
#define CLK_IN_GPIO_Port GPIOB
#define USART3_RX_Pin GPIO_PIN_11
#define USART3_RX_GPIO_Port GPIOB
#define TIM12_CH12_Pin GPIO_PIN_15
#define TIM12_CH12_GPIO_Port GPIOB
#define USART3_TX_Pin GPIO_PIN_8
#define USART3_TX_GPIO_Port GPIOD
#define LD4_Pin GPIO_PIN_12
#define LD4_GPIO_Port GPIOD
#define LD3_Pin GPIO_PIN_13
#define LD3_GPIO_Port GPIOD
#define LD5_Pin GPIO_PIN_14
#define LD5_GPIO_Port GPIOD
#define LD6_Pin GPIO_PIN_15
#define LD6_GPIO_Port GPIOD
#define MOSFET_08_Pin GPIO_PIN_6
#define MOSFET_08_GPIO_Port GPIOC
#define MOSFET_07_Pin GPIO_PIN_8
#define MOSFET_07_GPIO_Port GPIOC
#define MOSFET_06_Pin GPIO_PIN_9
#define MOSFET_06_GPIO_Port GPIOC
#define TIM1_CH1_Pin GPIO_PIN_8
#define TIM1_CH1_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define TIM2_CH1_Pin GPIO_PIN_15
#define TIM2_CH1_GPIO_Port GPIOA
#define MOSFET_05_Pin GPIO_PIN_11
#define MOSFET_05_GPIO_Port GPIOC
#define MOSFET_04_Pin GPIO_PIN_0
#define MOSFET_04_GPIO_Port GPIOD
#define MOSFET_03_Pin GPIO_PIN_1
#define MOSFET_03_GPIO_Port GPIOD
#define MOSFET_02_Pin GPIO_PIN_2
#define MOSFET_02_GPIO_Port GPIOD
#define MOSFET_01_Pin GPIO_PIN_3
#define MOSFET_01_GPIO_Port GPIOD
#define Audio_RST_Pin GPIO_PIN_4
#define Audio_RST_GPIO_Port GPIOD
#define OTG_FS_OverCurrent_Pin GPIO_PIN_5
#define OTG_FS_OverCurrent_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define TIM3_CH1_Pin GPIO_PIN_4
#define TIM3_CH1_GPIO_Port GPIOB
#define TIM3_CH2_Pin GPIO_PIN_5
#define TIM3_CH2_GPIO_Port GPIOB
#define TIM4_CH2_Pin GPIO_PIN_7
#define TIM4_CH2_GPIO_Port GPIOB
#define TIM10_CH1_Pin GPIO_PIN_8
#define TIM10_CH1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
