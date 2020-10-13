#include <avr/interrupt.h>
#include <util/delay.h>
#include <avrl/gpio.h>
#include <avrl/usart.h>

int main(void)
{
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

    usart_set_baudrate(USART0, 9600);
    usart_set_mode(USART0, USART_MODE_ASYNCHRONOUS);
    usart_set_parity(USART0, USART_PARITY_NONE);
    usart_set_databits(USART0, 8);
    usart_set_stopbits(USART0, 1);

    usart_set_direction(USART0, USART_DIRECTION_RX | USART_DIRECTION_TX);

    usart_enable_rx_interrupt(USART0);

    uint8_t data;
    while (1)
    {
        gpio_toggle(GPIOB, GPIO5);
        _delay_ms(100);
    }

    return 0;
}

ISR(USART_RX_vect)
{
    uint8_t data = usart_read(USART0);
    usart_send(USART0, data);
}
