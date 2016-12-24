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

OBJCOPY := arm-none-eabi-objcopy
CC := arm-none-eabi-gcc
AS := arm-none-eabi-as
ifeq ($(DEBUG),0)
	CFLAGS := -Os -Wall -Wextra -Wno-main -pedantic -std=c99
else
	CFLAGS := -Og -g -Wall -Wextra -Wno-main -pedantic -std=c99
endif
ASFLAGS := --warn
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16
BOARD := STM32F407VG

LINK_GROUP := -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LINK_PATH := -L$(STARTDIR)libopencm3/lib
LINK_LIB := -lopencm3_stm32f4

DOXYGEN := doxygen
DOXYFILE := $(STARTDIR)Doxyfile
STLINK := st-flash
MKDIR_P := mkdir -p

ifeq ($(DEBUG),0)
	FLASH_TGT := $(BINDIR)eurobot2k17.bin
else
	FLASH_TGT := $(BINDIR)eurobot2k17.elf
endif
