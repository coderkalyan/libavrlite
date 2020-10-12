/*
 * This example uses libavrlite's gpio functions
 * to flash the built-in LED on the Arduino board (port B, pin 7).
 */
#include "avrl/gpio.h"
#include "util/delay.h"

// Define port and pin constants
const int GPIO_PORT = GPIOB;
const int GPIO_PIN = GPIO5;

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

    // // The same thing, but with the toggle() function
    // while (1) {
    //     // toggle GPIO pin (led toggle)
    //     gpio_toggle(GPIO_PORT, GPIO_PIN);
    //
    //     // wait 1000ms (busy wait)
    //     _delay_ms(1000);
    // }

    // // The same thing, but with the write() function
    // while (1) {
    //     // write gpio HI (led on)
    //     gpio_write(GPIO_PORT, GPIO_PIN, GPIO_HIGH);
    //
    //     // wait 1000ms (busy wait)
    //     _delay_ms(1000);
    //
    //     // write gpio LO (led off)
    //     gpio_write(GPIO_PORT, GPIO_PIN, GPIO_LOW);
    //
    //     // wait 1000ms (busy wait)
    //     _delay_ms(1000);
    // }
}
