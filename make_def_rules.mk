# Implicit rule for compiling object files and generating dependency rules

$(ASMDIR)%.s: $(SRCDIR)%.c
	$(VECHO) "Compiling $(subst .c,.o,$<)"
	@$(MKDIR_P) $(@D) $(subst asm,dep,$(@D))
	$(CC) $(CFLAGS) $(MFLAGS) -MD -MP -x c -DSTM32F4 -DSTM32F407VG -DSTM32F4CCM -I$(SRCDIR) -I$(SRCDIR)libs/STM32F4xx_HAL_Driver/Inc/ -I$(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Include/ -I$(SRCDIR)libs/CMSIS/Include/ -I$(SRCDIR)initialisation -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/ -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/include/ -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/ -S $< -o $@
	@mv $(subst .s,.d,$@) $(subst asm,dep,$(subst .s,.d,$@))

$(OBJDIR)%.o: $(ASMDIR)%.s
	@$(MKDIR_P) $(@D)
	$(AS) $(ASFLAGS) $(MFLAGS) -I$(SRCDIR) -Ilibopencm3/include $< -o $@
