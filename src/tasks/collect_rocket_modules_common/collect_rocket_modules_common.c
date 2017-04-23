#include "collect_rocket_modules_common.h"

task_t collect_rocket_modules_common;
task_arguments_t collect_rocket_modules_common_arguments;

void collect_rocket_modules_common_run(task_arguments_t* argv){
	debug("||**********|collect_rocket_modules_common run method|**********||");
	osDelay(1000);

    //after dropping_modules_side_notch task
    //collecting modules from other rocket
    set_motion_speed_cmd(50);
    goto_xy_cmd(1000, 300, 1, 0);
    goto_xy_cmd(1350, 265, 1, 0); //you are now aprox. where you should be to stick it to rocket (dont be perv pls)

    //collecting modules
    set_motion_speed_cmd(50);
    for(int8_t i = 0; i <= 3; i++){
		move_forward_cmd(50);
		osDelay(250);
		if(i <= 2) //for the last module robot needs to stay
			move_forward_cmd(-50);
		osDelay(1000); //making sure tube is on revolver
		revolver_next();
        osDelay(1000); //make sure revolver is in right position
	} //modules should be collected and revolver postion should be 6

	argv->state = TASK_DONE;

}
void collect_rocket_modules_common_init(task_arguments_t* argv){
	debug("collect_rocket_modules_common_init");
    //it probably will be in postion one, but make sure it is
    revolver_go_to_position(1); //if you dont know why position one...think about it
    poke_init();
}
void collect_rocket_modules_common_finish(task_arguments_t* argv){
	debug("collect_rocket_modules_common_finish");

    set_motion_speed_cmd(50);
    move_forward_cmd(-100); //back away slowly from the rocket
}

void collect_rocket_modules_common_calculate_priority(task_arguments_t* argv){
	debug("collect_rocket_modules_common_calc_pri");
}


void ctor_test_1(void){

	debug("test 1 ctor");

	collect_rocket_modules_common.run = (task_callback)&collect_rocket_modules_common_run;
	collect_rocket_modules_common.init = (task_callback)&collect_rocket_modules_common_init;
	collect_rocket_modules_common.finish = (task_callback)&collect_rocket_modules_common_finish;
	collect_rocket_modules_common.calculate_priority = (task_callback)&collect_rocket_modules_common_calculate_priority;
	strncpy(collect_rocket_modules_common.task_name,"Test Task 1\0",12);

	collect_rocket_modules_common_arguments.estimated_time = 50;
	collect_rocket_modules_common_arguments.priority = 100;
	collect_rocket_modules_common_arguments.state = TASK_READY;

	collect_rocket_modules_common.data = &collect_rocket_modules_common_arguments;

	add_task(&collect_rocket_modules_common);
}
