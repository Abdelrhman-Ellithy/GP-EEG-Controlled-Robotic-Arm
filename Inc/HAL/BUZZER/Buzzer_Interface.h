/*
 * Buzzer_Interface.h
 * Created: 2023-7-30 7:40:05 AM
 *  Author: Abdelrahman Ellithy
 *  Layer: HAL
 *  SW: Buzzer
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_
#include "MCAL/GPIO/GPIO_interface.h"
typedef enum{
	Active_Low,
	Active_High
}active_type;
typedef struct{
	u8 BUZZER_PORT;
	u8 BUZZER_pin;
	active_type BUZZER_Active_Type;
}BUZZER;
void BUZZER_voidInit  (BUZZER* Buz);
void BUZZER_voidON	  (BUZZER* Buz);
void BUZZER_voidOFF	  (BUZZER* Buz);
void BUZZER_voidToggle(BUZZER* Buz);

#endif /* BUZZER_INTERFACE_H_ */
