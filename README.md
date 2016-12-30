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
  - `src` - directory contains the actual source files
    - `main.c` - the main while(1) loop
    - `drivers` - functions for controlling the actual devices and mechanisms on the robot
      - `actuators` - output devices such as motors and pneumatics
        - `ax12` - digital servo by Dynamixel
          - `Makefile` - source the necessary files to make proper compilation possible
          - `ax12.c` and `ax12.h` - functions for interfacing with the AX12
        - `motion` - motion driver, uses UART to talk to another MCU
          - `Makefile` - source the necessary files to make proper compilation possible
          - `motion.c` and `motion.h` - functions for interfacing with the motion driver
      - `sensors` - input devices such as digital and analog sensors
        - `analog` - analog sensors
          - `Makefile` - source the necessary files to make proper compilation possible
          - `colour.c` and `colour.h` - interface of the colour sensor
    - `initialisation` - contains source files with functions initialising the MCU
      - `Makefile` - source the necessary files to make proper compilation possible
      - `adc_config.c` and `adc_config.h` - initialises ADC1
      - `clock_config.c` and `clock_config.h` - initialises clock for all the peripheries utilised by the project
      - `gpio_config.c` and `gpio_config.h` - initialises GPIO ports
      - `timer_config.c` and `timer_config.h` - enables PWM's and other timers
      - `uart_config.c` and `uart_config.h` - initialises UART's
  - `libopencm3` - a git submodule and a library on which every file depends
  - `LICENSE` - GPL3 license
  - `Doxyfile` - doxygen configuration
  - `Makefile` - rules to build and flash the actual binary
  - `TODO` - serves as a reminder of the things needed to be done
  - `make_def_rules.mk` - contains clean target and .c -> .o `make` rules
  - `make_def_vars.mk` - contains all variables used by other `Makefiles`

### Compiling

#### Requirements

- Linux or Cygwin environment
- `arm-none-eabi` toolchain
- `git`
- `make`
- `openocd` utility

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

- assembly - generates only the assembly files
- bin - builds only the non-debug bin file
- clean - cleans either debug or release directory
- clean-all - cleans the whole project of compiled files
- doc - builds "doxygen" documentation
- flash - flashes the bin file onto STM32F4-Discovery
- help - prints this help message

The `make` variables known to this project's `Makefile` are:

- AS - assembler to be used
- CC - compiler to be used
- OBJCOPY - objcopy from the utilised toolchain
- BOARD - defines the board for which the code is compiled
- CFLAGS - user configurable compiler flags
- ASFLAGS - user configurable assembler flags
- DESTDIR - a directory where the resulting elf and bin binaries as well as the linker script
- OBJDIR - directory to keep all the object files
- DOCDIR - directory containing documentation
- BINDIR - directory with release version of the code
- ASMDIR - directory with assembly files
- SRCDIR - path to the project's source code
- DOXYGEN - executable for generating documentation
- DOXTFILE - $(STARTDIR)Doxyfile
- OPENOCD - flash utility from openocd package
- MKDIR_P - utility to make specified directory and its parents
- DEBUG - set to 0 for the release build

The default values of these variables:

- CC := arm-none-eabi-gcc
- AS := arm-none-eabi-as
- OBJCOPY := arm-none-eabi-objcopy
- DESTDIR := $(STARTDIR)build/
- OBJDIR := $(DESTDIR)obj/
- DOCDIR := $(DESTDIR)doc/
- BINDIR := $(DESTDIR)bin/
- ASMDIR := $(DESTDIR)asm/
- SRCDIR := $(STARTDIR)src/
- DOXYGEN := doxygen
- DOXYFILE := $(STARTDIR)Doxyfile
- OPENOCD := openocd
- MKDIR_P := mkdir -p
- DEBUG := not initially set

NOTE: If you set and of the directory paths, make sure you include the trailing slash.
