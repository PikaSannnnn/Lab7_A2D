/*	Author: sdong027
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	Demo Link:
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short photo_MIN = 0x030;	// 00 0011 0000
unsigned short photo_MAX = 0x1E0;	// 01 1110 0000

void ADC_init() {
	ADCSRA |= ((1 << ADEN) | (1 << ADSC) | ( 1 << ADATE));
}

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned short half = photo_MAX / 2;
	unsigned short tmpB = 0x00;
	ADC_init();
	/* Insert your solution below */
	while (1) {
		unsigned short input = ADC;
		
		if (input >= half) {
			tmpB = 0x01;
		}
		else {	// input < half
			tmpB = 0x00;	
		}

		PORTB = tmpB;
	}
	return 1;
}
