#include "dropping_modules_side_notch.h"

task_t dropping_modules_side_notch;
task_arguments_t dropping_modules_side_notch_arguments;

void dropping_modules_side_notch_run(task_arguments_t* argv){
	debug("||**********|dropping_modules_side_notch run method|**********||");
	osDelay(1000);

    //after collect_rocket_modules_home task


    //go drop home modules on side notch
    set_motion_speed_cmd(50);
    goto_xy_cmd(215, 975, 1, 0);
    rotate_for_cmd(90);
    //move_forward_cmd(); //to modify dropping position

    //now dropping modules
    set_motion_speed_cmd(50);
    for(int8_t i = 0; i <= 3; i++){
        poke_module(SERVO_TOP);
        osDelay(2000); //delay to make sure module is out
        poke_return(SERVO_TOP);
        move_forward_cmd(-11);
        revolver_previous();
        osDelay(1000); //make sure revolver is in right position
    }

	argv->state = TASK_DONE;

}
void dropping_modules_side_notch_init(task_arguments_t* argv){
	debug("dropping_modules_side_notch_init");

	set_motion_speed_cmd(50);
    revolver_go_to_position(5); //make sure revolver is in position *5
    poke_init();
}
void dropping_modules_side_notch_finish(task_arguments_t* argv){
	debug("dropping_modules_side_notch_finish");
}

void dropping_modules_side_notch_calculate_priority(task_arguments_t* argv){
	debug("dropping_modules_side_notch_calc_pri");
}


void ctor_test_1(void){

	debug("test 1 ctor");

	dropping_modules_side_notch.run = (task_callback)&dropping_modules_side_notch_run;
	dropping_modules_side_notch.init = (task_callback)&dropping_modules_side_notch_init;
	dropping_modules_side_notch.finish = (task_callback)&dropping_modules_side_notch_finish;
	dropping_modules_side_notch.calculate_priority = (task_callback)&dropping_modules_side_notch_calculate_priority;
	strncpy(dropping_modules_side_notch.task_name,"Test Task 1\0",12);

	dropping_modules_side_notch_arguments.estimated_time = 50;
	dropping_modules_side_notch_arguments.priority = 100;
	dropping_modules_side_notch_arguments.state = TASK_READY;

	dropping_modules_side_notch.data = &dropping_modules_side_notch_arguments;

	add_task(&dropping_modules_side_notch);
}
