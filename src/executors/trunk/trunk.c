#include <executors/trunk/trunk.h>

void open_trunk(void)
{
	analog_servo servo;
	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	analog_servo_move(servo, OPEN_TRUNK_VALUE);
}

void close_trunk(void)
{
	analog_servo servo;
	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	analog_servo_move(servo, CLOSE_TRUNK_VALUE);
}

void increase_trunk(void)
{
	analog_servo servo;
	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	analog_servo_move(servo, INCREASE_TRUNK_VALUE);
}

void reduce_trunk(void)
{
	analog_servo servo;
	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	analog_servo_move(servo, REDUCE_TRUNK_VALUE);
}
