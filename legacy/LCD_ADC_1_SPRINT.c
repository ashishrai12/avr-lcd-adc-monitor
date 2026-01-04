#ifndef F_CPU                                                                                          
#define F_CPU 16000000UL                                                                
#endif
#include<avr/io.h>  
#include<stdlib.h>
#include<stdio.h> 
#include<string.h>                                                                             
#include<util/delay.h>                                                                           
#include<avr/interrupt.h>

void CMD ()
{
 PORTB&=~(1<<0);                                                                           
 PORTB&=~(1<<1);                                                                         
 PORTB|=(1<<2);                                                                              
 _delay_ms(10);
 PORTB&=~(1<<2);
 _delay_ms(10);                                                                           
}

void DATA ()
{
 PORTB|=(1<<0);                               
 PORTB&=~(1<<1);                                                                        
 PORTB|=(1<<2);                                                                         
 _delay_ms(10);
 PORTB&=~(1<<2);
 _delay_ms(10);                                                                        
}

void LCD_INIT()
{

PORTC=0x38;
CMD ();
_delay_ms(10);
PORTC=0x0C;
CMD ();
_delay_ms(10);
PORTC=0x01;
CMD ();
_delay_ms(10);
PORTC=0x06;
CMD ();
_delay_ms(10);
PORTC=0x80;
CMD ();
_delay_ms(10);

PORTC='v';
DATA ();
_delay_ms(10);
PORTC='=';
DATA ();
_delay_ms(10);

PORTC=0x85;
CMD ();
_delay_ms(10);}
int main()
{
   char port_read;
   double ans;
   char disp_buf[20]; 
   int i=0;
   
   DDRB=0x07;   // first three outputs                                                 
   DDRC=0xFF;  // output
   LCD_INIT();
   sei();
   ADMUX=0x00;  // CHANNEL 0 AS INPUT
   ADCSRA=0xCF;
   PORTB=0x00;
   PORTC=0x00;
   while(1)
       {	
 	     ADCSRA|=0x40;    //START OF CONVERSION
	     _delay_ms(20);
         port_read=ADCL;
         ans=(port_read/255)*5.00;
	     sprintf(disp_buf,"%f",ans); 
         for(i=0;disp_buf[i]!='\0';i++)
	        {
              PORTC=disp_buf[i];
	          DATA();
			}
	   }
return 0;
}


