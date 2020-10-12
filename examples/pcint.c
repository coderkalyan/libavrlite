#include <util/delay.h>
#include <avr/interrupt.h>
#include <avrl/gpio.h>

int main(void)
{
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);
    gpio_mode_setup(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, GPIO7);

    gpio_set(GPIOB, GPIO4);

    gpio_pcint_enable_port(PCINT_GPIOD);
    gpio_pcint_enable_pin(PCINT_GPIOD, GPIO7);

    sei();

    while (1) {
        gpio_toggle(GPIOB, GPIO4);
        _delay_ms(500);
    }
}

ISR(ISR_PCINT_GPIOD) {
    gpio_toggle(GPIOB, GPIO5);
}
