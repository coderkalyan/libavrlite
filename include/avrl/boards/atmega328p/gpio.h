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

#define GPIO_EXINTCB(interrupt) (interrupt << 1)

#define GPIO_PCMSKR(port) _SFR_MEM8(0x6B + port)

#define PCCR PCICR
#define PCINT_GPIOD PCIE2
#define PCINT_GPIOC PCIE1
#define PCINT_GPIOB PCIE0

#define FEAT_EXINT
#define ISR_EXINT0 INT0_vect
#define ISR_EXINT1 INT1_vect
#define ISR_PCINT_GPIOD PCINT2_vect
#define ISR_PCINT_GPIOC PCINT1_vect
#define ISR_PCINT_GPIOB PCINT0_vect
