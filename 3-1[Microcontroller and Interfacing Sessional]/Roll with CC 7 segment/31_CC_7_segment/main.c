/*
 * 31_CC_7_segment.c
 *
 * Created: 5/21/2022 12:02:31 AM
 * Author : Abu Bakar
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LED_Direction_1 DDRC
#define LED_Direction_2 DDRD
#define LED_PORT_1 PORTC
#define LED_PORT_2 PORTD


int main(void)
{
	LED_Direction_1 |= 0xff;
	LED_Direction_2 |= 0xff;
	LED_PORT_1 = 0x4F;
	LED_PORT_2 = 0x6;
	
	while(1)
	{
		
	}
}

