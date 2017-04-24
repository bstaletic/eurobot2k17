#include "task_roll_me_up.h"

task_t task_roll_me_up;
task_arguments_t task_roll_me_up_arguments;

void task_roll_me_up_run(task_arguments_t* argv){
	debug("task_roll_me_up run method ");
	debug("NOW YOU WAIT ONE SEC");
	osDelay(5000);

    // rollers_forward();
	// debug("ROLLERS ARE ON");
    // osDelay(1500); //1
    // revolver_next();
	//
    // osDelay(1500); //2
    // revolver_next();


    // osDelay(1500); //3
    // revolver_next();
    //
    // osDelay(1500);  //4
    // revolver_next();
    //
    // osDelay(1500);  //5
    // revolver_next();
    //
    // osDelay(1500); //6
    // revolver_next();
    //
    // osDelay(1500); //7
    // revolver_next();

	argv->state = TASK_DONE;

}
void task_roll_me_up_init(task_arguments_t* argv){
	debug("task_roll_me_up_init");

	// revolver_init();
	rollers_reverse();
}
void task_roll_me_up_finish(task_arguments_t* argv){
	debug("task_roll_me_up_finish");

}

void task_roll_me_up_calculate_priority(task_arguments_t* argv){
	debug("task_roll_me_up_calc_pri");
}


void ctor_roll_me_up(void){

	debug("task_roll_me_up ctor");

	task_roll_me_up.run = (task_callback)&task_roll_me_up_run;
	task_roll_me_up.init = (task_callback)&task_roll_me_up_init;
	task_roll_me_up.finish = (task_callback)&task_roll_me_up_finish;
	task_roll_me_up.calculate_priority = (task_callback)&task_roll_me_up_calculate_priority;
	strncpy(task_roll_me_up.task_name,"Roll me up\0",12);

	task_roll_me_up_arguments.estimated_time = 50;
	task_roll_me_up_arguments.priority = 999;
	task_roll_me_up_arguments.state = TASK_READY;

	task_roll_me_up.data = &task_roll_me_up_arguments;

	add_task(&task_roll_me_up);
}
