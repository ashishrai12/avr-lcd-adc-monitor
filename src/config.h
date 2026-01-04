#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

// LCD Configuration
#define LCD_DATA_PORT      PORTD
#define LCD_DATA_DDR       DDRD

#define LCD_CTRL_PORT      PORTC
#define LCD_CTRL_DDR       DDRC
#define LCD_RS_PIN         PC0
#define LCD_RW_PIN         PC1
#define LCD_EN_PIN         PC2

// ADC Configuration
#define ADC_CHANNEL        0

#endif /* CONFIG_H_ */
