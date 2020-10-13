#include <util/delay.h>
#include <avr/interrupt.h>
#include <avrl/adc.h>
#include <avrl/usart.h>

uint16_t data;
char buffer[5];

int main(void)
{
    usart_set_baudrate(USART0, 9600);
    usart_set_mode(USART0, USART_MODE_ASYNCHRONOUS);
    usart_set_parity(USART0, USART_PARITY_NONE);
    usart_set_databits(USART0, 8);
    usart_set_stopbits(USART0, 1);
    usart_set_direction(USART0, USART_DIRECTION_TX);

    adc_enable();
    adc_set_clock(125000);
    adc_set_ref(ADC_REFERENCE_AVCC);
    adc_int_enable();

    sei();

    while (1) {
        adc_start_conversion(0);
        _delay_ms(500);
    }
}

ISR(ISR_ADC)
{
    data = adc_read();
    sprintf(buffer, "%d", data);
    usart_putln(USART0, buffer);
}
