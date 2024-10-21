/*
 * delay.c
 *
 * Created: 2023-11-09 4:15:42 AM
 *  Author: Abdelrahman Ellithy
 * 	layer: LIB
 * 	SW: delay
 */
#include "LIB/ellithy_delay.h"
#include "LIB/STD_TYPES.h"
/*	for F_CPU = 8mhz */
void _delay_ms(u16 delay_in_ms){
	u16 i,j,fact=((u16)(F_CPU/8000000u));
	fact*=993;
	for(i=0;i<delay_in_ms; i++)
	{
		for(j= 0 ; j < fact ; j++ )
		{
		__asm__("nop");
		}
	}
}
void _delay_us(u16 delay_in_us){
	u16 i,j;
	for(i=0;i<delay_in_us; i++)
	{
		for(j= 0 ; j < 3 ; j++ )
		{
		__asm__("nop");
		}
	}
}
