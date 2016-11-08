include $(SRC)make_def_vars.mk

# Bin file will be flashed onto the STM32F4-Discovery board
$(DESTDIR)eurobot2k17.bin: $(DESTDIR)eurobot2k17.elf
	$(OBJCOPY) -Obinary $< $@

# Compile the executable using every .o file created and the generated linker script
$(DESTDIR)eurobot2k17.elf : $(DESTDIR)generated.$(BOARD).ld $(OBJ)
	$(CC) --static -nostartfiles -T$(DESTDIR)generated.$(BOARD).ld $(MFLAGS) -Wl,-Map=eurobot2k17.map -Wl,--gc-sections $(LINK_PATH) $(OBJ) $(LINK_LIB) $(LINK_GROUP) -o $@

# Generate the linker script
$(DESTDIR)generated.$(BOARD).ld :
	$(CC) -E $(FINAL_CFLAGS) -P -E $(SRC)libopencm3/ld/linker.ld.S > $@
	@rm -f linker.ld.d

# Use make flash to flash the bin file onto STM32F4
flash: $(DESTDIR)eurobot2k17.bin
	$(STLINK) write $< 0x8000000

# Make the documentation for the code - currently invalid
doc: doc-clean
	$(DOXYGEN) $(DOXYFILE)
	@mv $(SRC)latex $(DESTDIR)
	@mv $(SRC)html $(DESTDIR)

help:
	@echo ""
	@echo Use "make flash" to quickly compile the binary and flash onto STM32
	@echo Possible make targets:
	@echo $$(DESTDIR)eurobot2k17.bin - binary ready for flashing
	@echo $$(DESTDIR)eurobot2k17.elf - passed to objcopy to make the bin file
	@echo $$(DESTDIR)generated.$$(BOARD).ld - linker script used to make the elf file
	@echo flash - flashes the bin file onto $$(BOARD)
	@echo doc - builds "doxygen" documentation
	@echo clean - cleans the whole project of compiled files
	@echo ""
	@echo NOTE: eurobot2k17.elf eurobot2k17.bin and generated.$$(BOARD).ld
	@echo ""
	@echo Variables used by this project\'s Makefile:
	@echo ""
	@echo BOARD - defines the board for which the code is compiled
	@echo CC - compiler to be used
	@echo CFLAGS - user configurable compiler flags
	@echo DESTDIR - a directory where the resulting elf and bin binaries as well as the linker script
	@echo SRC - path to the project\'s source code
	@echo STLINK - flash utility from st-link package
	@echo OBJCOPY - objcopy from the utilised toolchain
	@echo ""
	@echo The default values of these variables:
	@echo ""
	@echo BOARD := STM32F407VG
	@echo CC := arm-none-eabi-gcc
	@echo CFLAGS := -Os -g -Wall -Wextra -pednatic -x c -std=c99
	@echo DESTDIR := $$(SRC)build/
	@echo DOXYGEN := doxygen
	@echo STLINK := st-flash
	@echo OBJCOPY := arm-none-eabi-objcopy
	@echo SRC is not set
	@echo ""
	@echo NOTE: If you decide to set $$(SRC) or $$(DESTDIR) to something, mak sure you include the trailing slash

# Include all implicit rules and dependencies
include $(SRC)make_def_rules.mk
-include $(DEPS)
.PHONY: doc flash help
