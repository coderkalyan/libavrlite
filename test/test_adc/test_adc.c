/*
 * This file contains unit tests for making
 * sure that the ADC functionality in libavrlite
 * works as intended.
 *
 * Only tests constants for now. Will probably add
 * legit tests once timer/pwm support exists.
 */

#include <util/delay.h>
#include <avrl/adc.h>
#include <unity.h>

void test_adc_numbers(void) {
    /* Make sure the adc number constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, ADC0);
    TEST_ASSERT_EQUAL(1, ADC1);
    TEST_ASSERT_EQUAL(2, ADC2);
    TEST_ASSERT_EQUAL(3, ADC3);
    TEST_ASSERT_EQUAL(4, ADC4);
    TEST_ASSERT_EQUAL(5, ADC5);
}

void test_adc_refs(void) {
    /* Make sure the adc reference constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, ADC_REFERENCE_AREF);
    TEST_ASSERT_EQUAL(1, ADC_REFERENCE_AVCC);
    TEST_ASSERT_EQUAL(3, ADC_REFERENCE_1V1);
}

void test_adc_adjust_constants(void) {
    /* Make sure the adc adjust constants weren't
     * changed by accident. */
    TEST_ASSERT_EQUAL(0, ADC_ADJUST_RIGHT);
    TEST_ASSERT_EQUAL(1, ADC_ADJUST_LEFT);
}

int main() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    _delay_ms(2000);

    UNITY_BEGIN();    // Start tests

    RUN_TEST(test_adc_numbers);
    RUN_TEST(test_adc_refs);
    RUN_TEST(test_adc_adjust_constants);

    UNITY_END();
}
