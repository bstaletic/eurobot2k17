include $(PROJDIR)/make_def.mk

OBJ := main.o

main.bin: main.elf
	arm-none-eabi-objcopy -Obinary $< $@

main.elf : generated.$(BOARD).ld $(OBJ)
	$(CC) --static -nostartfiles -Tgenerated.$(BOARD).ld $(MFLAGS) -Wl,-Map=main.map -Wl,--gc-sections $(LINK_PATH) $(OBJ) $(LINK_LIB) $(LINK_GROUP) -o $@

generated.$(BOARD).ld :
	$(CC) -E $(CFLAGS) -P -E ${PROJDIR}/libopencm3/ld/linker.ld.S > $@

flash: main.bin
	st-link write $< 0x8000000

dodoc:
	doxygen $(DOXYFILE)

.PHONY: dodoc flash
