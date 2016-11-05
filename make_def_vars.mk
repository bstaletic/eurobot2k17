SRC := ${HOME}/eurobot2k17/
DESTDIR := ${SRC}build/

CC := arm-none-eabi-gcc
CFLAGS := -Os -g -Wall -Wextra -pedantic -x c -std=c99
FINAL_CFLAGS := ${CLFAGS}  -DSTM32F4 -DSTM32F407VG -DSTM32F4CCM -D_ROM_OFF=0x08000000 -D_ROM=1024K -D_RAM=128K -D_CCM=64K -D_CCM_OFF=0x10000000 -D_RAM_OFF=0x20000000 -fno-common -fdata-sections -I${SRC}libopencm3/include -I${SRC}
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16
DEPFLAGS := -MD
BOARD := STM32F407VG

LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LINK_PATH := -L${SRC}libopencm3/lib
LINK_LIB := -lopencm3_stm32f4

OBJ := ${SRC}main.o ${SRC}initialisation/clock_config.o ${SRC}initialisation/gpio_config.o ${SRC}initialisation/uart_config.o ${SRC}initialisation/timer_config.o ${SRC}drivers/actuators/ax12/ax12.o ${SRC}drivers/actuators/motion/motion.o
DEPS := $(OBJ:.o=.d)

DOXYFILE := $(SRC)Doxyfile
