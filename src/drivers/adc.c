#include "adc.h"

void adc_init(void) {
    // Select Vref=AVcc (5V)
    ADMUX |= (1 << REFS0); 
    // Clear REFS1 to ensure AVcc
    ADMUX &= ~(1 << REFS1);

    // Left adjust result? 
    // The original code used ADLAR (Left Adjust) and read only ADCH for 8-bit precision.
    // We will stick to 10-bit default (Right Adjust) for better precision, 
    // but can map to 8-bit if needed to match original exact behavior.
    // However, "intuitive" modern code usually prefers full 10-bit resolution (0-1023).
    // EXCEPT: The user's formula `b = ((a/255)*5)` specifically expects 8-bit (0-255).
    // So let's use ADLAR to keep consistent behavior with the request to "refactor" not "change behavior".
    ADMUX |= (1 << ADLAR);

    // Enable ADC and set Prescaler to 128 (16MHz/128 = 125kHz)
    // 125kHz is within the recommended 50-200kHz range.
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t adc_read(uint8_t channel) {
    // Channel selection (safe masking)
    channel &= 0x07;
    ADMUX = (ADMUX & 0xF8) | channel;

    // Start Single Conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    // Return the ADC value.
    // Since ADLAR is set, the top 8 bits are in ADCH.
    // We strictly return ADCH to match the original logical flow of 0-255.
    return ADCH; 
}
