#include "rocket.h"

void rocket_init(void){

	ax12_move(SERVO_ROCKET, ROCKET_INIT_POSITION);
}

void rocket_launch(void){

	ax12_move(SERVO_ROCKET, ROCKET_LAUNCH_POSITION);
}


