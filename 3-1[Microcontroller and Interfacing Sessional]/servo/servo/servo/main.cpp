#include <avr/io.h>
#include <util/delay.h>
int main(void) {
	
	DDRD |= 0x20;
	
	ICR1 = 19999;
	OCR1A = 1200;
	TCNT1 = 0;
	TCCR1A = 0x82;
	TCCR1B = 0x19;
	
	
	while (1) {
		

		OCR1A = 600;
		_delay_ms(2000);
		OCR1A = 800;
		_delay_ms(2000);
		OCR1A = 1000;
		_delay_ms(2000);
		OCR1A = 1400;
		_delay_ms(2000);
		OCR1A = 1800;
		_delay_ms(2000);
		
		OCR1A = 1400;
		_delay_ms(2000);
		OCR1A = 1000;
		_delay_ms(2000);
		OCR1A = 800;
		_delay_ms(2000);
		
	}
}


