#include "rocket.h"

void rocket_init(void){

	analog_servo_move(SERVO_ROCKET, ROCKET_INIT_POSITION);
}

void rocket_launch(void){

	analog_servo_move(SERVO_ROCKET, ROCKET_LAUNCH_POSITION);
}


