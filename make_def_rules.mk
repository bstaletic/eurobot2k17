# Implicit rule for compiling object files and generating dependency rules
%.o: %.c
	$(CC) $(FINAL_CFLAGS) $(MFLAGS) -MD -c $< -o $@


clean: doc-clean
	rm -rf $(DEPS)
	rm -rf $(OBJ)
	rm -rf $(DESTDIR)eurobot2k17.elf
	rm -rf $(DESTDIR)eurobot2k17.bin
	rm -rf $(DESTDIR)generated.$(BOARD).ld
	rm -rf $(DESTDIR)html
	rm -rf $(DESTDIR)latex
	rm -rf eurobot2k17.map

doc-clean:
	rm -rf $(DESTDIR)html
	rm -rf $(DESTDIR)latex

.PHONY: clean doc-clean
