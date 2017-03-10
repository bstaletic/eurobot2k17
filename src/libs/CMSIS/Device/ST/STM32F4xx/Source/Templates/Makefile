#SRC += $(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c

#ASRC_DIR := arm
ASRC_DIR := gcc
#ASRC_DIR := iar

OBJ += $(OBJDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)/startup_stm32f407xx.o

$(OBJDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)/startup_stm32f407xx.o: $(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)/startup_stm32f407xx.s
	$(VECHO) "Compiling $(subst .s,.o,$<)"
	@$(MKDIR_P) $(@D)
	$(AS) $(ASFLAGS) $(MFLAGS) -I$(SRCDIR) -I$(SRCDIR)libs/STM32F4xx_HAL_Driver/Inc/ -I$(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Include/ -I$(SRCDIR)libs/CMSIS/Include/ -I$(SRCDIR)initialisation -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/ -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/include/ -I$(SRCDIR)Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/ $< -o $@
