#include <avr/io.h>

// TODO: move this somewhere else, and abstract it a bit
//#define F_CPU 16000000UL

#define USART0_BASE 0xC0

#define USART0 USART0_BASE

#define USART_BHR(usart) _SFR_MEM8(usart + 0x05) // baudrate high register
#define USART_BLR(usart) _SFR_MEM8(usart + 0x04) // baudrate low register

#define USART_PR(usart) _SFR_MEM8(usart + 0x02) // parity register

#define USART_PARITY_BIT_BASE 4

#define USART_PARITY_NONE 0
#define USART_PARITY_EVEN 2
#define USART_PARITY_ODD 3
#define USART_PARITY_CLEAR 3


#define USART_DR(usart) _SFR_MEM8(usart + 0x01) // direction register
#define USART_DIRECTION_RX (1 << 4)
#define USART_DIRECTION_TX (1 << 3)

#define USART_SR(usart) _SFR_MEM8(usart + 0x02) // stop bits register
#define USART_STOPBITS_BIT_BASE 3

#define USART_DBR(usart) _SFR_MEM8(usart + 0x02) // data bits register
#define USART_DATABITS_BIT_BASE 1
#define USART_DATABITS_CLEAR 3

#define USART_TSR(usart) _SFR_MEM8(usart) // transmit status register
#define USART_TRANSMIT_BIT_BASE 5
#define USART_TDR(usart) _SFR_MEM8(usart + 0x06) // transmit data register

#define USART_RSR(usart) _SFR_MEM8(usart) // receive status register
#define USART_RECEIVE_BIT_BASE 7
#define USART_RDR(usart) _SFR_MEM8(usart + 0x06) // receive data register

#define USART_MR(usart) _SFR_MEM8(usart + 0x02) // mode register
#define USART_MODE_BIT_BASE 6
#define USART_MODE_ASYNCHRONOUS 0
#define USART_MODE_SYNCHRONOUS 1
#define USART_MODE_MSPIM 3
#define USART_MODE_CLEAR 3

#define USART_RIR(usart) _SFR_MEM8(usart + 0x01) // receive interrupt register
#define USART_RX_INTERRUPT 7

void usart_set_parity(uint8_t usart, uint8_t parity);
void usart_set_databits(uint8_t usart, uint8_t bits);
void usart_set_stopbits(uint8_t usart, uint8_t bits);
void usart_set_baudrate(uint8_t usart, uint32_t baud);
void usart_set_direction(uint8_t usart, uint8_t direction);
void usart_set_mode(uint8_t usart, uint8_t mode);
void usart_send(uint8_t usart, uint8_t data);
void usart_wait_send_ready(uint8_t usart);
void usart_send_blocking(uint8_t usart, uint8_t data);
uint8_t usart_read(uint8_t usart);
void usart_wait_recv_ready(uint8_t usart);
uint8_t usart_read_blocking(uint8_t usart);
void usart_enable_rx_interrupt(uint8_t usart);
void usart_disable_rx_interrupt(uint8_t usart);
