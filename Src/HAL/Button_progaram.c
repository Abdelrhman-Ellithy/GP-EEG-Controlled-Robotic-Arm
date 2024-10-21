/*
 * Button.c
 *
 * Created: 2023-07-20 2:54:56 PM
 *  Author: Abdelrahman Ellithy
 */ 
#include "LIB/Types.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "HAL/BUTTON/Button_interface.h"
void Button_read( Button* Btn,u8 *val){
	switch(Btn->BtnPullState){
	case PullDown :
		GPIO_GetPinValue(Btn->BtnPort, Btn->BtnPin , val);
		if(*val==GPIO_HIGH){
			while(*val==GPIO_HIGH){
				GPIO_GetPinValue(Btn->BtnPort, Btn->BtnPin , val);
			}
		}
		else{
			*val=0;
		}
		break;
	case PullUp :
		GPIO_GetPinValue(Btn->BtnPort, Btn->BtnPin , val);
		if(*val==GPIO_LOW){
			while(*val==GPIO_LOW){
				GPIO_GetPinValue(Btn->BtnPort, Btn->BtnPin , val);
			}
			*val=1;
		}
		else{
			*val=1;
		}

		break;
	}
}
