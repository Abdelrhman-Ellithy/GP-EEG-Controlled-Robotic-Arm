/*
 * Keypad.c
 *
 * Created: 2023-11-09 4:15:56 AM
 *  Author: Abdelrahman Ellithy
 */ 
#include <HAL/Keypad/Keypad_Config.h>
#include <HAL/Keypad/Keypad_interface.h>
#include <HAL/Keypad/Keypad_Private.h>
#include "LIB/Types.h"
u8 Get_pressed(void){
	u8 loc_pressed=KPD_NotPressed;
	u8 val=1;
	u8 row,col;
	for (col= Col1 ; col<= Col4 ;col++ )
	{
			
		GPIO_WritePinValue(keypad_port,col,GPIO_LOW);
		for (row=row1 ; row<=row4 ; row++)
		{
			GPIO_GetPinValue(keypad_port, row, &val);
			if(val==GPIO_LOW)
			{
				while(GPIO_LOW==val)
				{
					GPIO_GetPinValue(keypad_port, row, &val);
				}
				loc_pressed=keypad_Buttons[row-row1][col-Col1];
			}
		}
		GPIO_WritePinValue(keypad_port,col,GPIO_HIGH);
	}
	return loc_pressed;
}
