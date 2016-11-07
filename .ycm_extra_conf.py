def FlagsForFile( filename, **kwargs ):
    return { 'flags': [
    '-x',
    'c',
    '-DSTM32F4',
    '-DSTM32F407VG',
    '-DSTM32F4CCM',
    '-Wall',
    '-Wextra',
    '-Wno-main',
    '-std=c99',
    '-I',
    'libopencm3/include/',
    '-isystem',
    '/usr/lib/gcc/arm-none-eabi/6.2.0/include',
    '-isystem',
    '/usr/lib/gcc/arm-none-eabi/6.2.0/include-fixed',
    '-isystem',
    '/usr/arm-none-eabi/include',
    '-I.'
] }
