#ifndef LCD_H_
#define LCD_H_

#include "../config.h"
#include <util/delay.h>

// LCD Commands
#define LCD_CLEARDISPLAY   0x01
#define LCD_RETURNHOME     0x02
#define LCD_ENTRYMODESET   0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT    0x10
#define LCD_FUNCTIONSET    0x20
#define LCD_SETCGRAMADDR   0x40
#define LCD_SETDDRAMADDR   0x80

// Flags for display on/off control
#define LCD_DISPLAYON      0x04
#define LCD_CURSORON       0x02
#define LCD_BLINKON        0x01

// Flags for function set
#define LCD_8BITMODE       0x10
#define LCD_2LINE          0x08
#define LCD_5x10DOTS       0x04

void lcd_init(void);
void lcd_command(uint8_t command);
void lcd_data(uint8_t data);
void lcd_print(const char *str);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_clear(void);

#endif /* LCD_H_ */
