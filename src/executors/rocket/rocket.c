#include "rocket.h"

rocket_init(){

	analog_servo_move(SERVO_ROCKET, ROCKET_INIT_POSITION);
}

rocket_launch(){

	analog_servo_move(SERVO_ROCKET, ROCKET_LAUNCH_POSITION);
}


