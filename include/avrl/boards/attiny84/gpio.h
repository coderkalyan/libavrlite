#define GPIO_PORT_A_BASE 0x19
#define GPIO_PORT_B_BASE 0x16

#define GPIOA GPIO_PORT_A_BASE
#define GPIOB GPIO_PORT_B_BASE

#define EICR GIFR
#define EIMSKR GIMSK

#define PCCR GIMSK

#define GPIO_PCMSKR(port) _SFR_MEM8(0x12 + (0xE * port))
