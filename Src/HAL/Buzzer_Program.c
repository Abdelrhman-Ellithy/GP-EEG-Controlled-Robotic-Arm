/*
 * BUZZER_Program.c
 *
 * Created: 2023-7-30 7:40:36 AM
 *  Author: Abdelrahman Ellithy
 */ 
#include "HAL/BUZZER/BUZZER_Interface.h"
void BUZZER_voidInit(BUZZER* Buz){
	GPIO_SetPinMode(Buz->BUZZER_PORT,Buz->BUZZER_pin,GPIO_OUTPUT_GP_PP_2MHZ);
}
void BUZZER_voidON(BUZZER* Buz){
	switch(Buz->BUZZER_Active_Type)
	{
		case Active_High:
			GPIO_WritePinValue(Buz->BUZZER_PORT,Buz->BUZZER_pin,GPIO_HIGH);
			break;
		case Active_Low:
			GPIO_WritePinValue(Buz->BUZZER_PORT,Buz->BUZZER_pin,GPIO_LOW);
		break;
	}
}

void BUZZER_voidOFF(BUZZER* Buz){
	switch(Buz->BUZZER_Active_Type)
	{
		case Active_High:
			GPIO_WritePinValue(Buz->BUZZER_PORT,Buz->BUZZER_pin,GPIO_LOW);
		break;
		case Active_Low:
			GPIO_WritePinValue(Buz->BUZZER_PORT,Buz->BUZZER_pin,GPIO_HIGH);
		break;
	}
}
void BUZZER_voidToggle(BUZZER* Buz){
	GPIO_TogPinValue(Buz->BUZZER_PORT,Buz->BUZZER_pin);
}
