/*
 * LED_Interface.h
 *
 * Created: 2023-7-30 7:40:05 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "MCAL/GPIO/GPIO_interface.h"
typedef enum{
	Active_Low,
	Active_High
}active_type;
typedef struct{
	u8 LED_PORT;
	u8 LED_pin;
	active_type LED_Active_Type;
}LED;
void LED_voidInit(LED* led);
void LED_voidON(LED* led);
void LED_voidOFF(LED* led);
void LED_voidToggle(LED* led);


#endif /* LED_INTERFACE_H_ */
