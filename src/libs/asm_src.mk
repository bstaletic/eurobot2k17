OBJ += $(OBJDIR)/libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.o

$(OBJDIR)/libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.o: $(SRCDIR)/libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.s
	$(VECHO) "Compiling $<"
	@$(MKDIR_P) $(@D)
	$(AS) $(ASFLAGS) $(MFLAGS) $(INCLUDES) $< -o $@
