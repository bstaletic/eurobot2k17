STARTDIR := $(CURDIR)
ifeq ($(DEBUG),0)
	DESTDIR := $(STARTDIR)/build/release
	FLASH_TGT := $(BINDIR)/eurobot2k17.bin
	FLASH_OFFSET := 0x08000000
else
	DESTDIR := $(STARTDIR)/build/debug
	FLASH_TGT := $(BINDIR)/eurobot2k17.elf
endif

OBJDIR := $(DESTDIR)/obj
DOCDIR := $(DESTDIR)/doc
BINDIR := $(DESTDIR)/bin
ASMDIR := $(DESTDIR)/asm
DBGDIR := $(DESTDIR)/debug
SRCDIR := $(STARTDIR)/src
DEPDIR := $(DESTDIR)/dep

ifeq ($(DEBUG),0)
	CFLAGS := -Ofast -Wall -Wextra -Wno-main -std=c11 -fdata-sections -ffunction-sections -fuse-ld=gold
else
	CFLAGS := -Og -g -Wall -Wextra -Wno-main -std=c11 -fdata-sections -ffunction-sections -fuse-ld=gold
endif
ASFLAGS := --warn
MFLAGS := -mfloat-abi=hard -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16

DOXYFILE := $(STARTDIR)/Doxyfile
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
INCLUDES := -I$(SRCDIR)/libs/STM32F4xx_HAL_Driver/Inc/ -I$(SRCDIR)/libs/CMSIS/Device/ST/STM32F4xx/Include/ -I$(SRCDIR)/libs/CMSIS/Include/ -I$(SRCDIR)/initialisation -I$(SRCDIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/ -I$(SRCDIR)/Middlewares/Third_Party/FreeRTOS/Source/include/ -I$(SRCDIR)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/
