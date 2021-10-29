/*
 * accesspins.c
 *
 * Created: 10/20/2021 2:48:54 PM
 *  Author: IBRAR AHMAD
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define col0 PORTD4
#define col1 PORTD5
#define col2 PORTD6
#define col3 PORTD7

#define row0 PORTD0
#define row1 PORTD1
#define row2 PORTD2
#define row3 PORTD3




#define colpins(a,b,c,d) (((1<<a)|(1<<b)|(1<<c)|(1<<d)))
#define rowpins(e,f,g,h) (((1<<e)|(1<<f)|(1<<g)|(1<<h)))

void setcoloutrowin(){
	
	DDRD&=~ rowpins(row0,row1,row2,row3);	//ROWS in (first change status to input	)
	
	PORTD=rowpins(row0,row1,row2,row3);	//Pullup (modify complete port, not selected bits otherwise previously
	
	
	DDRD|=colpins(col0,col1,col2,col3);	//col out(if this is used 1st then both connected
										// will be output i.e output connected to other output)			
	
	
	
	
}

void setrowoutcolin(){

DDRD&=~ colpins(col0,col1,col2,col3);//cols in

PORTD=colpins(col0,col1,col2,col3);	//Pullup (modify complete port, not selected bits otherwise previously

//pulled up remain at 1. So set them to zero. This way input pulled to output also goes through intermediate stage

//_delay_ms(2);
DDRD|=rowpins(row0,row1,row2,row3);	//row out

//PORTC=(PIND&0xF0)>>4;

}


void waitforpress(){
	
_delay_us(5);	//If this delay is removed PIND remains zero and thus doesn't wait for press. If set >1us and < 5us than PIND gets set correctly for while check but not for the next debug instruction i.e PORTC=PIND&0xF0. Half the bits still remain zero
//PORTC=(PIND&0xF0)>>4;	

	while ((PIND&0xF0)==0xF0)
	{
	}


}


void waitforrelease(){
//PORTC=(PIND&0x0f);	
	//_delay_us(1);	
	while ((PIND&0x0F)!=0x0F)
	{
	}

PORTC=(PIND&0x0f);		
}


char readport(){
	
	return PIND;
	
}