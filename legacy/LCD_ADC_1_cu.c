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
PORTC=0x0E;
CMD ();
_delay_ms(10);
PORTC=0x01;
CMD ();
_delay_ms(10);
PORTC=0x06;
CMD ();
_delay_ms(10);

PORTC='v';
DATA ();
_delay_ms(10);

PORTC='=';
DATA ();
_delay_ms(10);

PORTC=0x82;
CMD ();
_delay_ms(10);

PORTC=0x00;
}

int main()
{
 
 float a,b,e,x;
 unsigned int c,d,i;
 char f[2],g[3];

 DDRD=0xFF;
 PORTD=0x00;
 DDRB=0x07;                                                    

 DDRC=0xFF;

 DDRA=0x00;

// PORTA=0xFF;

 LCD_INIT();

 //_delay_ms(10);   port c lcd data
                    //port b control signal b0,b1,b2
 
 sei();
 ADMUX=0x01;
 ADMUX|=(1<<ADLAR);
 ADCSRA=0xCF;
	
 PORTB=0x00;
 PORTC=0x00;
 PORTD=0x00;


 while(1)
 {	
	x=a;

	a=ADCH;
	_delay_ms(10);
	if(x!=a)
	{
	_delay_ms(2000);
	PORTC=0x0E;
	CMD();
	b=(((a/255)*5)*100);   // lets say a= 220   b=r220/255=0.8627*5=  4.3137 x100=431.37
	_delay_ms(1);
	c=b/100;// 4     int
	_delay_ms(1);
	e=c*100; //400  float
	_delay_ms(1);
	d=b-e; //31      int
	_delay_ms(1);
	
	PORTC=0x82;
	CMD ();
	_delay_ms(10);
	itoa(c,f,10);
	_delay_ms(15);

	for(i=0;i<1;i++)
	{
	
	PORTC=f[i];
	_delay_ms(10);	
	DATA();		
	_delay_ms(10);
	}

	PORTC='.';
	_delay_ms(10);
	DATA();
	_delay_ms(10);

	itoa(d,g,10);

	for(i=0;g[i]!='\0';i++)
	{

	PORTC=g[i];
	_delay_ms(10);	
	DATA();	
	_delay_ms(10);
		
	}

	}
	else
	{
	PORTC=0x0C;
	CMD();
	_delay_ms(150);

	}
 }
	return 0;
}




ISR(ADC_vect)
{
//	PORTC=ADCH;
	ADCSRA|=0x40;

}
