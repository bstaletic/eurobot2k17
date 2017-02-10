#ifndef CORE_TASK_H
#define CORE_TASK_H

#include <stdint-gcc.h>
/// status of task
typedef enum{
	TASK_ACTIVE, ///< task is currently running
	TASK_ACTIVE_WTM,  ///< task is currently active but it is waiting on motion
	TASK_READY, ///< task is ready
	TASK_DONE, ///< finished task
	TASK_BLOCKED ///< task is blocked currently blocked because of some obstacle
} task_states_t ;

/// types of task.
typedef enum{
	TASK_USER, ///< user tasks (collect balls task ... )
	TASK_SYSTEM_PREEXECUTE,  /*!<  system tasks are tasks that have to be updated every cycle ( set glovbal time, update led, ... )
	 	 	 	 	 	 	 	 Tasks with this type will be executed before user tasks */
	TASK_SYSTEM_POSTEXECUTE, ///< same as TASK_SYSTEM_PREEXECUTE but this tasks will be executed after user task.
	TASK_BACKPROC ///< this task will be run while robot is in motion wait state
} task_types_t;



/// task functions get this struct as argument
typedef struct {
	void* world_state; ///< @todo todo edit when world state is completed
	uint32_t time; ///< time to end of the match;
	uint32_t priority; ///< priority
	uint32_t estimated_time; ///< estimated time of execution
	task_states_t state; ///< task state, for more @see task_types_t

} task_arguments_t;

typedef int (*task_callback)(task_arguments_t*); // callback for task struct, for more @see task_t

/// encapsulates functions pointers and data in one task
typedef struct {
	task_types_t type; ///< type of task, for more info @see task_types_t

	task_callback init; ///< pointer to init function. This function is be called at starting of task.
	task_callback run; ///< pointer to run function This function is called when task is active
	task_callback finish; ///< pointer to finish function. This function is called when task status went from active to done.
	task_callback calculate_priority; ///< as name says.

	task_arguments_t* data; ///< @see task_arguments_t
	char task_name[50]; ///< task name

} task_t;

#endif
