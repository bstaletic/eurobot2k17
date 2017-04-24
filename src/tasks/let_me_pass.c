#include "let_me_pass.h"

task_t let_me_pass;
task_arguments_t let_me_pass_arguments;

void let_me_pass_run(task_arguments_t* argv){
	debug("Starting let_me_pass run method ");
	osDelay(1000);

    info("||*****|RUNNING HOMOLOGATION|*****||");

    info("Going to x: 1150 y: 540");
    goto_xy_cmd(1150, 540, -1, 0);

    info("Going to x: 1150 y:265\nClosing to home rocket");

    goto_xy_cmd(1150, 265, 1, 0);

    info("Starting to collect home modules");
    //set_motion_speed_cmd(50);
    rollers_reverse();
	for(int8_t i = 1; i <= 4; i++){

        info("Collecting module %d", i);
		move_forward_cmd(50);
		osDelay(250);

		if(i <= 3) //for the last module robot needs to stay
			move_forward_cmd(-50);

		osDelay(1000); //making sure tube is on revolver
        switch (i) {

            case 1:
                revolver_go_to_position(800); //POSITION_TAKE_1
                break;

            case 2:
                revolver_go_to_position(600); //POSITION_TAKE_2
                break;

            case 3:
                revolver_go_to_position(400); //POSITION_TAKE_3
                break;

            case 4:
                revolver_go_to_position(200); //POSITION_TAKE_4
                break;

            default:
                revolver_init();

        }
		osDelay(1000); //make sure revolver is in right position

        info("Module %d should be collecetd", i);
	}
    rollers_off();

    info("Going to x: 1150 y:1000");
    goto_xy_cmd(1150, 1000, -1, 0);
    info("Going to x: 1150 y:1000");
    goto_xy_cmd(1150, 1000, -1, 0);
    rotate_to_cmd(135);
    info("Going to move module from the way");
    move_forward_cmd(50);
    move_forward_cmd(-50);
    info("Module should be out of the way");

    info("Going to x: 240 y:964\nNearing front notch");

    goto_xy_cmd(240, 964, 1, 0);

    info("Starting to drop modules");
    //set_motion_speed_cmd(50);
    rollers_forward();
	for(int8_t i = 1; i <= 4; i++){

        info("Dropping module %d", i);

        switch (i) {

            case 1:
                revolver_go_to_position(800); //POSITION_TAKE_4
                break;

            case 2:
                revolver_go_to_position(600); //POSITION_TAKE_3
                break;

            case 3:
                revolver_go_to_position(400); //POSITION_TAKE_2
                break;

            case 4:
                revolver_go_to_position(200); //POSITION_TAKE_1
                break;

            default:
                revolver_init();

        }
        move_forward_cmd(-10);
        osDelay(500); //make sure revolver is out
        move_forward_cmd(10);

        info("Module %d should be dropped", i);
	}

////////////////////////////////////////////////////////////////////////////////

    // goto_xy_cmd(1150, 1000, -1, 0);
    // info("Going to x: 1150 y:1000");
    // goto_xy_cmd(240, 964, 1, 0);
    // info("Going to x: 240 y:964\nNearing side notch");
    // rotate_to_cmd(-90);
    //
    // info("Starting to drop modules in to side notch");
    // //set_motion_speed_cmd(50);
    // for(int8_t i = 0; i <= 3; i++){
    //
    //     switch (i) {
    //
    //         case 1:
    //             revolver_go_to_position(300); //POSITION_DROP_1
    //             break;
    //
    //         case 2:
    //             revolver_go_to_position(500); //POSITION_DROP_2
    //             break;
    //
    //         case 3:
    //             revolver_go_to_position(700); //POSITION_DROP_3
    //             break;
    //
    //         case 4:
    //             revolver_go_to_position(900); //POSITION_DROP_4
    //             break;
    //
    //         default:
    //             revolver_init();
    //
    //     }
    //     osDelay(1000); //make sure revolver is in right position
    //     poke_module(SERVO_TOP);
    //     osDelay(2000); //make sure module is out
    //     poke_return(SERVO_TOP);
    //     move_forward_cmd(-11);
    //
    //     info("Module %d should be dropped", i);
    // }

    debug("TASK IS DONE");
	argv->state = TASK_DONE;

}
void let_me_pass_init(task_arguments_t* argv){
	debug("Starting let_me_pass initialsation");

    set_xy_cmd(0, 0, 180); //setting where is robot
    //set_motion_speed_cmd(50); //seting speed

    debug("Initialisation done");
}
void let_me_pass_finish(task_arguments_t* argv){
	debug("Starting let_me_pass finish");



    debug("HOMOLOGATION IS DONE");
}

void let_me_pass_calculate_priority(task_arguments_t* argv){
	debug("Starting let_me_pass calc calculate priority");
}


void ctor_let_me_pass(void){

	debug("Starting let_me_pass ctor");

	let_me_pass.run = (task_callback)&let_me_pass_run;
	let_me_pass.init = (task_callback)&let_me_pass_init;
	let_me_pass.finish = (task_callback)&let_me_pass_finish;
	let_me_pass.calculate_priority = (task_callback)&let_me_pass_calculate_priority;
	strncpy(let_me_pass.task_name,"Test Task 1\0",12);

	let_me_pass_arguments.estimated_time = 50;
	let_me_pass_arguments.priority = 100;
	let_me_pass_arguments.state = TASK_READY;

	let_me_pass.data = &let_me_pass_arguments;

	add_task(&let_me_pass);
}
