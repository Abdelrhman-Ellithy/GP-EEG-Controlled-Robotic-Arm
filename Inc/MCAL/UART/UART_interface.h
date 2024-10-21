/*=================================================================================*/
/*  File        : UART_INTERFACE_H_                                                  */
/*  Description : This Program file  for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: UART
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "LIB/STD_TYPES.h"
typedef enum{
	 UART_1=0
	,UART_2
	,UART_3
}UART_ID;


/*******************************************************************************
*                       Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		UART_Init
* Description:			Function to initialize the UART */
void UART_Init();

/*******************************************************************************
* Function Name:		UART_SendByte
* Description:			Function to send one byte using the UART */
void UART_SendByte(UART_ID Copy_u8UartNumber, u8 Copy_u8DataByte);

/*******************************************************************************
* Function Name:		UART_SendString
* Description:			Function to send string using the UART */
void UART_SendString(UART_ID Copy_u8UartNumber, u8* Copy_Pu8DataString);

/*******************************************************************************
* Function Name:		UART_SendStream
* Description:			Function to send stream of data using UART */
void UART_SendStream(UART_ID Copy_u8UartNumber, u8* Copy_pu8DataByte, u16 Copy_u8DataSize);

/*******************************************************************************
* Function Name:		UART_ReceiveByte
* Description:			Function to receive one byte using UART */
void UART_ReceiveByte(UART_ID Copy_u8UartNumber, u8* Copy_pu8DataByte);

/*******************************************************************************
* Function Name:		UART_ReceiveString
* Description:			Function to receive string using UART */
void UART_ReceiveString(UART_ID Copy_u8UartNumber, u8* Copy_pu8DataByte);

/*******************************************************************************
* Function Name:		UART_ReceiveStream
* Description:			Function to receive string using UART */
void UART_ReceiveStream(UART_ID Copy_u8UartNumber, u8* Copy_pu8DataByte, u16 Copy_u8DataSize);

/*******************************************************************************
* Function Name:		UART_u8SetCallBack
* Description:			Function to set the ISR */
void UART_SetCallBack(UART_ID Copy_u8UartNumber, void(*Copy_pfCallback)(void));



#endif /* UART_INTERFACE_H_ */
