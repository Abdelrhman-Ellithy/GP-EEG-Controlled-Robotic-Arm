/*=================================================================================*/
/*  File        : NVIC_Program.c                                                   */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW: NVIC
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/stm32f103c8t6.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/NVIC/NVIC_config.h"
#include "MCAL/NVIC/NVIC_Private.h"

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/
void NVIC_Init(void){

	SCB_AIRCR=NVIC_GROUP_SUBSelected;
}

void NVIC_EnableInterrupt(NVIC_INTERTUPT_id Copy_u8InterruptID)
{

	if(Copy_u8InterruptID < 32)
	{
		NVIC_ISER0= (1 << Copy_u8InterruptID);
	}
	else
	{
		NVIC_ISER1 = (1 << (Copy_u8InterruptID-32));
	}

}

void NVIC_DisableInterrupt(NVIC_INTERTUPT_id Copy_u8InterruptID)
{

	if(Copy_u8InterruptID < 32)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptID);
	}
	else
	{
		NVIC_ICER1 = (1 << (Copy_u8InterruptID-32));
	}

}

void NVIC_SetInterruptPending(NVIC_INTERTUPT_id Copy_u8InterruptID)
{

	if(Copy_u8InterruptID < 32)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptID);
	}
	else
	{
		Copy_u8InterruptID -= 32 ;
		NVIC_ISPR1 = (1 << (Copy_u8InterruptID-32));
	}
}


void NVIC_SClearInterruptPending(NVIC_INTERTUPT_id Copy_u8InterruptID)
{

	if(Copy_u8InterruptID <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptID);
	}
	else
	{
		Copy_u8InterruptID -= 32 ;
		NVIC_ICPR1 = (1 << (Copy_u8InterruptID-32));
	}
}


void NVIC_SetGroupPriority(NVIC_INTERTUPT_id Copy_u8InterruptID,u8 Copy_u8GroupPriority)
{
		*((NVIC_IPR_ptr+NVIC_IPR_offsets[Copy_u8InterruptID]))=Copy_u8GroupPriority;
}


void NVIC_GenerateSWInerrupt(NVIC_INTERTUPT_id Copy_u8InterruptID)
{

		NVIC_STIR = Copy_u8InterruptID;
}
