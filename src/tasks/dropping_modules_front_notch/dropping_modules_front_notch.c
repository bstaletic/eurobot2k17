#include "dropping_modules_front_notch.h"

task_t dropping_modules_front_notch;
task_arguments_t dropping_modules_front_notch_arguments;

void dropping_modules_front_notch_run(task_arguments_t* argv){
	debug("||**********|dropping_modules_front_notch run method|**********||");
	osDelay(1000);

	//TASK2
	//AFTER collect_rocket_modules_common TASK
	//go collect COMMON_TABLE_MODULE_3
	goto_xy_cmd(740, 1200, 1, 0);
	rotate_to_cmd(45);
	rollers_on();
	move_forward_cmd(50);
	//you are now aprox. where you should be to stick it to the notch six itmes BUKVALNO! (dont be perv pls)
	osDelay(1000);


	rollers_forward();
	for(int8_t i = 0; i <=5 ; i++){

		colour_shift(BLUE);

		poke_module(SERVO_FRONT);
		osDelay(2000); //make sure module is out
		revolver_previous();
		osDelay(1000); //make sure revolver is well rotated
		poke_return(SERVO_FRONT);
		//osDelay(1000); //make sure poke servo is in initial position
	}

	argv->state = TASK_DONE;

}
void dropping_modules_front_notch_init(task_arguments_t* argv){
	debug("dropping_modules_front_notch_init");

	set_motion_speed_cmd(50);
	revolver_go_to_position(7); //there are 6 modules in robot and 7th needs too get in
	poke_init();
}
void dropping_modules_front_notch_finish(task_arguments_t* argv){
	debug("dropping_modules_front_notch_finish");

	rollers_off();
}

void dropping_modules_front_notch_calculate_priority(task_arguments_t* argv){
	debug("dropping_modules_front_notch_calc_pri");
}


void ctor_test_1(void){

	debug("dropping_modules_front_notch ctor");

	dropping_modules_front_notch.run = (task_callback)&dropping_modules_front_notch_run;
	dropping_modules_front_notch.init = (task_callback)&dropping_modules_front_notch_init;
	dropping_modules_front_notch.finish = (task_callback)&dropping_modules_front_notch_finish;
	dropping_modules_front_notch.calculate_priority = (task_callback)&dropping_modules_front_notch_calculate_priority;
	strncpy(dropping_modules_front_notch.task_name,"Test Task 1\0",12);

	dropping_modules_front_notch_arguments.estimated_time = 50;
	dropping_modules_front_notch_arguments.priority = 100;
	dropping_modules_front_notch_arguments.state = TASK_READY;

	dropping_modules_front_notch.data = &dropping_modules_front_notch_arguments;

	add_task(&dropping_modules_front_notch);
}
