#include "collect_rocket_modules_common.h"

task_t collect_rocket_modules_common;
task_arguments_t collect_rocket_modules_common_arguments;

void collect_rocket_modules_common_run(task_arguments_t* argv){
	debug("||**********|collect_rocket_modules_common run method|**********||");
	osDelay(1000);

    //FIRST TASK
	//go collect COMMON_TABLE_MODULE_1
    goto_xy_cmd(1000, 550, 1, 0);
	rotate_to_cmd(-90);
    rollers_on();
    set_motion_speed_cmd(50);
    move_forward_cmd(50);
    osDelay(250);
    revolver_next();
    //go collect COMMON_TABLE_MODULE_2
    goto_xy_cmd(550, 1100, 1, 0);
	rotate_to_cmd(-180);
    set_motion_speed_cmd(50);
    move_forward_cmd(50);
    osDelay(250);
    revolver_next();

    //collecting COMMON_ROCKET_MODULES from other rocket
    set_motion_speed_cmd(50);
    goto_xy_cmd(265, 1350, 1, 0);
	rotate_to_cmd(-180); //you are now aprox. where you should be to stick it to rocket (dont be perv pls)
    //collecting modules
    set_motion_speed_cmd(50);
    for(int8_t i = 0; i <= 3; i++){
		move_forward_cmd(50);
		osDelay(250);
		if(i <= 2) //for the last module robot needs to stay in position
			move_forward_cmd(-50);
		osDelay(1000); //making sure tube is on revolver
		revolver_next();
        osDelay(1000); //make sure revolver is in next position
	} //modules should be collected and revolver postion should be 6

	argv->state = TASK_DONE;

}
void collect_rocket_modules_common_init(task_arguments_t* argv){
	debug("collect_rocket_modules_common_init");

	//putting co-or sys in table corner
	set_xy_cmd(935, 175, 0);
	set_motion_speed_cmd(50);
    revolver_init();
    poke_init();
	rollers_reverse();

}
void collect_rocket_modules_common_finish(task_arguments_t* argv){
	debug("collect_rocket_modules_common_finish");

    set_motion_speed_cmd(50);
    move_forward_cmd(-100); //back away from the rocket
	rollers_off();

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
