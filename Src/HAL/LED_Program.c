/*
 * LED_Program.c
 *
 * Created: 2023-7-30 7:40:36 AM
 *  Author: Abdelrahman Ellithy
 */ 
#include "HAL/LED/LED_Interface.h"
void LED_voidInit(LED* led){
	GPIO_SetPinMode(led->LED_PORT,led->LED_pin,GPIO_OUTPUT_GP_PP_2MHZ);
}
void LED_voidON(LED* led){
	switch(led->LED_Active_Type)
	{
		case Active_High:
			GPIO_WritePinValue(led->LED_PORT,led->LED_pin,GPIO_HIGH);
			break;
		case Active_Low:
			GPIO_WritePinValue(led->LED_PORT,led->LED_pin,GPIO_LOW);
		break;
	}
}

void LED_voidOFF(LED* led){
	switch(led->LED_Active_Type)
	{
		case Active_High:
			GPIO_WritePinValue(led->LED_PORT,led->LED_pin,GPIO_LOW);
		break;
		case Active_Low:
			GPIO_WritePinValue(led->LED_PORT,led->LED_pin,GPIO_HIGH);
		break;
	}
}
void LED_voidToggle(LED* led){
	GPIO_TogPinValue(led->LED_PORT,led->LED_pin);
}
