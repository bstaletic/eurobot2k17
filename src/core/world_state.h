#ifndef CORE_WORLD_STATE_H
#define CORE_WORLD_STATE_H

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
	ELEMENT_OUR
}element_distribution_t;

typedef struct{
	int x;
	int y;
}point_t;

typedef struct{
	element_status_t status;
	element_distribution_t distribution;
	char name[32];
	point_t position;
}element_t;


/// @todo todo remove n from ifndef :D
#ifndef ROBOT_ENTERPRISE



#else if ROBOT_VOYAGER


#endif

#endif
