/*
 * This example uses libavrlite's gpio functions
 * to flash the built-in LED on the Arduino board (port B, pin 7).
 */
#include "avrl/gpio.h"
#include "util/delay.h"

// Define port and pin constants
const int GPIO_PORT = GPIOB;
const int GPIO_PIN = GPIO7;

int main() {
    // Setup the pin in OUTPUT mode
    gpio_mode_setup(GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN);
    while (1) {
        // set gpio HI (led on)
        gpio_set(GPIO_PORT, GPIO_PIN);

        // wait 1000ms (busy wait)
        _delay_ms(1000);

        // set gpio LO (led off)
        gpio_clear(GPIO_PORT, GPIO_PIN);

        // wait 1000ms (busy wait)
        _delay_ms(1000);
    }
}
