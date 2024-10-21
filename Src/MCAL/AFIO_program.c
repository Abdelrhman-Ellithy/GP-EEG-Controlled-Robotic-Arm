/*=================================================================================*/
/*  File        : AFIO_Program.c                                                   */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: AFIO
 *  													*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/AFIO/AFIO_interface.h"
#include "MCAL/AFIO/AFIO_Private.h"
#include "LIB/stm32f103c8t6.h"
/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/
void AFIO_SetTIMERConfiguration(AFIO_TIMER_ID Copy_u8TimerNumber ){
	switch(Copy_u8TimerNumber){
	  case AFIO_TIMER1 : CLR_BIT(AFIO->MAPR,6); CLR_BIT(AFIO->MAPR,7); break;
	  case AFIO_TIMER2 : CLR_BIT(AFIO->MAPR,8); CLR_BIT(AFIO->MAPR,9); break;
	  case AFIO_TIMER3 : CLR_BIT(AFIO->MAPR,10); CLR_BIT(AFIO->MAPR,11); break;
	  case AFIO_TIMER4 : CLR_BIT(AFIO->MAPR,12); break;
	}
}

void AFIO_EXTI_Port_Source(AFIO_EXTI_ID Copy_u8EXTINumber , AFIO_PORT Copy_u8PortNumber)
{

	if(Copy_u8EXTINumber <= AFIO_EXTI_LINE15)
	{
		u8 Local_RegisterNumber = Copy_u8EXTINumber/4;
		u8 Local_ByteNumber = Copy_u8EXTINumber%4;

		AFIO->EXTICR[Local_RegisterNumber] &= ~(0b1111 << (4*Local_ByteNumber));
		AFIO->EXTICR[Local_RegisterNumber] |= (Copy_u8PortNumber << (4*Local_ByteNumber));
	}

}

void AFIO_DisableJTAG(void)
{


	CLR_BIT(AFIO->MAPR,26);
	SET_BIT(AFIO->MAPR,25);
	CLR_BIT(AFIO->MAPR,24);

}

void AFIO_SetUARTConfiguration(AFIO_UART_ID Copy_u8UARTNumber , u8 Copy_u8RemapValue)
{

	switch(Copy_u8UARTNumber)
	{
	case AFIO_UART1:
		CLR_BIT(AFIO->MAPR ,2);
		AFIO->MAPR |=(Copy_u8RemapValue<< 2);
		break;

	case AFIO_UART2:
		CLR_BIT(AFIO->MAPR ,3);
		AFIO->MAPR |= (Copy_u8RemapValue<< 3) ;
		break;

	case AFIO_UART3:
		CLR_BIT(AFIO->MAPR ,4);
		AFIO->MAPR |= (Copy_u8RemapValue << 4) ;
		break;
	}
}
