# libavrlite: a thin abstraction library for the AVR platform

libavrlite is a thin AVR abstraction library which aims to provide abstractions
for AVR functions while maintaining minimal overhead and keeping the programmer
in control. It provides functions for common embedded programming tasks,
such as reading and writing serial/USART.

## Install
libavrlite is just a platformio library. To install the latest version
in your platformio project, simply use the package manager:
`pio lib install libavrlite`

## Features
libavrlite has many abstractions and utilities embedded programmers will find useful:

- GPIO abstractions
- USART serial read/write
- ISR (interrupt) macros
    - USART
    - EXINT
    - PCINT
- Hardware analog-digital converter
