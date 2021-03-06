/*	Author: sdong027
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #1
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

void ADC_init() {
	ADCSRA |= ((1 << ADEN) | (1 << ADSC) | ( 1 << ADATE));
}

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	//unsigned short input = 0x00;
	ADC_init();
	/* Insert your solution below */
	while (1) {
		unsigned short input = ADC;
		PORTB = (char)input;
		char upper = (input >> 8) & 0x03;
		PORTD = upper;
	}
	return 1;
}
