SRC += $(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c

#ASRC_DIR := arm
#ASRC_DIR := gcc
ASRC_DIR := iar

OBJ += $(OBJDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)/startup_stm32f407xx.o

$(OBJDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)/startup_stm32f407xx.o: $(SRCDIR)libs/CMSIS/Device/ST/STM32F4xx/Source/Templates/$(ASRC_DIR)startup_stm32f407xx.s
	@echo AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaA
	$(AS) $< --warn -o $@
