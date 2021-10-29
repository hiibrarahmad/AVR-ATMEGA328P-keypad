/*
 * keypadtable.h
 *
 * Created: 10/21/2021 3:36:13 PM
 *  Author: IBRAR AHMAD
 */ 


#ifndef KEYPADTABLE_H_
#define  KEYPADTABLE_H_


//A connnected to PD0 and 4 connected to PD4
//#define keyvalues[]{0b01111110,0b10111110,0b11011110,0b11101110,0b01111101,0b10111101,0b11011101,0b11101101,0b01111011,0b10111011,0b11011011,0b11101011,0b01110111,0b10110111,0b11010111,0b11100111}

//#define buttontocode() ()

#define	one	 0b01111110

#define two  0b10111110
#define three  0b11011110
#define A  0b11101110

#define	four 	0b01111101
#define five	 0b10111101
#define six		0b11011101
#define B		0b11101101

#define	seven 	0b01111011
#define eight 	0b10111011
#define nine 	0b11011011
#define C  0b11101011

#define	asterik 	0b01110111
#define zero	 0b10110111
#define hash  0b11010111
#define D 	0b11100111




#endif /* KEYPADTABLE_H_ */