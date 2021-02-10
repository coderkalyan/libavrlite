# libavrlite: a thin abstraction library for the AVR platform

libavrlite is a thin AVR abstraction library which aims to provide abstractions
for AVR functions while maintaining minimal overhead and keeping the programmer
in control. It provides functions for common embedded programming tasks,
such as reading and writing serial/USART. It is inspired by libopencm3, and has a
similar (but not compatible) API.

_Warning: libavrlite is currently in very early development. It does not support
all peripherals on AVR processors, and it is currently only tested on an Arduino Uno.
If you are interested in contributing additional board support, please let me know or
file a PR._

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

## Examples & Docs

For the examples, go to the [examples/ folder](examples/).
The project currently does not have documentation. Contribute some!
In the meantime, you can [read the header files](include/).
