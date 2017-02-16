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
	CFLAGS := -Og -g -Wall -Wextra -Wno-main -std=c11
endif
ASFLAGS := --warn
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16
BOARD := STM32F407VG

LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LINK_PATH := -L$(STARTDIR)libopencm3/lib
LINK_LIB := -lopencm3_stm32f4

DOXYFILE := $(STARTDIR)Doxyfile
ifeq ($V,1)
	DOXYGEN := doxygen
	OPENOCD := openocd
	OBJCOPY := arm-none-eabi-objcopy
	CC := arm-none-eabi-gcc
	AS := arm-none-eabi-as
	VECHO := @true
else
	DOXYGEN := @doxygen
	OPENOCD := @openocd
	OBJCOPY := @arm-none-eabi-objcopy
	CC := @arm-none-eabi-gcc
	AS := @arm-none-eabi-as
	VECHO := @echo
endif

ifeq ($(DEBUG),0)
	FLASH_TGT := $(BINDIR)eurobot2k17.bin
	FLASH_OFFSET := 0x08000000
else
	FLASH_TGT := $(BINDIR)eurobot2k17.elf
endif

MKDIR_P := @mkdir -p
