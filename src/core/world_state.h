#ifndef CORE_WORLD_STATE_H
#define CORE_WORLD_STATE_H

#include "utils/common_utils.h"

typedef enum{
	ELEMENT_ACTIVE,
	ELEMENT_IN_ROBOT,
	ELEMENT_DONE,
	ELEMENT_LOST
}element_status_t;

typedef enum{
	MECHANISM_FULL,
	MECHANISM_ACTIVE,
	MECHANISM_ERROR
}mechanism_status_t;

typedef enum{
	ELEMENT_COMMON,
	ELEMENT_ALLY
}element_distribution_t;

typedef struct{
	mechanism_status_t status;
	int elements_count;
}mechanism_t;

typedef struct{
	element_status_t status;
	element_distribution_t distribution;
	char name[32];
	point_t position;
}element_t;

/// @todo todo remove n from ifndef :D
#ifndef ROBOT_VOYAGER
typedef struct{
	mechanism_t revolver;
	mechanism_t rocket_luncher;
}robot_state;

typedef struct{
	element_t rocket_module_ally;
	element_t rocket_module_common;
	element_t lunar_module_ally_1;
	element_t lunar_module_ally_2;
	element_t lunar_module_common_1;
	element_t lunar_module_common_2;
	element_t lunar_module_common_3;
}world_state;

#else

typedef struct{
	mechanism_t ball_colector;
};

typedef struct{
	element_t ball;
};

typee

#endif

#endif
