#include <avr/io.h>

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5

#define ADC_MUXR ADMUX // adc mux register
#define ADC_MUX_BIT MUX0
#define ADC_ENR ADCSRA // adc enable register
#define ADC_EN_BIT ADEN
#define ADC_SCR ADCSRA // adc scale register
#define ADC_SCALE_BIT ADPS0
#define ADC_REFR ADMUX // adc reference voltage register
#define ADC_REF_BIT REFS0
#define ADC_ADJR ADMUX // adc adjust register
#define ADC_ADJ_BIT ADLAR
#define ADC_SCR ADCSRA // adc start conversion register
#define ADC_SCR_BIT ADSC
#define ADC_INTR ADCSRA
#define ADC_INTR_BIT ADIE

#define ADC_REFERENCE_AREF 0
#define ADC_REFERENCE_AVCC 1
#define ADC_REFERENCE_1V1 3

#define ADC_ADJUST_RIGHT 0
#define ADC_ADJUST_LEFT 1

#define ISR_ADC ADC_vect

void adc_enable();
void adc_disable();
void adc_set_clock(uint32_t rate);
void adc_set_ref(uint8_t ref);
void adc_set_adjust(uint8_t adjust);
void adc_start_conversion(uint8_t pin);
uint16_t adc_read();
void adc_wait_ready();
uint16_t adc_read_blocking(uint8_t pin);
void adc_int_enable();
void adc_int_disable();
