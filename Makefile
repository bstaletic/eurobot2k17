CC := arm-none-eabi-gcc
FAMILY := STM32F4
BOARD := STM32F407VG
#CFLAGS := -mfloat-abi=hard -DSTM32F4 -I libopencm3/include -L libopencm3/lib -lopencm3_stm32f4 -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
WARNINGS := -Wall -Wextra -pedantic -x c -std=c99
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16
DEFINITIONS_OBJ := -D$(FAMILY) -D$(BOARD) -DSTM32F4CCM
DEFINITIONS_LD := -D_ROM=1024K -D_RAM=128K -D_CCM=64K -DSTM32F4CCM -D_CCM_OFF=0x10000000 -D$(FAMILY) -D_ROM_OFF=0x08000000 -D_RAM_OFF=0x20000000
INCLUDE_PATH := -Ilibopencm3/include
LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LINK_PATH := -Llibopencm3/lib
LINK_LIB := -lopencm3_stm32f4
OPTIMISE := -Os -g

OBJS := main.o

DOXYFILE := Doxyfile

main.elf : generated.$(BOARD).ld main.o
	$(CC) --static -nostartfiles -Tgenerated.$(BOARD).ld $(MFLAGS) -Wl,-Map=main.map -Wl,--gc-sections $(LINK_PATH) main.o $(LINK_LIB) $(LINK_GROUP) -o $@

main.o : main.c
	$(CC) $(OPTIMISE) $(MFLAGS) $(WARNINGS) $(FFLAGS) $(DEFINITIONS_OBJ) $(INCLUDE_PATH) -o $@ -c $<

generated.$(BOARD).ld :
	$(CC) -E $(MFLAGS) $(DEFINITIONS_LD) -P -E libopencm3/ld/linker.ld.S > $@
main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

flash: main.bin
	st-link write $< 0x8000000

dodoc:
	doxygen $(DOXYFILE)

clean:
	rm -rf main.* generated.*.ld main.map

.PHONY: clean dodoc flash
