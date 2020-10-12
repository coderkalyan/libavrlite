#include <avrl/adc.h>

void adc_enable()
{
    ADC_ENR |= (1 << ADC_EN_BIT);
}

void adc_disable()
{
    ADC_ENR &= ~(1 << ADC_EN_BIT);
}

void adc_set_clock(uint32_t rate)
{
    uint8_t scale = F_CPU / rate;
    uint8_t prescaler = 1;
    while ((scale >> 1) >= 2) {
        scale = scale >> 1;
        prescaler++;
    }

    ADC_SCR |= (prescaler << ADC_SCALE_BIT);
}

void adc_set_ref(uint8_t ref)
{
    ADC_REFR |= (ref << ADC_REF_BIT);
}

void adc_set_adjust(uint8_t adjust)
{
    ADC_ADJR |= (adjust << ADC_ADJ_BIT);
}

uint16_t adc_read(int pin)
{
    ADC_MUXR |= (pin << ADC_MUX_BIT);
    ADC_SCR |= (1 << ADC_SCR_BIT);

    while (ADC_SCR & (1 << ADC_SCR_BIT));

    return (ADC);
}
