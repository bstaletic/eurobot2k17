#include "timer_utils.h"

void set_pwm(uint8_t tim, uint32_t channel, int16_t pwm_value)
{
	TIM_OC_InitTypeDef channel_pwm_config;
	channel_pwm_config.OCMode = TIM_OCMODE_PWM1;
	channel_pwm_config.OCPolarity = TIM_OCPOLARITY_LOW;
	channel_pwm_config.Pulse = pwm_value;
	channel_pwm_config.OCFastMode = TIM_OCFAST_DISABLE;
	channel_pwm_config.OCIdleState = TIM_OCIDLESTATE_RESET;
	channel_pwm_config.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	switch (tim) {
		case 1:
			HAL_TIM_PWM_ConfigChannel(&htim1, &channel_pwm_config, channel);
			break;
		case 2:
			HAL_TIM_PWM_ConfigChannel(&htim1, &channel_pwm_config, channel);
			break;
		case 3:
			HAL_TIM_PWM_ConfigChannel(&htim1, &channel_pwm_config, channel);
			break;
		case 4:
			HAL_TIM_PWM_ConfigChannel(&htim1, &channel_pwm_config, channel);
			break;
		case 9:
			HAL_TIM_PWM_ConfigChannel(&htim1, &channel_pwm_config, channel);
			break;
	}
}
