include $(STARTDIR)make_def_vars.mk

include $(SRCDIR)Makefile
include $(SRCDIR)initialisation/Makefile
include $(SRCDIR)drivers/Makefile
include $(SRCDIR)executors/Makefile
include $(SRCDIR)core/Makefile
include $(SRCDIR)utils/Makefile
include $(SRCDIR)tasks/Makefile
include $(SRCDIR)executors/Makefile
include $(SRCDIR)core/Makefile

OBJ := $(subst src/,,$(SRC:%.c=$(OBJDIR)%.o))
ASM := $(subst src/,,$(SRC:%.c=$(ASMDIR)%.s))
DEPS := $(subst src/,,$(SRC:%.c=$(DEPDIR)%.d))

all: bin

bin: $(BINDIR)eurobot2k17.bin


# Bin file will be flashed onto the STM32F4-Discovery board
$(BINDIR)eurobot2k17.bin: $(BINDIR)eurobot2k17.elf
	@$(MKDIR_P) $(@D)
	$(OBJCOPY) -Obinary $< $@

# Compile the executable using every .o file created and the generated linker script
$(BINDIR)eurobot2k17.elf : $(DESTDIR)generated.$(BOARD).ld $(OBJ)
	@$(MKDIR_P) $(@D)
	$(CC) --static -nostartfiles -T$(DESTDIR)generated.$(BOARD).ld $(MFLAGS) -Wl,-Map=$(DESTDIR)eurobot2k17.map -Wl,--gc-sections $(LINK_PATH) $(OBJ) $(LINK_LIB) $(LINK_GROUP) -o $@

# Generate the linker script
$(DESTDIR)generated.$(BOARD).ld :
	@$(MKDIR_P) $(@D)
	$(CC) -E $(CFLAGS) $(MFLAGS) -D_ROM=1024K -D_ROM_OFF=0x08000000 -D_RAM=128K -D_RAM_OFF=0x20000000 -D_CCM=64K -D_CCM_OFF=0x10000000 -P -E $(STARTDIR)libopencm3/ld/linker.ld.S > $@

# Generate all assembly files
assembly: $(ASM)

# Use make flash to flash the bin file onto STM32F4
flash: $(FLASH_TGT)
	$(OPENOCD) -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "reset_config srst_only separate srst_nogate srst_open_drain connect_assert_srst" -c "program $(FLASH_TGT) verify reset exit $(FLASH_OFFSET)"


# Make the documentation for the code - currently invalid
doc:
	$(DOXYGEN) $(DOXYFILE) 1>/dev/null
	@$(MKDIR_P) $(DOCDIR)
	@rm -rf $(DOCDIR)latex $(DOCDIR)html
	@mv $(STARTDIR)latex $(DOCDIR)
	@mv $(STARTDIR)html $(DOCDIR)

help:
	@echo Use "make flash" to quickly compile the binary and flash onto STM32
	@echo Possible make targets:
	@echo assembly - generates only the assembly files
	@echo bin - builds only the non-debug bin file
	@echo clean - cleans either the build or release directory
	@echo clean-all - cleans the whole project of compiled files
	@echo doc - builds "doxygen" documentation
	@echo flash - flashes the bin file onto STM32F4-Discovery
	@echo help - prints this help message
	@echo ""
	@echo To compile without the debugging symbols use DEBUG=0
	@echo ""
	@echo For more information about these variables check the README.md

clean:
	rm -rf $(DESTDIR)

clean-all:
	rm -rf $(STARTDIR)build/

# Include all implicit rules and dependencies
include $(STARTDIR)make_def_rules.mk
-include $(DEPS)

.PHONY: doc flash help assembly bin clean clean-all all
