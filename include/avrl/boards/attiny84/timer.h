//struct timer_conf TIMER0 = {
    //.control_a = &TCCR0A,
    //.control_b = &TCCR0B,
    //.counter = &TCNT0,
    //.compare_a = &OCR0A,
    //.compare_b = &OCR0B,
    //.int_mask = &TIMSK0,
    //.int_flag = &TIFR0,
//};
#define TIMER0_CRA TCCR0A
#define TIMER0_CRB TCCR0B
