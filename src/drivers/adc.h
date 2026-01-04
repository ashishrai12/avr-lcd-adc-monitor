#ifndef ADC_H_
#define ADC_H_

#include "../config.h"

// ADC Reference Selection
#define ADC_REF_AREF    0x00
#define ADC_REF_AVCC    0x40
#define ADC_REF_INTERNAL 0xC0

// Prescaler Selection
#define ADC_PRESCALER_2   0x01
#define ADC_PRESCALER_4   0x02
#define ADC_PRESCALER_8   0x03
#define ADC_PRESCALER_16  0x04
#define ADC_PRESCALER_32  0x05
#define ADC_PRESCALER_64  0x06
#define ADC_PRESCALER_128 0x07

void adc_init(void);
uint16_t adc_read(uint8_t channel);

#endif /* ADC_H_ */
