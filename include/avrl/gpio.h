#include <avr/io.h>

#if defined(__AVR_ATmega328P__)
#include <avrl/boards/atmega328p/gpio.h>
#elif defined(__AVR_ATtiny84__)
#include <avrl/boards/attiny84/gpio.h>
#endif

#define GPIO0 0
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7

#define GPIO_PIN(port) _SFR_IO8(port)
#define GPIO_DDR(port) _SFR_IO8(port + 0x01)
#define GPIO_PORT(port) _SFR_IO8(port + 0x02)

#define GPIO_MODE_INPUT 0
#define GPIO_MODE_OUTPUT 1

#define GPIO_PUPD_NONE 0
#define GPIO_PUPD_PULLUP 1

#define GPIO_LOW 0
#define GPIO_HIGH 1

void gpio_mode_setup(uint8_t port, uint8_t mode, uint8_t pupd, uint8_t pin);

void gpio_set(uint8_t port, uint8_t pin);
void gpio_clear(uint8_t port, uint8_t pin);
void gpio_toggle(uint8_t port, uint8_t pin);
void gpio_write(uint8_t port, uint8_t pin, uint8_t state);
uint8_t gpio_get(uint8_t port, uint8_t pin);
