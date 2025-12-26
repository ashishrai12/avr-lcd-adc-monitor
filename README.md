# LCD_ADC_AVR

1. Hardware Control (The LCD)The functions CMD(), DATA(), and LCD_INIT() handle the communication with an LCD screen (typically an industry-standard Hitachi HD44780 controller).PORTD is used as the Data Bus (sending the characters or commands).PORTC is used for Control Signals:PC0 (RS): Register Select. Low for commands, High for data.PC1 (RW): Read/Write. Kept Low (Write mode).PC2 (E): Enable pulse. This "clocks" the data into the LCD.
   
3. Analog-to-Digital Conversion (ADC)The code configures the microcontroller to read an analog signal on Pin A0 (ADMUX=0x00).It uses 8-bit resolution (ADLAR is set, and it reads only ADCH).The ADC is set to "Free Running" mode or manually re-triggered inside the Interrupt Service Routine (ISR(ADC_vect)).
   
4. The Math (Calculating Temperature/Voltage)Inside the while(1) loop, the code processes the raw digital value a:$$b = \left( \frac{a}{255} \times 5 \right) \times 100$$a/255 * 5: Converts the 8-bit digital value back into a voltage (0–5V).x 100: This suggests it is scaling for a sensor like the LM35, where 10mV = 1°C. Scaling by 100 turns 0.25V into "25.0".
   
5. Display LogicThe code performs some manual string formatting to display a decimal point:Integer Part: It takes the whole number (c), converts it to a string using itoa, and sends it to the LCD.Decimal Point: It manually sends the . character.Fractional Part: It calculates the remainder (d) and sends that as the decimals.Refresh: It waits 1 second (_delay_ms(1000)), clears the screen, and starts over.
