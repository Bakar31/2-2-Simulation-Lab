/*
 * Exp05 Part 2.c
 *
 * Created: 6/8/2022 11:04:39 PM
 * Author : G-A2

Goal: This project aims to increment and decrement value from 0-9 with the help two push buttons. The 'DisplayDigit' shows the desired value in the 7 segment CC
type  display. POTRC is selected as the output terminal which is connected to the 7-segment display. The 1st pin and 2nd pin of PORTD takes input from the push
buttons. This code is only to display number from 0-9. If the pushbutton is pressed more after reaching 9 or 0, it will not do anything.

This code is clean and we avoided complex statement to keep it simple.
This is a highly reproducible code.
*/

#define F_CPU 8000000UL // set the CPU frequency at 8Mhz
#include <avr/io.h>
#include <util/delay.h>

static void DisplayDigit(uint8_t num); //Function Prototype


int main(void) {
	DDRC = 0xFF; // PORTC as Output
	DDRD &= ~(1<<PD0); // First pin of PORTD as Input

	uint8_t count = 0; 	// Variable that counts the Input
	DisplayDigit(count); // Show Initial count value (0) on Display

	while (1) {

		if( (PIND & 0x01) == 0 ) // Check if switch is pressed
		{
			_delay_ms(80); // delay for 80 s

			if (count < 9 ) // Check if count value is less than MAX value (9)
			{
				count++; // If true increment the count value
			}

			else
			{
				continue; // Otherwise continue
			}

		DisplayDigit(count); // Show the count value on Display
		}
		
		if( (PIND & 0x02) == 0 ) 
		{
			_delay_ms(80); // delay for 80 s
			
			if (count > 0 ) // Check if count value is greater than MIN value (0)
			{
				count--; // If true decrement the count value
			}
			
			else
			{
				continue; // Otherwise continue
			}
			
			DisplayDigit(count); // Show the count value on Display
		}
	}

	return 0;
}

static void DisplayDigit(uint8_t num) {

	PORTC &= 0x80; // Clear only bits (PC6:PC0)
	switch (num)
	{
	// Print 0 on 7-segment if num = 0 or num > 9
		default:

		case 0:
		PORTC |= 0x3F; // show 0
		break;

		case 1:
		PORTC |= 0x06; // show 1
		break;

		case 2:
		PORTC |= 0x5B; // show 2
		break;

		case 3:
		PORTC |= 0x4F; // show 3
		break;

		case 4:
		PORTC |= 0x66; // show 4
		break;

		case 5:
		PORTC |= 0x6D; // show 5
		break;

		case 6:
		PORTC |= 0x7D; // show 6
		break;

		case 7:
		PORTC |= 0x07; // show 7
		break;

		case 8:
		PORTC |= 0x7F; // show 8
		break;

		case 9:
		PORTC |= 0x6F; // show 9
		break;
	}
}
