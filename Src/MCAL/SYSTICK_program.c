/*=================================================================================*/
/*  File        : SYSTICK.c                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: SYSTICK
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/SYSTICK/Systick._Config.h"
#include "MCAL/SYSTICK/SysTick_Interface.h"
#include "MCAL/SYSTICK/SysTicK_private.h"
#include "LIB/stm32f103c8t6.h"

static u8 SysTK_ModeOfInterval;
static void (*SysTK_ptr_f)(void) = NULL;

void SysTKInit(SysTK_clk Copy_ClockSource){
	switch(Copy_ClockSource){
	case SysTK_AHB : SET_BIT(SysTK->CTRL,2); break;
	case SysTK_AHB_8 : CLEAR_BIT(SysTK->CTRL,2); break;
	}
}


void SysTKSetmSBusyWait(u32 Copy_u32Ticks){
	Copy_u32Ticks&=0x00ffffff;
	SysTK->LOAD=Copy_u32Ticks-1;
}

void SysTKSetIntervalSingle(u32 Copy_u32NumOfTicks, void(*Copy_ptr_f)(void)){

	u32 Local_u32LoadValue;

	if(GET_BIT(SysTK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32NumOfTicks ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32NumOfTicks ;
	}
	if((Local_u32LoadValue <= 0x00FFFFFF) && (Copy_ptr_f != NULL))
	{
		/* Set Callback Function */
		SysTK_ptr_f = Copy_ptr_f;
		/* Load the required delay */
		SysTK->LOAD = Local_u32LoadValue-1 ;
		/* Enable the timer */
		SET_BIT(SysTK->CTRL,0);
		/* Set the mode = interval */
		SysTK_ModeOfInterval = SysTK_SINGLE_INTERVAL;
		/* Enable the exception request */
		SET_BIT(SysTK->CTRL,1);
	}
}


void SysTKSetIntervalPeriodic(u32 Copy_u32NumOfTicks, void(*Copy_ptr_f)(void)){

	u32 Local_u8LoadValue;

	if(GET_BIT(SysTK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u8LoadValue = (F_CPU/1000000)*Copy_u32NumOfTicks ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u8LoadValue = (F_CPU/8000000)*Copy_u32NumOfTicks ;
	}
	if((Local_u8LoadValue <= 0x00FFFFFF) && (Copy_ptr_f != NULL))
	{
		/* Set Callback Function */
		SysTK_ptr_f = Copy_ptr_f;
		/* Load the required delay */
		SysTK->LOAD = Local_u8LoadValue-1 ;
		/* Enable the timer */
		SET_BIT(SysTK->CTRL,0);
		/* Set the mode = interval */
		SysTK_ModeOfInterval = SysTK_PERIODIC_INTERVAL;
		/* Enable the exception request */
		SET_BIT(SysTK->CTRL,1);
	}
}


void SysTKStop(void){
	CLEAR_BIT(SysTK->CTRL,0);
}

void SysTKGetElapsedTime      (u32 * Copy_pu32ElapsedTime_PTR){
	*Copy_pu32ElapsedTime_PTR=(SysTK->LOAD-SysTK->VAL);
}
void SysTKGetRemainingTime    (u32 * Copy_32RemainingTime_PTR){
	*Copy_32RemainingTime_PTR=SysTK->VAL;
}
void SysTick_Handler(void){

	/* Clear The Interrupt Flag */
	CLEAR_BIT(SysTK->CTRL,16);

	if(SysTK_ModeOfInterval == SysTK_SINGLE_INTERVAL)
	{
		/* Disable and Stop The Timer */
		CLEAR_BIT(SysTK->CTRL,0);
		CLEAR_BIT(SysTK->CTRL,1);
		SysTK->LOAD = 0;
		SysTK->VAL  = 0;
	}
	if(SysTK_ptr_f != NULL)
	{
		SysTK_ptr_f();
	}
}
