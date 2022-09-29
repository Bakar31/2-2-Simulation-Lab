/*
 * matrix_keypad.c
 *
 * Created: 5/20/2022 12:11:56 PM
 * Author : Abu Bakar
 */ 

#define F_CPU 16000000UL
#define NO_KEY 0xFF
#define ROW_SIZE 4
#define COLUMN_SIZE 4
#include <avr/io.h>
#include <util/delay.h>
#include "lcd/lcd_lib.h"


static uint8_t getKeyPressed(void);

int main(void) {
	uint8_t key_value = NO_KEY;
	
    DDRA = 0x00;
	PORTA |= 0x0F;
	
	LCDinit();
	LCDWriteStringXY(2, 0, "Matrix Keypad");
	_delay_ms(50);
	
	LCDclr();
	LCDWriteStringXY(0, 0, "Key");
	LCDWriteStringXY(2, 1, "Pressed = "); 
	
    while (1) {
		key_value = getKeyPressed();
		
		if(key_value != NO_KEY) {
			LCDWriteIntXY(12, 1, key_value, 2);
		}
	}
}


static uint8_t getKeyPressed(void) {
	uint8_t row, column;
	
	PORTA |= 0X0F;
	
	for(column = 0; column < COLUMN_SIZE; column++) {
		// De-select column, i,e all are inputs
		DDRA &= 0x00;
		
		DDRA |= (0X80 >> column);
		
		// Scan Rows
		for(row = 0; row < ROW_SIZE; row++) {
			
			if(! (PINA & ( 0X08 >> row)) ) {
				return ( (row*COLUMN_SIZE)+column);
			}
		}
	}
	
	return NO_KEY;
}

