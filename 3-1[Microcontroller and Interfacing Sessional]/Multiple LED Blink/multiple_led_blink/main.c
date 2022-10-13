/*
 * multiple_led_blink.c
 *
 * Created: 2/28/2022 8:31:53 PM
 * Author : Abu Bakar
 */ 

#include <avr/io.h> //avr input output header file
#include<util/delay.h> // delay header file for delay

int main(void)
{
	DDRC = 0xFF; // declaring all pins of PORT C as output
	while (1) // forever loop
	{
		PORTC = 0xFF; // all pins of PORTC high
		_delay_ms(1000); // delay 1s
		PORTC = 0x00; // all pins of PORTC low
		_delay_ms(1000); // delay 1s
	}
	return 0;
}
