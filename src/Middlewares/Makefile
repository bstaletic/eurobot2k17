SRC += Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/croutine.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/list.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/queue.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/tasks.c
SRC += Middlewares/Third_Party/FreeRTOS/Source/timers.c

#These files are generated by stm32cubemx, so the warnings are of no interest
$(ASMDIR)/Middlewares/%.s: $(SRCDIR)/Middlewares/%.c
	$(VECHO) "Compiling $<"
	@$(MKDIR_P) $(@D) $(subst asm,dep,$(@D))
	$(CC) $(CFLAGS) -Wno-unused-parameter $(MFLAGS) -MD -MP -x c $(INCLUDES) -S $< -o $@
	@mv $(subst .s,.d,$@) $(subst asm,dep,$(subst .s,.d,$@))
