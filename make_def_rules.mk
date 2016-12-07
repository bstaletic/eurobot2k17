# Implicit rule for compiling object files and generating dependency rules

$(ASMDIR)%.s: $(SRCDIR)%.c
	$(MKDIR_P) $(@D) $(subst asm,dep,$(@D))
	$(CC) $(CFLAGS) $(MFLAGS) -MD -MP -x c -DSTM32F4 -DSTM32F407VG -DSTM32F4CCM -I$(SRCDIR) -Ilibopencm3/include -S $< -o $@
	mv $(subst .s,.d,$@) $(subst asm,dep,$(subst .s,.d,$@))

$(OBJDIR)%.o: $(ASMDIR)%.s
	@$(MKDIR_P) $(@D)
	$(AS) $(ASFLAGS) $(MFLAGS) -I$(SRCDIR) -Ilibopencm3/include $< -o $@
