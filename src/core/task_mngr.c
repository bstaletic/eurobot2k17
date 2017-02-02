#include "task_mngr.h"



void task_mngr_run(){
	while(1){
		run_systemtask_preexecute();
		//
		//		if(task_user_active.data->state == TASK_ACTIVE){
		//			task_user_active.run(task_user_active.data);
		//		}else{
		//			task_t task_tmp;
		//			for(int i=0; i < TASK_USER_LIST_SIZE; i++){
		//
		//			}
		//		}

		run_systemtask_postexecute();
	}
}

void run_systemtask_preexecute(void){

}


void run_systemtask_postexecute(void){

}
