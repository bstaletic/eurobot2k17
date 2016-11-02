AR := arm-none-eabi-ar
CC := arm-none-eabi-gcc
CFLAGS := -Os -g -Wall -Wextra -pedantic -x c -std=c99 -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -DSTM32F4 -DSTM32F407VG -DSTM32F4CCM -D_ROM_OFF=0x08000000 -D_ROM=1024K -D_RAM=128K -D_CCM=64K -D_CCM_OFF=0x10000000 -D_RAM_OFF=0x20000000 -fno-common -fdata-sections -MD -I${PROJDIR}/libopencm3/include
PROJDIR := ${HOME}/eurobot3k17
BOARD := STM32F407VG
LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LINK_PATH := -L${PROJDIR}/libopencm3/lib
LINK_LIB := -lopencm3_stm32f4

DOXYFILE := $(PROJDIR)/Doxyfile

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.bin
	rm -rf generated.*.ld
	rm -rf *.map
	rm -rf lib*.a

.PHONY: clean
