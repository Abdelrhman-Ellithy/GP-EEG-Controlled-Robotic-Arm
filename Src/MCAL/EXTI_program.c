/*=================================================================================*/
/*  File        : EXTI_Program.c                                                   */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: EXTI
 *  													*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/EXTI/EXTI_Private.h"
#include "LIB/stm32f103c8t6.h"

typedef void(*fptr)(void);

static fptr EXTI_CallBacks[16] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
								  NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void EXTI_Interrupt_Enable(EXTI_ID Copy_u8EXTINumber ,Edge_trriger Edge ){
	SET_BIT(EXTI->IMR,Copy_u8EXTINumber);
	switch(Edge){
		case ANY_LOGIC_CHANGE:
			SET_BIT(EXTI->FTSR,Copy_u8EXTINumber);
			SET_BIT(EXTI->RTSR,Copy_u8EXTINumber);
		break;

		case FALLING_EDGE:  SET_BIT(EXTI->FTSR,Copy_u8EXTINumber); break;
		case RISING_EDGE:   SET_BIT(EXTI->RTSR,Copy_u8EXTINumber);	break;
	}
}
void EXTI_Interrupt_Disable(EXTI_ID Copy_u8EXTINumber  ){
	CLEAR_BIT(EXTI->IMR,Copy_u8EXTINumber);
}

void EXTI_SetCallBack(EXTI_ID Copy_u8EXTINumber , void(*Copy_pfCallback)(void))
{

	if(Copy_u8EXTINumber <=  EXTI15)
	{
		EXTI_CallBacks[Copy_u8EXTINumber] = Copy_pfCallback;
	}
}



void EXTI0_IRQHandler(void)
{
	EXTI->PR = (1 << 0);
	if(EXTI_CallBacks[0] != NULL )
	{
		EXTI_CallBacks[0]();
	}
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR = (1 << 1);
	if(EXTI_CallBacks[1] != NULL )
	{
		EXTI_CallBacks[1]();
	}
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR = (1 << 2);
	if(EXTI_CallBacks[2] != NULL )
	{
		EXTI_CallBacks[2]();
	}
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR = (1 << 3);
	if(EXTI_CallBacks[3] != NULL )
	{
		EXTI_CallBacks[3]();
	}
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR = (1 << 4);
	if(EXTI_CallBacks[4] != NULL )
	{
		EXTI_CallBacks[4]();
	}
}

void EXTI9_5_IRQHandler(void)
{
	for (u8 i = 5 ; i <= 9 ; i++)
	{
		if(GET_BIT(EXTI->PR,i) == 1 && GET_BIT(EXTI->IMR,i) == 1)
		{
			EXTI->PR = (1 << i);
			if(EXTI_CallBacks[i] != NULL )
			{
				EXTI_CallBacks[i]();
			}
		}
	}
}

void EXTI15_10_IRQHandler(void)
{
	for (u8 i = 10 ; i <= 15 ; i++)
	{
		if(GET_BIT(EXTI->PR,i) == 1)
		{
			SET_BIT(EXTI->PR,i);
			if(EXTI_CallBacks[i] != NULL )
			{
				EXTI_CallBacks[i]();
			}
		}
	}
}

