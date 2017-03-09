ifeq ($(DEBUG),0)
	DESTDIR := $(STARTDIR)build/release/
else
	DESTDIR := $(STARTDIR)build/debug/
endif

OBJDIR := $(DESTDIR)obj/
DOCDIR := $(DESTDIR)doc/
BINDIR := $(DESTDIR)bin/
ASMDIR := $(DESTDIR)asm/
DBGDIR := $(DESTDIR)debug/
SRCDIR := $(STARTDIR)src/
DEPDIR := $(DESTDIR)dep/

ifeq ($(DEBUG),0)
	CFLAGS := -Os -Wall -Wextra -Wno-main -std=c11
else
	CFLAGS := -Og -g -Wall -Wextra -Wno-main -std=c11 -w
endif
ASFLAGS := --warn
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16
BOARD := STM32F407VG

LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

DOXYFILE := $(STARTDIR)Doxyfile
ifeq ($V,1)
	DOXYGEN := doxygen
	OPENOCD := openocd
	OBJCOPY := arm-none-eabi-objcopy
	CC := arm-none-eabi-gcc
	AS := arm-none-eabi-as
	VECHO := @true
	RM := rm
	SCP := scp
	SSH := ssh
else
	DOXYGEN := @doxygen
	OPENOCD := @openocd
	OBJCOPY := @arm-none-eabi-objcopy
	CC := @arm-none-eabi-gcc
	AS := @arm-none-eabi-as
	VECHO := @echo
	RM := @rm
	SCP := scp
	SSH := ssh
endif

ifeq ($(DEBUG),0)
	FLASH_TGT := $(BINDIR)eurobot2k17.bin
	FLASH_OFFSET := 0x08000000
else
	FLASH_TGT := $(BINDIR)eurobot2k17.elf
endif

MKDIR_P := @mkdir -p

# Rspberry Pi variables
PI_USERNAME := pi
PI_IP := 192.168.10.115

ifeq ($(DEBUG),0)
	PI_FLASH_TGT := bin/eurobot2k17.bin
else
	PI_FLASH_TGT := bin/eurobot2k17.elf
endif

PI_FLASH_CMD := 'openocd -f interface/stlink-v2-1.cfg -f target/stm32f4x.cfg -c "reset_config srst_only separate srst_nogate srst_open_drain connect_assert_srst" -c "program $(PI_FLASH_TGT) verify reset exit $(FLASH_OFFSET)"'
