SRC := ${HOME}/eurobot2k17/
include $(SRC)make_def_vars.mk

# Bin file will be flashed onto the STM32F4-Discovery board
${DESTDIR}main.bin: ${DESTDIR}main.elf
	arm-none-eabi-objcopy -Obinary $< $@

# Compile the executable using every .o file created and the generated linker script
${DESTDIR}main.elf : generated.$(BOARD).ld $(OBJ)
	$(CC) --static -nostartfiles -Tgenerated.$(BOARD).ld $(MFLAGS) -Wl,-Map=main.map -Wl,--gc-sections $(LINK_PATH) $(OBJ) $(LINK_LIB) $(LINK_GROUP) -o $@

# Generate the linker script
${DESTDIR}generated.$(BOARD).ld :
	$(CC) -E $(FINAL_CFLAGS) -P -E ${SRC}libopencm3/ld/linker.ld.S > $@
	@rm -f linker.ld.d

# Use make flash to flash the bin file onto STM32F4
flash: ${DESTDIR}main.bin
	st-link write $< 0x8000000

# Make the documentation for the code - currently invalid
doc:
	doxygen $(DOXYFILE)

# Include all implicit rules and dependencies
include $(SRC)make_def_rules.mk
-include $(DEPS)
.PHONY: doc flash
