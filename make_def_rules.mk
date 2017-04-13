# Implicit rule for compiling object files and generating dependency rules

$(ASMDIR)/%.s: $(SRCDIR)/%.c
	$(VECHO) "Compiling $<"
	@$(MKDIR_P) $(@D) $(subst asm,dep,$(@D))
	$(CC) $(CFLAGS) $(MFLAGS) -MD -MP -x c $(INCLUDES) -S $< -o $@
	@mv $(subst .s,.d,$@) $(subst asm,dep,$(subst .s,.d,$@))

$(OBJDIR)/%.o: $(ASMDIR)/%.s
	@$(MKDIR_P) $(@D)
	$(AS) $(ASFLAGS) $(MFLAGS) $(INCLUDES) $< -o $@
