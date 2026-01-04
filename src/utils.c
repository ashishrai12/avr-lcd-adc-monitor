#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

float calculate_sensor_value(uint8_t adc_val) {
    // Formula from original code: b = ((a/255)*5)*100
    // This scales 0-255 to 0-500.
    return ((float)adc_val / 255.0f) * 5.0f * 100.0f;
}

void format_float(float value, char *buffer, int decimals) {
    // dtostrf is standard in avr-libc for float to string
    // Usage: dtostrf(float_value, min_width, precision, string_buffer)
    dtostrf(value, 4, decimals, buffer);
}
