/*
 * 0-99.c
 *
 * Created: 5/29/2022 4:43:58 PM
 * Author : ABu Bakar
 */ 

#define  F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xFF;
	DDRD=0xFF;
	char array[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

	while (1)
	{
		for (int i=0; i < 10; i++)
		{
			for (int j=0; j<10; j++)
			{
				PORTC = array[i];
				PORTD = array[j];
				_delay_ms(150);
			}
		}
	}
	return 0;
}