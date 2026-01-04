#ifndef F_CPU                                                                                          
#define F_CPU 16000000UL                                                                
#endif
#include<avr/io.h>  
#include<stdlib.h> 
#include<string.h>                                                                             
#include<util/delay.h>                                                                           
#include<avr/interrupt.h>

void CMD ()
{
 PORTC&=~(1<<0);                                                                           
 PORTC&=~(1<<1);                                                                         
 PORTC|=(1<<2);                                                                              
 _delay_ms(100);
 PORTC&=~(1<<2);                                                                           
}

void DATA ()
{
 PORTC|=(1<<0);                               
 PORTC&=~(1<<1);                                                                        
 PORTC|=(1<<2);                                                                         
 _delay_ms(100);
 PORTC&=~(1<<2);                                                                        
}

void LCD_INIT()
{

DDRD=0xFF;                                                    

DDRC=0xFF;


PORTD=0x38;
CMD ();
_delay_ms(100);
PORTD=0x0E;
CMD ();
_delay_ms(100);
PORTD=0x01;
CMD ();
_delay_ms(100);
PORTD=0x06;
CMD ();
_delay_ms(100);
PORTD=0x80;
CMD ();
_delay_ms(100);

PORTD=0x00;
}

void main(void)
{
 float a,b,e;
 unsigned int c,d,i;
 char f[1],g[3];

 LCD_INIT();

 _delay_ms(10);
 DDRA=0x00;

 sei();
 ADMUX=0x00;
 ADMUX|=(1<<ADLAR);
 ADCSRA=0xCF;
	
 DDRB=0xFF;
	
 PORTB=0x00;
 PORTD=0x00;



while(1)
{	
	a=ADCH;
	b=(((a/255)*5)*100);
	c=b/100;
	e=c*100;
	d=b-e;
	

	itoa(c,f,10);

	for(i=0;i<1;i++)
	{

	PORTD=f[i];
	_delay_ms(5);
	DATA();		
	}

	PORTD='.';
	_delay_ms(5);
	DATA();
	
	itoa(d,g,10);

	for(i=0;i<2;i++)
	{

	PORTD=g[i];
	_delay_ms(5);
	DATA();		
	}
	_delay_ms(1000);

	PORTD=0x01;
	CMD ();
	
	
}

}


ISR(ADC_vect)
{
//	PORTD=ADCH;
	ADCSRA|=0x40;
	


}

