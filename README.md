# eurobot2k17

This repo is going to be used for hosting the code for the upcoming Eurobot 2017 competition. The code is GPL3 licensed.

### Hardware being utilised

1. STM32F4-Discovery board
2. PIC base motion driver
3. Dynamixel AX12
4. Analogue PWM driven servo motors

### Software being utilised

1. [libopencm3](https://libopencm3.github.io/docs/latest/stm32f4/html/modules.html) library
2. [FreeRTOS](https://freertos.org/)

### Directory structure

- Top level directory contains
  - `drivers` - functions for controlling the actual devices and mechanisms on the robot
    - `actuators` - output devices such as motors and pneumatics
      - `ax12` - digital servo by Dynamixel
        - `ax12.c` and `ax12.h` - functions for interfacing with the AX12
        - `Makefile` - source the necessary files to make proper compilation possible
      - `motion` - motion driver, uses UART to talk to another MCU
        - `motion.c` and `motion.h` - functions for interfacing with the motion driver
        - `Makefile` - source the necessary files to make proper compilation possible
  - `initialisation` - contains source files with functions initialising the MCU
    - `Makefile` - source the necessary files to make proper compilation possible
    - `clock_config.c` and `clock_config.h` - initialises clock for all the peripheries utilised by the project
    - `gpio_config.c` and `gpio_config.h` - initialises GPIO ports
    - `timer_config.c` and `timer_config.h` - enables PWM's and other timers
    - `uart_config.c` and `uart_config.h` - initialises UART's
  - `libopencm3` - a git submodule and a library on which every file depends
  - `LICENSE` - GPL3 license
  - `Doxyfile` - doxygen configuration
  - `Makefile` - rules to build and flash the actual binary
  - `TODO` - serves as a reminder of the things needed to be done
  - `main.c` - the main while(1) loop
  - `make_def_rules.mk` - contains clean target and .c -> .o `make` rules
  - `make_def_vars.mk` - contains all variables used by other `Makefiles`

### Compiling

#### Requirements

- Linux or Cygwin environment
- `arm-none-eabi` toolchain
- `git`
- `make`
- `st-link` utility

#### Compiling and flashing the binary

##### Quick start
If you're just looking for a fastest way to use this code here's the simplest way:

1. `git clone https://github.com/bstaletic/eurobot2k17`
2. `cd eurobot2k17`
3. `git submodule update --init`
4. `cd libopencm3`
5. `make`
6. `cd ..`
7. `make flash`

#### Full guide
This will explain every single step in the compilation procedure and thte ways to customise it. While the secnod just changes the working directory to that of the cloned repo.

First six steps are mandatory. The first step clones the repository, the third clones the libopencm3 library and the fifth compiles the `libopencm3` library.

- `git clone https://github.com/bstaletic/eurobot2k17`
- `cd eurobot2k17`
- `git submodule update --init`
- `cd libopencm3`
- `make`
- `cd ..`

Now the code is ready for compilation and the default `make` target compiles the bin file ready for flashing onto STM32F407VG. Other possible targets are as follows:

- $(DESTDIR)eurobot2k17.elf - passed to objcopy to make the bin file
- $(DESTDIR)generated.STM32F407VG.ld - linker script used to make the elf file
- flash - flashes the bin file onto STM32F407
- doc - builds `doxygen` documentation
- clean - cleans the whole project of compiled files

The `make` variables known to this project's `Makefile` are:

- BOARD - defines the board for which the code is compiled
- CC - compiler to be used
- CFLAGS - user configurable compiler flags
- DESTDIR - a directory where the resulting elf and bin binaries as well as the linker script
- SRC - path to the project's source code
- DOXYGEN - executable for generating documentation
- OBJCOPY - objcopy from the utilised toolchain
- STFLASH - flash utility from st-link package

The default values of these variables:

- BOARD := STM32F407VG
- CC := arm-none-eabi-gcc
- CFLAGS := -Os -g -Wall -Wextra -pednatic -x c -std=c99
- DESTDIR := ${SRC}build/
- SRC not set by default
- DOXYGEN := doxygen
- OBJCOPY := arm-none-eabi-objcopy
- STLINK := st-flash

NOTE: If you set $(SRC) or $(DESTDIR) make sure you include the trailing slash.
