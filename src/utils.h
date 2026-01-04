#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>

/**
 * @brief Converts an 8-bit ADC value to a scaled voltage/temperature value.
 * Logic: (adc_val / 255.0) * 5.0 * 100.0
 * 
 * @param adc_val The unscaled ADC reading (0-255).
 * @return float The calculated value.
 */
float calculate_sensor_value(uint8_t adc_val);

/**
 * @brief Formats a float value into a string with specified precision.
 * 
 * @param value The float value to format.
 * @param buffer The destination buffer.
 * @param decimals Number of decimal places.
 */
void format_float(float value, char *buffer, int decimals);

#endif /* UTILS_H_ */
