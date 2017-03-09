#include "trunk.h"

void trunk_init(void)
{
	analog_servo servo;
//	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	analog_servo_move(servo, CLOSE_TRUNK_VALUE);

//	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	analog_servo_move(servo, REDUCE_TRUNK_VALUE);
}

void trunk_open(void)
{
	analog_servo servo;
//	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	analog_servo_move(servo, OPEN_TRUNK_VALUE);
}

void trunk_close(void)
{
	analog_servo servo;
//	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	analog_servo_move(servo, CLOSE_TRUNK_VALUE);
}

void trunk_increase(void)
{
	analog_servo servo;
//	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	analog_servo_move(servo, INCREASE_TRUNK_VALUE);
}

void trunk_reduce(void)
{
	analog_servo servo;
//	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	analog_servo_move(servo, REDUCE_TRUNK_VALUE);
}
