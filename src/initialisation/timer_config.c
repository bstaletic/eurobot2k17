#include <initialisation/timer_config.h>

void timer1_config(void)
{
	timer_reset(TIM1);
	timer_set_prescaler(TIM1, 105);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	timer_enable_preload(TIM1);
	timer_continuous_mode(TIM1);
	timer_set_period(TIM1, 8000);
	/* Output compare mode: timer identifier, channel identifier == 1, mode == regular PWM */
	timer_disable_oc_output(TIM1, TIM_OC1);
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_value(TIM1, TIM_OC1, 4000);
	/* Enable PWM */
	timer_enable_oc_output(TIM1, TIM_OC1);
	timer_enable_break_main_output(TIM1);
	timer_enable_counter(TIM1);
}

void timer2_config(void)
{
	timer_reset(TIM2);
	timer_set_prescaler(TIM2, 105);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier == 2, channel identifier, mode == regular PWM */
	timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);
	timer_set_period(TIM2, 8000);
	timer_set_oc_value(TIM2, TIM_OC1, 4000);
	/* Enable PWM */
	timer_enable_oc_output(TIM2, TIM_OC1);
	timer_enable_counter(TIM2);
}

void timer3_config(void)
{
	timer_reset(TIM3);
	timer_set_prescaler(TIM3, 105);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 3, mode == regular PWM */
	timer_set_oc_mode(TIM3, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM3, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM3, TIM_OC1);
	timer_enable_oc_output(TIM3, TIM_OC2);
	timer_enable_break_main_output(TIM3);
	timer_set_period(TIM3, 8000);
	timer_set_oc_value(TIM3, TIM_OC1, 8000);
	timer_set_oc_value(TIM3, TIM_OC2, 8000);
	timer_enable_counter(TIM3);
}

void timer4_config(void)
{
	timer_reset(TIM4);
	timer_set_prescaler(TIM4, 105);
	/* Timer mode: timer identifier, clock division == 1, alignment, direction */
	timer_set_mode(TIM4, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 4, mode == regular PWM */
	timer_set_oc_mode(TIM4, TIM_OC2, TIM_OCM_PWM1);
	timer_set_period(TIM4, 8000);
	timer_set_oc_value(TIM4, TIM_OC2, 8000);
	/* Enable PWM */
	timer_enable_oc_output(TIM4, TIM_OC2);
	timer_enable_counter(TIM4);
}

void timer9_config(void)
{
	timer_reset(TIM9);
	timer_set_prescaler(TIM9, 105);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM9, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 9, mode == regular PWM */
	timer_set_oc_mode(TIM9, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM9, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_set_period(TIM9, 8000);
	timer_set_oc_value(TIM9, TIM_OC1, 8000);
	timer_set_oc_value(TIM9, TIM_OC2, 8000);
	timer_enable_oc_output(TIM9, TIM_OC1);
	timer_enable_oc_output(TIM9, TIM_OC2);
	//timer_enable_break_main_output(TIM9);
	timer_enable_counter(TIM9);
}

void timer10_config(void)
{
	timer_reset(TIM10);
	timer_set_prescaler(TIM10, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM10, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 10, mode == regular PWM */
	timer_set_oc_mode(TIM10, TIM_OC1, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_set_period(TIM10, 8399);
	timer_set_oc_value(TIM10, TIM_OC1, 8000);
	timer_enable_oc_output(TIM10, TIM_OC1);
	timer_enable_counter(TIM10);
}
