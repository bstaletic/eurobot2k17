#include "collect_rocket_modules_home.h"

task_t collect_rocket_modules_home;
task_arguments_t collect_rocket_modules_home_arguments;

void collect_rocket_modules_home_run(task_arguments_t* argv){
	debug("||**********|collect_rocket_modules_home run method|**********||");
	osDelay(1000);

	//first task in order
	//going to collect_rocket_modules our collour
	set_motion_speed_cmd(50);
	goto_xy_cmd(1150, 265, 1, 0);
	rotate_for_cmd(90);
	rollers_reverse();
	rollers_on();

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
	}

	argv->state = TASK_DONE;

}
void collect_rocket_modules_home_init(task_arguments_t* argv){
	debug("collect_rocket_modules_home_init");

	//putting co-or sys in table corner
	set_xy_cmd(175, 935, 0);
	//making sure revolver is in initial position
	revolver_init();
	poke_init();
}
void collect_rocket_modules_home_finish(task_arguments_t* argv){
	debug("collect_rocket_modules_home_finish");

	rollers_off();
	move_forward_cmd(-100); //slowly move away from the rocket
}
void collect_rocket_modules_home_calculate_priority(task_arguments_t* argv){
	debug("collect_rocket_modules_home_calc_pri");
}


void ctor_collect_rocket_modules_home(void){

	debug("collect_rocket_modules_home ctor");

	collect_rocket_modules_home.run = (task_callback)&collect_rocket_modules_home_run;
	collect_rocket_modules_home.init = (task_callback)&collect_rocket_modules_home_init;
	collect_rocket_modules_home.finish = (task_callback)&collect_rocket_modules_home_finish;
	collect_rocket_modules_home.calculate_priority = (task_callback)&collect_rocket_modules_home_calculate_priority;
	strncpy(collect_rocket_modules_home.task_name,"Test Task 1\0",12);

	collect_rocket_modules_home_arguments.estimated_time = 50;
	collect_rocket_modules_home_arguments.priority = 100;
	collect_rocket_modules_home_arguments.state = TASK_READY;

	collect_rocket_modules_home.data = &collect_rocket_modules_home_arguments;

	add_task(&collect_rocket_modules_home);
}
