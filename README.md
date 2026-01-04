# LCD_ADC_AVR

This project acts as an AVR firmware for reading analog values (ADC) and displaying them on a 16x2 LCD.

## Refactoring Overview

The codebase has been refactored from a monolithic script into a modular C project structure to improve readability, maintainability, and scalability.

### Directory Structure

```
LCD_ADC_AVR/
├── src/
│   ├── drivers/
│   │   ├── lcd.c       # LCD driver implementation
│   │   ├── lcd.h       # LCD driver interface
│   │   ├── adc.c       # ADC driver implementation
│   │   └── adc.h       # ADC driver interface
│   ├── config.h        # Pin configurations and constants
│   ├── utils.c         # Helper functions for math/formatting
│   ├── utils.h         # Helper function interfaces
│   └── main.c          # Main application loop
├── tests/
│   └── test_logic.py   # Python unit tests for calculation logic
├── visualization/
│   └── visualize_transfer.py # Script to plot sensor response curve
└── README.md
```

## Features

1.  **Hardware Abstraction**: LCD and ADC logic are separated into dedicated drivers.
2.  **Configuration**: All pin mappings (LCD Data/Control ports, ADC Channel) are centralized in `config.h`.
3.  **Visualization**: A Python script is provided to visualize the ADC transfer function.
4.  **Testing**: Unit tests ensure the core mathematical logic is correct.

## How to Compile

This project requires `avr-gcc` and `avr-libc`.

Example compilation command:
```bash
avr-gcc -mmcu=atmega32 -Os src/main.c src/drivers/lcd.c src/drivers/adc.c src/utils.c -o main.elf
```

## How to Test

Run the python test suite to verify the calculation logic:

```bash
python tests/test_logic.py
```

## Visualization

Generate a response curve plot:

```bash
python visualization/visualize_transfer.py
```
