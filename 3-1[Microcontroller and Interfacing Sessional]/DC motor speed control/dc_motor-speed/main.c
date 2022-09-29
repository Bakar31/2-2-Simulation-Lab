#include <avr/io.h>


int main(void)
{
   DDRB=0X08;
   PORTA=0X80;
   TCCR0=0X73;
    while (1) 
    {
		switch((PINA&0X80))
		{
			case 0: OCR0 =64; break; //25%
			case 1: OCR0 =127; break; //50%
    }
	}
	return 0;
	}

