include $(CURDIR)/make_def_vars.mk

include $(SRCDIR)/Makefile

OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
ASM := $(SRC:%.c=$(ASMDIR)/%.s)
DEPS := $(SRC:%.c=$(DEPDIR)/%.d)

include $(SRCDIR)/libs/asm_src.mk

all: bin

bin: $(BINDIR)/eurobot2k17.bin

# Bin file will be flashed onto the STM32F4-Discovery board
$(BINDIR)/eurobot2k17.bin: $(BINDIR)/eurobot2k17.elf
	@$(MKDIR_P) $(@D)
	$(OBJCOPY) -Obinary $< $@

# Compile the executable using every .o file created and the generated linker script
$(BINDIR)/eurobot2k17.elf : $(OBJ)
	$(VECHO) "Linking $@"
	@$(MKDIR_P) $(@D)
	$(CC) --specs=nano.specs --static -T$(STARTDIR)/ldscript/stm32f4_freertos.ld $(MFLAGS) -Wl,-Map=$(DESTDIR)/eurobot2k17.map -Wl,--gc-sections $(OBJ) $(LINK_GROUP) -o $@

# Generate all assembly files
assembly: $(ASM)

# Use make flash to flash the bin file onto STM32F4
flash: $(FLASH_TGT)
	$(VECHO) "Flashing $@"
	$(OPENOCD) -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "reset_config srst_only separate srst_nogate srst_open_drain connect_assert_srst" -c "program $(FLASH_TGT) verify reset exit $(FLASH_OFFSET)"


# Make the documentation for the code - currently invalid
doc:
	$(VECHO) "Generating documentation"
	$(DOXYGEN) $(DOXYFILE) &>/dev/null
	@$(MKDIR_P) $(DOCDIR)
	@$(RM) -rf $(DOCDIR)/latex $(DOCDIR)/html
	@mv $(STARTDIR)/latex $(DOCDIR)
	@mv $(STARTDIR)/html $(DOCDIR)

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

pi-flash: bin
	$(VECHO) "Copying executable to RPi"
	$(SCP) $(FLASH_TGT) $(PI_USERNAME)@$(PI_IP):bin/
	$(VECHO) "Flashing executable"
	$(SSH) $(PI_USERNAME)@$(PI_IP) $(PI_FLASH_CMD)

clean:
	$(VECHO) "Cleaning dependency directory"
	$(RM) -rf $(DEPDIR)/core
	$(RM) -rf $(DEPDIR)/drivers
	$(RM) -rf $(DEPDIR)/executors
	$(RM) -rf $(DEPDIR)/initialisation
	$(RM) -rf $(DEPDIR)/tasks
	$(RM) -rf $(DEPDIR)/utils
	$(RM) -rf $(DEPDIR)/main.d
	$(VECHO) "Cleaning binaries directory"
	$(RM) -rf $(BINDIR)
	$(RM) -rf $(DESTDIR)/eurobot2k17.map
	$(VECHO) "Cleaning object directory"
	$(RM) -rf $(OBJDIR)/core
	$(RM) -rf $(OBJDIR)/drivers
	$(RM) -rf $(OBJDIR)/executors
	$(RM) -rf $(OBJDIR)/initialisation
	$(RM) -rf $(OBJDIR)/tasks
	$(RM) -rf $(OBJDIR)/utils
	$(RM) -rf $(OBJDIR)/main.o
	$(VECHO) "Cleaning assembly directory"
	$(RM) -rf $(ASMDIR)/core
	$(RM) -rf $(ASMDIR)/drivers
	$(RM) -rf $(ASMDIR)/executors
	$(RM) -rf $(ASMDIR)/initialisation
	$(RM) -rf $(ASMDIR)/tasks
	$(RM) -rf $(ASMDIR)/utils
	$(RM) -rf $(ASMDIR)/main.s

clean-all:
	@$(VECHO) "Cleaning all files"
	$(RM) -rf $(STARTDIR)/build/

# Include all implicit rules and dependencies
include $(STARTDIR)/make_def_rules.mk
-include $(DEPS)

.PHONY: doc flash help assembly bin clean clean-all all pi-flash
