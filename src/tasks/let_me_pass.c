#include "let_me_pass.h"

task_t let_me_pass;
task_arguments_t let_me_pass_arguments;

void let_me_pass_run(task_arguments_t* argv){
	debug("Starting let_me_pass run method ");

    stuck_disable_cmd();
	set_xy_cmd(0, 0, 180); //setting where is robot

    info("||*****|RUNNING HOMOLOGATION|*****||");
    revolver_init();
	osDelay(10);
	revolver_init();
	rocket_init();
	osDelay(10);
	rocket_init();
	// revolver_go_to_position(POSITION_1);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_2);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_3);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_4);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_5);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_6);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_7);
	// osDelay(2000);
	//
	// revolver_go_to_position(POSITION_8);
	// osDelay(2000);
//////////////////////////PLAVA STRANA///////////////////////////////////////////
/*    set_motion_speed_cmd(120);
    goto_xy_cmd(400, 243, -1, 0);
    set_motion_speed_cmd(120);

    goto_xy_cmd(200, 243, 1, 0);
    set_motion_speed_cmd(50);
        wait_for_motion();
    rollers_forward();

    info("Starting to collect home modules");

    move_forward_cmd(200);
    set_motion_speed_cmd(50);
    move_forward_cmd(-200);
    set_motion_speed_cmd(50);
    move_forward_cmd(100);
        wait_for_motion();
    osDelay(1000);
    revolver_go_to_position(POSITION_2);
    osDelay(10);
    revolver_go_to_position(POSITION_2);

    move_forward_cmd(95);
    set_motion_speed_cmd(50);
    move_forward_cmd(-200);
    set_motion_speed_cmd(50);
    move_forward_cmd(100);
        wait_for_motion();
    osDelay(1000);
    revolver_go_to_position(POSITION_3);
    osDelay(10);
    revolver_go_to_position(POSITION_3);


    move_forward_cmd(95);
    set_motion_speed_cmd(50);
    move_forward_cmd(-200);
    set_motion_speed_cmd(50);
    move_forward_cmd(100);
        wait_for_motion();
    osDelay(1000);
    revolver_go_to_position(POSITION_4);
    osDelay(10);
    revolver_go_to_position(POSITION_4);


    move_forward_cmd(95);
    set_motion_speed_cmd(50);
    move_forward_cmd(-200);
    set_motion_speed_cmd(50);
    move_forward_cmd(100);
        wait_for_motion();
    osDelay(1000);
    revolver_go_to_position(POSITION_5);
    osDelay(10);
    revolver_go_to_position(POSITION_5);

    rollers_off();

info("Modules should be collected");

goto_xy_cmd(650, 233, -1, 0);
set_motion_speed_cmd(100);

	wait_for_motion();
rollers_reverse();
osDelay(500);
rollers_off();

info("Going for module 1 on the table");

goto_xy_cmd(700, -190, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
rollers_forward();
goto_xy_cmd(460, -540, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
move_forward_cmd(40);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(1000);
move_forward_cmd(15);
set_motion_speed_cmd(50);
// move_forward_cmd(-100);
// set_motion_speed_cmd(50);
// move_forward_cmd(75);
// set_motion_speed_cmd(50);
	wait_for_motion();
rollers_off();
ax12_set_speed(REVOLVER_AX12_ID, 120);
revolver_go_to_position(POSITION_6);
osDelay(10);
revolver_go_to_position(POSITION_6);

info("Module 1 from table should be collected");

goto_xy_cmd(1000, -340, -1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
rollers_forward();
goto_xy_cmd(1435, -200, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(1000);
	wait_for_motion();
	osDelay(5);
	wait_for_motion();
move_forward_cmd(-200);
move_forward_cmd(100);
	wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_7);
osDelay(10);
revolver_go_to_position(POSITION_7);

info("Module 2 should be collected from the table");

// rotate_to_cmd(-45);
goto_xy_cmd(1250, 370, -1, 0);
set_motion_speed_cmd(50);
goto_xy_cmd(900, 80, 1, 0);
set_motion_speed_cmd(50);

info("Nearing front notch");

goto_xy_cmd(940, -190, 1, 0);
set_motion_speed_cmd(120);
rotate_to_cmd(45);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(500);

info("Starting to drop modules");

revolver_go_to_position(POSITION_4);
osDelay(10);
revolver_go_to_position(POSITION_4);
move_forward_cmd(105);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-40);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_3);
osDelay(10);
revolver_go_to_position(POSITION_3);

move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_2);
osDelay(10);
revolver_go_to_position(POSITION_2);

move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_1);
osDelay(10);
revolver_go_to_position(POSITION_1);

move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();

move_forward_cmd(-150);
set_motion_speed_cmd(120);
rotate_for_cmd(180);
wait_for_motion();
set_motion_speed_cmd(120);
move_forward_cmd(-300);
set_motion_speed_cmd(120);
move_forward_cmd(150);

info("Modules should be droped");
*/
///////////////////////////////ZUTA STRANA///////////////////////////////////////

set_motion_speed_cmd(120);
goto_xy_cmd(400, -233, -1, 0);
set_motion_speed_cmd(120);

goto_xy_cmd(200, -233, 1, 0);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_forward();

info("Starting to collect home modules");

move_forward_cmd(200);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(500);
move_forward_cmd(-220);
set_motion_speed_cmd(50);
move_forward_cmd(110);
    wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_2);
osDelay(10);
revolver_go_to_position(POSITION_2);

move_forward_cmd(110);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(500);
move_forward_cmd(-220);
set_motion_speed_cmd(50);
move_forward_cmd(110);
    wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_3);
osDelay(10);
revolver_go_to_position(POSITION_3);


move_forward_cmd(110);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(500);
move_forward_cmd(-220);
set_motion_speed_cmd(50);
move_forward_cmd(120);
    wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_4);
osDelay(10);
revolver_go_to_position(POSITION_4);


move_forward_cmd(120);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(500);
move_forward_cmd(-220);
set_motion_speed_cmd(50);
	wait_for_motion();
move_forward_cmd(120);
    wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_5);
osDelay(10);
revolver_go_to_position(POSITION_5);

rollers_off();

info("Modules should be collected");

goto_xy_cmd(650, -233, -1, 0);
set_motion_speed_cmd(100);

	wait_for_motion();
rollers_reverse();
osDelay(500);
rollers_off();

info("Going for module 1 on the table");

goto_xy_cmd(700, 190, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
rollers_forward();
goto_xy_cmd(460, 540, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
move_forward_cmd(40);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(1000);
// move_forward_cmd(15);
// set_motion_speed_cmd(50);
move_forward_cmd(-100);
set_motion_speed_cmd(50);
move_forward_cmd(75);
set_motion_speed_cmd(50);
	wait_for_motion();
rollers_off();
ax12_set_speed(REVOLVER_AX12_ID, 120);
revolver_go_to_position(POSITION_6);
osDelay(10);
revolver_go_to_position(POSITION_6);

info("Module 1 from table should be collected");

goto_xy_cmd(1000, 340, -1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
rollers_forward();
goto_xy_cmd(1435, 200, 1, 0);
set_motion_speed_cmd(50);
	wait_for_motion();
osDelay(1000);
	wait_for_motion();
	osDelay(5);
	wait_for_motion();
move_forward_cmd(-200);
move_forward_cmd(100);
	wait_for_motion();
osDelay(1000);
revolver_go_to_position(POSITION_7);
osDelay(10);
revolver_go_to_position(POSITION_7);

info("Module 2 should be collected from the table");

// rotate_to_cmd(-45);
goto_xy_cmd(1250, 370, -1, 0);
set_motion_speed_cmd(50);
goto_xy_cmd(900, -80, 1, 0);
set_motion_speed_cmd(50);

info("Nearing front notch");

goto_xy_cmd(897, 188, -1, 0);
set_motion_speed_cmd(50);
rotate_to_cmd(-36);
	wait_for_motion();
// rollers_reverse();

info("Starting to drop modules");

revolver_go_to_position(POSITION_6);
osDelay(10);
revolver_go_to_position(POSITION_6);
move_forward_cmd(134);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
osDelay(1000);
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_5);
osDelay(10);
revolver_go_to_position(POSITION_5);
ax12_set_speed(REVOLVER_AX12_ID, 100);

set_motion_speed_cmd(50);
move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_4);
osDelay(10);
revolver_go_to_position(POSITION_4);

set_motion_speed_cmd(50);
move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_3);
osDelay(10);
revolver_go_to_position(POSITION_3);

set_motion_speed_cmd(50);
move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_2);
osDelay(10);
revolver_go_to_position(POSITION_2);

move_forward_cmd(35);
set_motion_speed_cmd(50);
wait_for_motion();
rollers_reverse();
    move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();
revolver_go_to_position(POSITION_1);
osDelay(10);
revolver_go_to_position(POSITION_1);

move_forward_cmd(35);
set_motion_speed_cmd(50);
    wait_for_motion();
rollers_reverse();
move_forward_cmd(-35);
set_motion_speed_cmd(50);
    wait_for_motion();
osDelay(1000);
rollers_off();

move_forward_cmd(-150);
set_motion_speed_cmd(120);
rotate_for_cmd(180);
	wait_for_motion();
	set_motion_speed_cmd(50);
	osDelay(5);
	wait_for_motion();
	set_motion_speed_cmd(50);
	osDelay(5);
	wait_for_motion();
set_motion_speed_cmd(120);
move_forward_cmd(-300);
set_motion_speed_cmd(120);
move_forward_cmd(150);


info("Modules should be droped");

/////////////////////////////////////////////////////////////////////////////////
///////////////////////POINT TO POINT METHOD/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
   // goto_xy_cmd(-5, -233, 1, 0);
   // set_motion_speed_cmd(50);
   // goto_xy_cmd(50, -233, -1, 0);
   // set_motion_speed_cmd(50);
   // wait_for_motion();
   // osDelay(2000);
   //
   // revolver_go_to_position(POSITION_2);
   //
   //  goto_xy_cmd(-5, -233, 1, 0);
   //  set_motion_speed_cmd(50);
   //  goto_xy_cmd(50, -233, -1, 0);
   //  set_motion_speed_cmd(50);
   //  wait_for_motion();
   //  osDelay(2000);
   //  revolver_go_to_position(POSITION_3);
   //
   //     goto_xy_cmd(-5, -233, 1, 0);
   //     set_motion_speed_cmd(50);
   //     goto_xy_cmd(50, -233, -1, 0);
   //     set_motion_speed_cmd(50);
   //     wait_for_motion();
   //     osDelay(2000);
   //     revolver_go_to_position(POSITION_4);
   //
   //          	goto_xy_cmd(-5, -233, 1, 0);
   //              set_motion_speed_cmd(50);
   //              goto_xy_cmd(50, -233, -1, 0);
   //              set_motion_speed_cmd(100);
   //              wait_for_motion();
   //              osDelay(2000);
   //
   //                  goto_xy_cmd(450,-233, -1, 0);
//
// goto_xy_cmd(940, 230, 1, 0);
// goto_xy_cmd(1015, 155, 1, 0);
// osDelay(500);
// rollers_forward();
//     goto_xy_cmd(940, 230, -1, 0);
//     goto_xy_cmd(1015, 155, 1, 0);
//     osDelay(500);
//         goto_xy_cmd(940, 230, -1, 0);
//         goto_xy_cmd(1015, 155, 1, 0);
//         osDelay(500);
//             goto_xy_cmd(940, 230, -1, 0);
//             goto_xy_cmd(1015, 155, 1, 0);

////////////////////////////////////////////////////////////////////////////////
////////////////////THIS IS ELEGANT SOLUTION AND WE DONT NEED THAT//////////////
///////////////////////////ZERO FUCKS GIVEN/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// info("Going to x: 1150 y: 540");
//      goto_xy_cmd(1150, 540, -1, 0);
//
//      info("Going to x: 1150 y:265\nClosing to home rocket");
//
//      goto_xy_cmd(1150, 265, 1, 0);
//
//      info("Starting to collect home modules");
//      //set_motion_speed_cmd(50);
//      rollers_reverse();
//  	for(int8_t i = 1; i <= 4; i++){
//
//          info("Collecting module %d", i);
//  		move_forward_cmd(50);
//  		osDelay(250);
//
//  		if(i <= 3) //for the last module robot needs to stay
//  			move_forward_cmd(-50);
//
//  		osDelay(1000); //making sure tube is on revolver
//          switch (i) {
//
//              case 1:
//                  revolver_go_to_position(800); //POSITION_TAKE_1
//                  break;
//
//              case 2:
//                  revolver_go_to_position(600); //POSITION_TAKE_2
//                  break;
//
//              case 3:
//                  revolver_go_to_position(400); //POSITION_TAKE_3
//                  break;
//
//              case 4:
//                  revolver_go_to_position(200); //POSITION_TAKE_4
//                  break;
//
//              default:
//                  revolver_init();
//
//          }
//  		osDelay(1000); //make sure revolver is in right position
//
//          info("Module %d should be collecetd", i);
//  	}
//      rollers_off();
//
//      info("Going to x: 1150 y:1000");
//      goto_xy_cmd(1150, 1000, -1, 0);
//      info("Going to x: 1150 y:1000");
//      goto_xy_cmd(1150, 1000, -1, 0);
//      rotate_to_cmd(135);
//      info("Going to move module from the way");
//      move_forward_cmd(50);
//      move_forward_cmd(-50);
//      info("Module should be out of the way");
//
//      info("Going to x: 240 y:964\nNearing front notch");
//
//      goto_xy_cmd(240, 964, 1, 0);
//
//      info("Starting to drop modules");
//      //set_motion_speed_cmd(50);
//      rollers_forward();
//  	for(int8_t i = 1; i <= 4; i++){
//
//          info("Dropping module %d", i);
//
//          switch (i) {
//
//              case 1:
//                  revolver_go_to_position(800); //POSITION_TAKE_4
//                  break;
//
//              case 2:
//                  revolver_go_to_position(600); //POSITION_TAKE_3
//                  break;
//
//              case 3:
//                  revolver_go_to_position(400); //POSITION_TAKE_2
//                  break;
//
//              case 4:
//                  revolver_go_to_position(200); //POSITION_TAKE_1
//                  break;
//
//              default:
//                  revolver_init();
//
//          }
//          move_forward_cmd(-10);
//          osDelay(500); //make sure revolver is out
//          move_forward_cmd(10);
//
//          info("Module %d should be dropped", i);
//  	}
//
////////////////////////////////////////////////////////////////////////////////
///////////////////////////THIS IS SECOND ELEGANT OPTION////////////////////////
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
