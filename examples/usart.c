#include "gpio.h"
#include "usart.h"

int main(void)
{
    usart_set_baudrate(USART0, 9600);
    usart_set_mode(USART0, USART_MODE_ASYNCHRONOUS);
    usart_set_parity(USART0, USART_PARITY_NONE);
    usart_set_databits(USART0, 8);
    usart_set_stopbits(USART0, 1);

    usart_set_direction(USART0, USART_DIRECTION_RX | USART_DIRECTION_TX);

    uint8_t data;
    while (1)
    {
        data = usart_read_blocking(USART0);
        usart_send_blocking(USART0, data);
    }

    return 0;
}
