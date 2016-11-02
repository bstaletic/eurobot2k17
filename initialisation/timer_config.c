#include "timer_config.h"

void tim1_config(void)
{
	timer_reset(TIM1);
	timer_set_prescaler(TIM1, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 1, mode == regular PWM */
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM1, TIM_OC1);
	timer_enable_break_main_output(TIM1);
	timer_enable_counter(TIM1);
}

void tim2_config(void)
{
	timer_reset(TIM2);
	timer_set_prescaler(TIM2, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier == 2, channel identifier, mode == regular PWM */
	timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM2, TIM_OC1);
	timer_enable_break_main_output(TIM2);
	timer_enable_counter(TIM2);
}

void tim3_config(void)
{
	timer_reset(TIM3);
	timer_set_prescaler(TIM3, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 3, mode == regular PWM */
	timer_set_oc_mode(TIM3, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM3, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM3, TIM_OC1);
	timer_enable_oc_output(TIM3, TIM_OC2);
	timer_enable_break_main_output(TIM3);
	timer_enable_counter(TIM3);
}

void tim4_config(void)
{
	timer_reset(TIM4);
	timer_set_prescaler(TIM4, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM4, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 4, mode == regular PWM */
	timer_set_oc_mode(TIM4, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM4, TIM_OC2);
	timer_enable_break_main_output(TIM4);
	timer_enable_counter(TIM4);
}

void tim9_config(void)
{
	timer_reset(TIM9);
	timer_set_prescaler(TIM9, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM9, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 9, mode == regular PWM */
	timer_set_oc_mode(TIM9, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM9, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM9, TIM_OC1);
	timer_enable_oc_output(TIM9, TIM_OC2);
	timer_enable_break_main_output(TIM9);
	timer_enable_counter(TIM9);
}

void tim10_config(void)
{
	timer_reset(TIM10);
	timer_set_prescaler(TIM10, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM10, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 10, mode == regular PWM */
	timer_set_oc_mode(TIM10, TIM_OC1, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM10, TIM_OC1);
	timer_enable_break_main_output(TIM10);
	timer_enable_counter(TIM10);
}
