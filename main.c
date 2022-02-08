/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mariam
 */
#include"../std_types.h"
#include"../Bit_calc.h"

#include"avr/delay.h"
//#include"avr/io.h"
#include<avr/interrupt.h>

#include"DIO_interface.h"
#include"ADC_interface.h"
#include"Timer_interface.h"

#define OCR_ON_Time		1500
#define OCR_OFF_Time	18500

ISR(TIMER1_COMPA_vect)
{

static u8 flag=0;
if(flag==0)
{
DIO_vidSetPinValue(DIO_PORTB,PIN0,HIGH);
_delay_ms(500);
vidSetTimer1Value (OCR_ON_Time);
flag=1;

}
else if(flag==1)
{
	DIO_vidSetPinValue(DIO_PORTB,PIN0,LOW);
	_delay_ms(500);
	vidSetTimer1Value(OCR_OFF_Time);
	flag=0;

}
}
void main (void)
{//u8 result;
//u8 Local_iteraion;
DIO_vidSetPinDirection(DIO_PORTB,PIN0,OUTPUT);
DIO_vidSetPinValue(DIO_PORTB,PIN0,LOW);

/*intializations*/
//ADC_vidIntitalization();
//Timer_vidIntFastPWMmode();
Timer_vidIntTimer1ctcMode(OCR_OFF_Time);
	//Timer_TCCR0=0b01101010;

	while(1)
	{
/*for(Local_iteraion=0;Local_iteraion<255;Local_iteraion++)
{Timer_OCR0=Local_iteraion;
	_delay_ms(100);
}*/
		/*********************************************/
		//task 2->using potontiometer
		//Timer_OCR0=ADC_GetAdcBlocking(0,&result);
/******************************************************************/
		//task3 use timer 1 to generate a duty cycle to move the servo motor 90 degrees


	}
}


