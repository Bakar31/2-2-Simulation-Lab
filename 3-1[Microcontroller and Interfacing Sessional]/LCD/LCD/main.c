/*
 * LCD.c
 *
 * Created: 5/20/2022 2:24:40 PM
 * Author : Abu Bakar
 */ 

#define F_CPU 1000000UL 
#include <avr/io.h>
#include "lib/lcd_lib.h"


int main(void) {
	
	DDRD = 0xFF;
	DDRC = 0xFF;
	
	// Power up delay to stabilize LCD
	_delay_ms(100);
	LCDinit(); // Initialize LCD, print welcome message
	LCDWriteStringXY(2, 0, "Hello World!");
	while (1) {
	}
}

