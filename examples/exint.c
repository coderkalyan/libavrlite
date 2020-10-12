#include <util/delay.h>
#include <avr/interrupt.h>
#include <avrl/gpio.h>

int main(void)
{
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);
    gpio_mode_setup(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, GPIO3);

    gpio_set(GPIOB, GPIO4);

    gpio_exint_set_mode(EXINT1, EXINT_MODE_CHANGE);
    gpio_exint_enable(EXINT1);

    sei();

    while (1) {
        gpio_toggle(GPIOB, GPIO4);
        _delay_ms(500);
    }
}

ISR(ISR_EXINT1) {
    gpio_toggle(GPIOB, GPIO5);
}
