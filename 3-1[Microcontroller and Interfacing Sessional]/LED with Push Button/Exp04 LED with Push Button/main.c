/*
 * Exp: 04 [LED with Push Button.c]
 *
 * Created: 6/8/2022 7:57:55 PM
 * Author : G-A2
 
 Goal: 
 The aim of this project is to blink a LED whenever the pushbutton is pressed. We have made the 1st pin PORTC as output where LED is 
 connected as 1st pin of PORTD as input from where the code knows if the button is pressed on not.
 This is a super efficient code that employs a while loop to blink the LED. We can change the blinking number just by changing the value of 'repeted_time' 
 variable. We can also change the delay time from 'delay' variable.
 */ 

#define F_CPU 8000000UL // set the CPU frequency at 8Mhz
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int delay = 700; // variable for delay time.
	int repeted_time = 5; // how many time we want the led to blink
	int counter = 0; // track blinking number
	
    DDRC = 0x01; //set the output pin
	DDRD &= ~(1<<PD0); // set the input pin
	
    while (1) // infinite loop
    {
		if(PIND & (1<<PD0) == 1) // checks if the button is pressed
		{
			while(counter < repeted_time) // while loop for blinking number.
			{
				PORTC = 0x01;
				_delay_ms(delay);
				PORTC = 0x00;
				_delay_ms(delay);
				
				counter = counter + 1; // increment the counter
			}
			
			counter = 0; // set the counter to the initial value
		}
		
    }
}

