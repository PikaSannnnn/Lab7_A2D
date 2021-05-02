/*	Author: sdong027
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #4
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
	// DDRD = 0xFF; PORTD = 0x00;	// not used for this part
	unsigned short threshold_diff = photo_MAX / 8;
	ADC_init();
	/* Insert your solution below */
	while (1) {
		unsigned short input = ADC;
		unsigned short tmpB = 0x00;
		
		// 0 = off
/*
		if (input >= (photo_MAX - (threshold_diff * 7))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff * 6))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff * 5))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff * 4))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff * 3))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff * 2))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (photo_MAX - (threshold_diff))) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= photo_MAX) {
			tmpB = (tmpB << 1) | 0x01;
		}
*/
		if (input >= (threshold_diff * 0)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 1)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 2)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 3)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 4)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 5)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 6)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		if (input >= (threshold_diff * 7)) {
			tmpB = (tmpB << 1) | 0x01;
		}
		
		PORTB = tmpB;
	}
	return 1;
}
