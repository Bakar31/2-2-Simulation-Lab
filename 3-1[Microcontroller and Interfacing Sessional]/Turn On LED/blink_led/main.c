/*
 * blink_led.c
 *
 * Created: 2/28/2022 6:48:02 PM
 * Author : Abu Bakar
 */ 

#include <avr/io.h> //avr input output header file
int main(void)
{
	DDRC = 0xFF; // declaring all pins of PORT C as output
	while (1) // forever loop
	{
		PORTC = 0x01; // PIN 1 of PORTC high
	}
	return 0;
}
