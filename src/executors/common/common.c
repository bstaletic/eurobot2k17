#include "common.h"
#include "../utils/logger.h"
#include "cmsis_os.h"

void common_main(void){
	while(1){
		logger_main();

	}
}
