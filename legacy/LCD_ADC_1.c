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
 PORTB&=~(1<<0);                                                                           
 PORTB&=~(1<<1);                                                                         
 PORTB|=(1<<2);                                                                              
 _delay_ms(10);
 PORTB&=~(1<<2);                                                                           
}

void DATA ()
{
 PORTB|=(1<<0);                               
 PORTB&=~(1<<1);                                                                        
 PORTB|=(1<<2);                                                                         
 _delay_ms(10);
 PORTB&=~(1<<2);                                                                        
}

void LCD_INIT()
{

DDRB=0xFF;                                                    

DDRC=0xFF;


PORTC=0x38;
CMD ();
_delay_ms(100);
PORTC=0x0E;
CMD ();
_delay_ms(100);
PORTC=0x01;
CMD ();
_delay_ms(100);
PORTC=0x06;
CMD ();
_delay_ms(100);
PORTC=0x80;
CMD ();
_delay_ms(100);

PORTC=0x00;
}

void main(void)
{
 float a,b,e,x;
 unsigned int c,d,i,y;
 char f[1],g[3];

 LCD_INIT();

 _delay_ms(10);
 DDRA=0x00;

 sei();
 ADMUX=0x00;
 ADMUX|=(1<<ADLAR);
 ADCSRA=0xCF;
	
 DDRC=0xFF;
	
 PORTB=0x00;
 PORTC=0x00;



while(1)
{	
	x=a;

	a=ADCH;
	_delay_ms(100);
	if(x!=a)
	{
	
	b=(((a/255)*5)*100);
	c=b/100;
	e=c*100;
	d=b-e;

	PORTC=0x01;
	CMD ();
	itoa(c,f,10);

	for(i=0;i<1;i++)
	{

	PORTC=f[i];
	_delay_ms(5);
	DATA();		
	}

	PORTC='.';
	_delay_ms(5);
	DATA();
	
	itoa(d,g,10);

	for(i=0;i<2;i++)
	{

	PORTC=g[i];
	_delay_ms(5);
	DATA();		
	}
	
	y=1;
	}
	else
	{
	
	if(y==1)
	{
	PORTC=0x01;
	CMD();
	for(i=0;i<1;i++)
	{

	PORTC=f[i];
	_delay_ms(5);
	DATA();		
	}

	PORTC='.';
	_delay_ms(5);
	DATA();
	

	for(i=0;i<2;i++)
	{

	PORTC=g[i];
	_delay_ms(5);
	DATA();	
	}

	
	y=0;
	
	}
	}
}

}


ISR(ADC_vect)
{
//	PORTD=ADCH;
	ADCSRA|=0x40;
	


}

