#Writing tasks

This is a short HOWTO to writing new tasks. For the sake of simplicity
we'll call the tast mytask and add it to all the tasks.

###Defining a new task

1. Create a new file named `mytask.c` in `src/tasks`
2. On the first line include the file's header (`#include "mytask.h"`, we'll get back to this header later)
3. Declare global variables for the task and its arguments
```
task_t mytask;
task_arguments_t mytask_arguments;
```
- You'll need to write what should the task do before starting, while it's running and when it finishes.
```
void mytask_run(task_arguments_t* argv) {
	debug("Task started");
	//The commands you want robot to do
	//We'll get back to available commands later
	mytask.state = TASK_FINISHED;
}

void mytask_init(task_arguments_t* argv) {
	debug("Task initialisation");
	//Set task preconditions to be met
}

void mytask_finish(task_arguments_t* argv) {
	debug("Task done");
}

void mytask_priority(task_arguments_t* argv) {
	argv->prority = 0;
}

//Constructor of the task
void ctor_task_mytask(void) {
	mytask.run = (task_callback)&mytask_run;
	mytask.init = (task_callback)&mytask_init;
	mytask.finish = (task_callback)&mytask_finish;
	mytask.calculate_priority = (task_callback)&mytask_priority;
	mytask.name = "mytask";

	mytask_arguments.estimated_time = 50;
	mytask_arguments.priority = 0;
	arguments.state = TASK_READY;

	mytask.data = &arguments;

	add_task(&mytask);
}
```

Now that we have defined a new task we need to expose it to the rest of the code through its header.

- Make a new file named `mytask.h` in `src/tasks`.
- The header file needs to have a guard statement
```
#ifndef MY_TASK_HEADER
#define MY_TASK_HEADER
//Write all your code here
#endif //MY_TASK_HEADER
```
- We are supposed to only expose the constructor and we do that by adding
```
void ctor_task_mytask(void);
```
to our header.

###Available commands

We shall devide the available commands in three categories

1. Logger and debugging functions
2. Actuators (excl. motion driver)
3. Motion commands

#####Logger and debugging functioins

These are defined in `src/utils/logger.h` so to use them, you need to include that header.

Available commands are `error()`, `debug()` and `info()`. All of these print information to the debugging USART and will be visible in console. These functions also take `printf()`-like formatting syntax.

#####Actuator functions

There are numerous headers in `src/executors`, disregarding the `motion*` we may pick any header we find useful and use all of its exposed functions.

#####Motion commands

There are two headers having the word motion in `src/executors`, but only the `motion_commands.h` should be used. This header's functions wrap
