#include "motion.h"

void motion_main(void){
	while(1){
		for (int i = 0; i < 100; i++){
			debug("MOTION");
			for (int j = 0; j < 100000; j++){
							__asm__("nop");
						}
			error("TOME");
			for (int j = 0; j < 1000000000; j++){
				__asm__("nop");
			}
		}
	}

}
