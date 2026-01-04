
#ifndef F_CPU                                                                             // To check whether the external                           frequency is defined earlier or not.
#define F_CPU 16000000UL                                                                 //To set the frequency at 16 MHZ.
#endif
#include<avr/io.h>                                                                                // HEADER files for AVR IC
#include<util/delay.h>                                                                          // Header for delay 

void CMD ()
{
PORTC&=~(1<<0);                                                                           // RS=0 for command data
PORTC&=~(1<<1);                                                                           // R/W = 0 for write
PORTC|=(1<<2);                                                                              // E = 1 for enabling LCD to read data
_delay_ms(10);
PORTC&=~(1<<2);                                                                           //E = o for disabling LCD to read data
}

void DATA ()
{
PORTC|=(1<<0);                                                                            // RS=1 for data
PORTC&=~(1<<1);                                                                        // R/W = 0 for write
PORTC|=(1<<2);                                                                           // E = 1 for enabling LCD to read data
_delay_ms(10);
PORTC&=~(1<<2);                                                                        //E = o for disabling LCD to read data
}

int main()
{

DDRD=0xFF;                                                                                  //PORT D in output mode
DDRC=0x07; 

PORTD=0x38;
CMD ();
_delay_ms(50);
PORTD=0x0E;
CMD ();
_delay_ms(10);
 PORTD=0x01;
CMD ();
_delay_ms(10);
PORTD=0x06;
CMD ();
_delay_ms(10);
PORTD=0x80;
CMD ();
_delay_ms(10);
PORTD='H';
DATA ();
_delay_ms(10);
PORTD='E';
DATA ();
_delay_ms(10);
PORTD='L';
DATA ();
_delay_ms(10);
PORTD='L';
DATA ();
_delay_ms(10);
PORTD='O';
DATA ();
_delay_ms(10);

while(1)
{

PORTD=0x0C;
CMD();

}
return 1;
}
