#include "config.h"
#include "drivers/lcd.h"
#include "drivers/adc.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
    // Initialization
    lcd_init();
    adc_init();

    // Setup initial display
    lcd_set_cursor(0, 0);
    lcd_print("Temp Sensor");
    _delay_ms(1000);
    lcd_clear();

    char display_buffer[16];
    uint8_t raw_adc;
    float sensor_value;

    while (1) {
        // 1. Read Data
        raw_adc = adc_read(ADC_CHANNEL);

        // 2. Process Data
        sensor_value = calculate_sensor_value(raw_adc);

        // 3. Display Data
        lcd_set_cursor(0, 0);
        lcd_print("Raw: ");
        // Using itoa for integer raw value
        itoa(raw_adc, display_buffer, 10);
        lcd_print(display_buffer);
        lcd_print("   "); // Clear trailing characters

        lcd_set_cursor(1, 0);
        lcd_print("Val: ");
        // Format calculated value to 2 decimal places
        format_float(sensor_value, display_buffer, 2);
        lcd_print(display_buffer);
        lcd_print("      ");

        // 4. Update Rate
        _delay_ms(500); 
    }

    return 0;
}
