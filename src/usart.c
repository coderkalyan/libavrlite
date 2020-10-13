#include <avrl/gpio.h>
#include <avrl/usart.h>

void usart_set_baudrate(uint8_t usart, uint32_t baud)
{
    uint16_t prescaler = (((F_CPU / (baud * 16UL))) - 1);
    USART_BHR(usart) = prescaler >> 8;
    USART_BLR(usart) = prescaler;
}

void usart_set_direction(uint8_t usart, uint8_t direction)
{
    USART_DR(usart) = (USART_DR(usart) & (~direction)) | (direction);
}

void usart_set_parity(uint8_t usart, uint8_t parity)
{
    USART_PR(usart) &= ~((USART_PARITY_CLEAR << USART_PARITY_BIT_BASE));
    USART_PR(usart) |= (parity << USART_PARITY_BIT_BASE);
}

void usart_set_databits(uint8_t usart, uint8_t bits)
{
    USART_DBR(usart) &= ~((USART_DATABITS_CLEAR << USART_DATABITS_BIT_BASE));
    USART_DBR(usart) |= ((bits - 5) << USART_DATABITS_BIT_BASE);
}

void usart_set_stopbits(uint8_t usart, uint8_t bits)
{
    USART_SR(usart) = (USART_SR(usart) & (~(bits << USART_STOPBITS_BIT_BASE))) |
            (bits << USART_STOPBITS_BIT_BASE);
}

void usart_set_mode(uint8_t usart, uint8_t mode)
{
    USART_MR(usart) &= ~((USART_MODE_CLEAR << USART_MODE_BIT_BASE));
    USART_MR(usart) |= (mode << USART_MODE_BIT_BASE);
}

void usart_send(uint8_t usart, char data)
{
    USART_TDR(usart) = data;
}

void usart_wait_send_ready(uint8_t usart)
{
    while ((USART_TSR(usart) & (1 << USART_TRANSMIT_BIT_BASE)) == 0);
}

void usart_send_blocking(uint8_t usart, char data)
{
    usart_wait_send_ready(usart);
    usart_send(usart, data);
}

char usart_read(uint8_t usart)
{
    uint8_t data;
    data = USART_RDR(usart);
    return data;
}

void usart_wait_recv_ready(uint8_t usart)
{
    while ((USART_RSR(usart) & (1 << USART_RECEIVE_BIT_BASE)) == 0);
}

char usart_read_blocking(uint8_t usart)
{
    usart_wait_recv_ready(usart);
    return usart_read(usart);
}

void usart_enable_rx_interrupt(uint8_t usart)
{
    USART_RIR(usart) |= (1 << USART_RX_INTERRUPT);
}

void usart_disable_rx_interrupt(uint8_t usart)
{
    USART_RIR(usart) &= ~(1 << USART_RX_INTERRUPT);
}

void usart_enable_tx_complete_interrupt(uint8_t usart)
{
    USART_TIR(usart) |= (1 << USART_TX_INTERRUPT);
}

void usart_disable_tx_complete_interrupt(uint8_t usart)
{
    USART_TIR(usart) &= ~(1 << USART_TX_INTERRUPT);
}

void usart_enable_tx_ready_interrupt(uint8_t usart)
{
    USART_EIR(usart) |= (1 << USART_EMPTY_INTERRUPT);
}

void usart_disable_tx_ready_interrupt(uint8_t usart)
{
    USART_EIR(usart) &= ~(1 << USART_EMPTY_INTERRUPT);
}

void usart_puts(uint8_t usart, char *string)
{
    while (*string) {
        usart_send_blocking(usart, *string);
        string++;
    }
}

void usart_putln(uint8_t usart, char *string)
{
    usart_puts(usart, string);
    usart_puts(usart, "\r\n");
}
