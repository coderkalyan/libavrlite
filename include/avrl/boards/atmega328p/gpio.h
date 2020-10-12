#include <avr/interrupt.h>

#define GPIO_PORT_B_BASE 0x03
#define GPIO_PORT_C_BASE 0x06
#define GPIO_PORT_D_BASE 0x09

#define GPIOB GPIO_PORT_B_BASE
#define GPIOC GPIO_PORT_C_BASE
#define GPIOD GPIO_PORT_D_BASE

#define EICR EICRA // external interrupt control register
#define EIMSKR EIMSK // external interrupt mask register

#define EXINT0 0
#define EXINT1 1

#define GPIO_INTMSKB(interrupt) (interrupt + 0)
#define GPIO_INTCB(interrupt) (interrupt << 1)

#define ISR_EXINT0 INT0_vect
#define ISR_EXINT1 INT1_vect
