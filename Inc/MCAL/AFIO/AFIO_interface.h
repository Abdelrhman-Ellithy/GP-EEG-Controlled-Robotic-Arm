/*=================================================================================*/
/*  File        : AFIO INTERFACE                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: AFIO */

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#include "LIB/STD_TYPES.h"

typedef enum{
	 AFIO_PORTA=0
	,AFIO_PORTB
	,AFIO_PORTC
}AFIO_PORT;

typedef enum{
	 AFIO_EXTI_LINE0=0
	,AFIO_EXTI_LINE1
	,AFIO_EXTI_LINE2
	,AFIO_EXTI_LINE3
	,AFIO_EXTI_LINE4
	,AFIO_EXTI_LINE5
	,AFIO_EXTI_LINE6
	,AFIO_EXTI_LINE7
	,AFIO_EXTI_LINE8
	,AFIO_EXTI_LINE9
	,AFIO_EXTI_LINE10
	,AFIO_EXTI_LINE11
	,AFIO_EXTI_LINE12
	,AFIO_EXTI_LINE13
	,AFIO_EXTI_LINE14
	,AFIO_EXTI_LINE15
}AFIO_EXTI_ID;
/*******************************************************************************
*                       	   		AFIO UART LINE                  	       *
*******************************************************************************/

typedef enum{
	 AFIO_UART1=0
	,AFIO_UART2
	,AFIO_UART3
}AFIO_UART_ID;

typedef enum{
	 AFIO_TIMER1=0
	,AFIO_TIMER2
	,AFIO_TIMER3
	,AFIO_TIMER4
}AFIO_TIMER_ID;

#define AFIO_UART1_Tx_PA9_Rx_PA10			0
#define AFIO_UART1_Tx_PB6_Rx_PB7			1

#define AFIO_UART2_Tx_PA2_Rx_PA3			0
#define AFIO_UART2_Tx_PD5_Rx_PD6			1

#define AFIO_UART3_Tx_PB10_Rx_PB11			0
#define AFIO_UART3_Tx_PC10_Rx_PC11			1
#define AFIO_UART3_Tx_PD8_Rx_PD9			3


void AFIO_SetTIMERConfiguration(AFIO_TIMER_ID Copy_u8TimerNumber );

void AFIO_EXTI_Port_Source(AFIO_EXTI_ID Copy_u8EXTINumber , AFIO_PORT Copy_u8PortNumber);

void AFIO_DisableJTAG(void);

void AFIO_SetUARTConfiguration(AFIO_UART_ID Copy_u8UARTNumber , u8 Copy_u8RemapValue);

#endif
