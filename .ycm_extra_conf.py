def FlagsForFile( filename, **kwargs ):
    return { 'flags': [
    '-xc',
    '-Wall',
    '-Wextra',
    '-std=c11',
    '-isystem/usr/lib/gcc/arm-none-eabi/6.3.1/include',
    '-isystem/usr/lib/gcc/arm-none-eabi/6.3.1/include-fixed',
    '-isystem/usr/arm-none-eabi/include',
    '-Isrc/libs/STM32F4xx_HAL_Driver/Inc/',
    '-Isrc/libs/CMSIS/Device/ST/STM32F4xx/Include/',
    '-Isrc/libs/CMSIS/Include/',
    '-Isrc/initialisation/',
    '-Isrc/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/',
    '-Isrc/Middlewares/Third_Party/FreeRTOS/Source/include/',
    '-Isrc/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/',
] }
