#include "lcd.h"

static void lcd_enable_pulse(void) {
    LCD_CTRL_PORT |= (1 << LCD_EN_PIN);
    _delay_us(1);
    LCD_CTRL_PORT &= ~(1 << LCD_EN_PIN);
    _delay_us(100);
}

void lcd_command(uint8_t command) {
    LCD_DATA_PORT = command;
    LCD_CTRL_PORT &= ~(1 << LCD_RS_PIN); // RS = 0 for command
    LCD_CTRL_PORT &= ~(1 << LCD_RW_PIN); // RW = 0 for write
    lcd_enable_pulse();
    _delay_ms(2);
}

void lcd_data(uint8_t data) {
    LCD_DATA_PORT = data;
    LCD_CTRL_PORT |= (1 << LCD_RS_PIN);  // RS = 1 for data
    LCD_CTRL_PORT &= ~(1 << LCD_RW_PIN); // RW = 0 for write
    lcd_enable_pulse();
}

void lcd_init(void) {
    LCD_DATA_DDR = 0xFF;
    LCD_CTRL_DDR |= (1 << LCD_RS_PIN) | (1 << LCD_RW_PIN) | (1 << LCD_EN_PIN);

    _delay_ms(50); // Initial power-up delay

    lcd_command(LCD_FUNCTIONSET | LCD_8BITMODE | LCD_2LINE);
    lcd_command(LCD_DISPLAYCONTROL | LCD_DISPLAYON);
    lcd_clear();
    lcd_command(LCD_ENTRYMODESET | 0x02); // Increment cursor
}

void lcd_print(const char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? 0x00 : 0x40;
    address += col;
    lcd_command(LCD_SETDDRAMADDR | address);
}

void lcd_clear(void) {
    lcd_command(LCD_CLEARDISPLAY);
    _delay_ms(2);
}
