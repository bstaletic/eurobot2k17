#include "door.h"

///used for initializing function in task
void poke_init(void){
    ax12_move(SERVO_TOP, POKE_INIT_POSITION);
    ax12_move(SERVO_FRONT, POKE_INIT_POSITION);
}

///used to get module out of robot
void poke_module(uint8_t servo_id){

    if(servo_id == SERVO_TOP)
        ax12_move(servo_id, POKE_MODULE_POSITION_TOP);
    else
        ax12_move(servo_id, POKE_MODULE_POSITION_FRONT);
}

///used forused to initialize one servo to init position
void poke_return(uint8_t servo_id){
    ax12_move(servo_id, POKE_INIT_POSITION);
}
