/*
 * This file contains unit tests for making
 * sure that the basic GPIO functionality in libavrlite
 * works as intended by flashing the builtin LED.
 */

#include <util/delay.h>
#include "avrl/gpio.h"
#include <unity.h>

// Define builtin LED pin num
const uint8_t LED_PORT = GPIOB;
const uint8_t LED_PIN = GPIO5;

void test_pin_numbers(void) {
    /* Make sure the pin number constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, GPIO0);
    TEST_ASSERT_EQUAL(1, GPIO1);
    TEST_ASSERT_EQUAL(2, GPIO2);
    TEST_ASSERT_EQUAL(3, GPIO3);
    TEST_ASSERT_EQUAL(4, GPIO4);
    TEST_ASSERT_EQUAL(5, GPIO5);
    TEST_ASSERT_EQUAL(6, GPIO6);
    TEST_ASSERT_EQUAL(7, GPIO7);
}

void test_gpio_mode_constants(void) {
    /* Make sure the gpio mode constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, GPIO_MODE_INPUT);
    TEST_ASSERT_EQUAL(1, GPIO_MODE_OUTPUT);
}

void test_gpio_pupd_constants(void) {
    /* Make sure the gpio pullup constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, GPIO_PUPD_NONE);
    TEST_ASSERT_EQUAL(1, GPIO_PUPD_PULLUP);
}

void test_led_state_high(void) {
    /* Verify that GPIO can be set HI properly. */
    gpio_set(LED_PORT, LED_PIN);
    _delay_ms(1000);
    TEST_ASSERT_EQUAL(1, gpio_get(LED_PORT, LED_PIN));
}

void test_led_state_low(void) {
    /* Verify that GPIO can be set LO properly. */
    gpio_clear(LED_PORT, LED_PIN);
    _delay_ms(1000);
    TEST_ASSERT_EQUAL(0, gpio_get(LED_PORT, LED_PIN));
}

void test_led_state_toggle(void) {
    /* Verify that GPIO can be toggled properly. */
    uint8_t gpio = gpio_get(LED_PORT, LED_PIN);
    gpio_toggle(LED_PORT, LED_PIN);
    _delay_ms(1000);
    TEST_ASSERT_EQUAL(!gpio, gpio_get(LED_PORT, LED_PIN));
}

int main() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    _delay_ms(2000);

    UNITY_BEGIN();    // Start tests
    RUN_TEST(test_pin_numbers);
    RUN_TEST(test_gpio_mode_constants);
    RUN_TEST(test_gpio_pupd_constants);

    // Setup the LED pin
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);

    // Reset it
    RUN_TEST(test_led_state_high);
    RUN_TEST(test_led_state_low);

    // Toggle it on and off
    RUN_TEST(test_led_state_toggle);
    RUN_TEST(test_led_state_toggle);

    UNITY_END();
    return 0;
}

