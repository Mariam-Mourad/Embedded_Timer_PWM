/*
 * ADC_prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mariam
 */
#include"std_types.h"
//#include"DIO_interface.h"// dah mayenfa3sh a3meloh include 3ashan ADC is a periferal in the MCAL
#include"Bit_calc.h"
#include"ADC_interface.h"

void ADC_vidIntitalization(void)
{//enebaling the periferal
	//in register ADCSRA
	SetBit(ADCSRA_Register,7);
	//Prescaler configuration
		SetBit(ADCSRA_Register,0);
		SetBit(ADCSRA_Register,1);
		SetBit(ADCSRA_Register,2);
//set ADMUX
//set ADLAR
	//ADMUX=0x60;
	//reference voltage is ACC(internal)
	ClrBit(ADMUXA_Register,7);
	SetBit(ADMUXA_Register,6);
	//data left adjustment
	SetBit(ADMUXA_Register,5);



}

u8 ADC_GetAdcBlocking(u8 Copy_Channel_Num, u8* Copy_Data )
{//el bernameg hena me3ala2 3ala el flag le7ad ma el flag yetrefe3(lama a5od eraya)
u8 Local_ErrorState=STD_u8_ERROR_OK;
if((Copy_Channel_Num>=0)&&(Copy_Channel_Num<8))
{
ADMUXA_Register=(((ADMUXA_Register)&(0b11100000))|(Copy_Channel_Num));
//start conversion
SetBit(ADCSRA_Register,6);
//wait on flag(tol ma howa b zero el 2eraya mesh gahza)
while(GetBit(ADCSRA_Register,4)==0);
//ADC Flag Clear
SetBit(ADCSRA_Register,4);
//read value
(*Copy_Data)=ADCH_Register;
}
}
