# Implicit rule for compiling object files and generating dependency rules
%.o: %.c
	$(CC) $(FINAL_CFLAGS) $(MFLAGS) -MD -c $< -o $@


clean:
	rm -rf $(DEPS)
	rm -rf $(OBJ)
	rm -rf ${SRC}main.elf
	rm -rf ${SRC}main.bin
	rm -rf ${SRC}generated.${BOARD}.ld

.PHONY: clean
