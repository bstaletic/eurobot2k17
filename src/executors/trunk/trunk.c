#include <drivers/actuators/analog_servo/analog_servo.h>

void open_trunk(void)
{
	analog_servo servo;
	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	servo.value = OPEN_TRUNK_VALUE;
}

void close_trunk(void)
{
	analog_servo servo;
	servo.channel = OPEN_TRUNK_TIMER_CHANNEL;
	servo.timer = OPEN_TRUNK_TIMER;
	servo.value = CLOSE_TRUNK_VALUE;
}

void increase_trunk(void)
{
	analog_servo servo;
	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	servo.value = INCREASE_TRUNK_VALUE;
}

void increase_trunk(void)
{
	analog_servo servo;
	servo.channel = INCREASE_TRUNK_TIMER_CHANNEL;
	servo.timer = INCREASE_TRUNK_TIMER;
	servo.value = REDUCE_TRUNK_VALUE;
}
