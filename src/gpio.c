#include <avrl/gpio.h>

void gpio_mode_setup(uint8_t port, uint8_t mode, uint8_t pupd, uint8_t pin)
{
    GPIO_DDR(port) = (GPIO_DDR(port) & (~(1 << pin))) | (mode << pin);
    gpio_write(port, pin, pupd);
}

void gpio_set(uint8_t port, uint8_t pin)
{
    GPIO_PORT(port) |= (1 << pin);
}

void gpio_clear(uint8_t port, uint8_t pin)
{
    GPIO_PORT(port) &= ~(1 << pin);
}

void gpio_toggle(uint8_t port, uint8_t pin)
{
    GPIO_PORT(port) ^= (1 << pin);
}

void gpio_write(uint8_t port, uint8_t pin, uint8_t state)
{
    GPIO_PORT(port) = (GPIO_PORT(port) & (~(1 << pin))) | (state << pin);
}

uint8_t gpio_get(uint8_t port, uint8_t pin)
{
    return (GPIO_PIN(port) & (1 << pin)) ? GPIO_HIGH : GPIO_LOW;
}
