#include "LIB/stm32f103c8t6.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/UART/UART_Config.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/UART/UART_private.h"

static UART_RegDef_t * UART_IDS[3] = {UART1,UART2,UART3};
typedef void(*fptr_t)(void);
static fptr_t UART_SetCallbacks[3] = {NULL,NULL,NULL};

extern volatile UART_DATA;

void UART_Init(){
		// 0b001
		#if UART1_EN==1

		//UART1->CR1=0;
		//UART1->CR2=0;
		//UART1->CR3=0;
		SET_BIT(UART1->CR1,13); /* Enable the UART */
		UART1->CR1|= (UART1_DataSize<<12);
		UART1->CR2|=UART1_StopBit<<12;
		UART1->CR1|= (UART1_Parity_bit<<9);
		UART1->CR1|= ( (UART1_Recive_Method&0b0011)<< 5);
		UART1->CR1|= (UART1_Dublex_Mode<<2);
		UART1->BRR= UART1_BUAD_Rate;
		//SET_BIT(UART1->CR2,11);
		UART1->CR3|=( (UART1_Recive_Method>>2)<<6);
		#endif

		#if UART2_EN==1

		//UART2->CR1=0;
		//UART2->CR2=0;
		//UART2->CR3=0;
		SET_BIT(UART2->CR1,13); /* Enable the UART */
		UART2->CR1|= (UART2_DataSize<<12);
		UART2->CR2|= (UART2_StopBit<<12);
		UART2->CR1|= (UART2_Parity_bit<<9);
		UART2->CR1|= ((UART2_Recive_Method& 0b0011)<< 5);
		UART2->CR1|= (UART2_Dublex_Mode<<2);  /* Transmit receive Enable */
		UART2->BRR= UART2_BUAD_Rate;
		UART2->CR3|=( (UART2_Recive_Method>>2)<<6);

	    #endif

		#if UART3_EN==1

		//UART3->CR1=0;
		//UART3->CR2=0;
		SET_BIT(UART3->CR1,13); /* Enable the UART */
		UART3->CR1|= (UART3_DataSize<<12);
		UART3->CR2|= (UART3_StopBit<<12);
		UART3->CR1|= (UART3_Parity_bit<<9);
		UART3->CR1|= ((UART3_Recive_Method& 0b0011)<< 5);
		UART3->CR1|= (UART3_Dublex_Mode<<2);  /* Transmit receive Enable */
		UART3->BRR= UART3_BUAD_Rate;
		UART3->CR3|=( (UART3_Recive_Method>>2)<<6);
		#endif
}

void UART_SendByte(UART_ID Copy_UartNumber, u8 Copy_u8DataByte){

	CLEAR_BIT(UART_IDS[Copy_UartNumber]->SR,6);
	UART_IDS[Copy_UartNumber]->DR=Copy_u8DataByte;
	while(GET_BIT(UART_IDS[Copy_UartNumber]->SR,6) == 0); /* Wait if the previous Transmission isn't completed */

}

/*******************************************************************************
* Function Name:		UART_SendString
* Description:			Function to send string using the UART */
void UART_SendString(UART_ID Copy_UartNumber, u8* Copy_Pu8DataString){

	if(Copy_Pu8DataString != NULL)
	{
		u16 i ;
		for(i = 0 ; Copy_Pu8DataString[i] != '\0'&& Copy_Pu8DataString[i] != '#' ; i++)
		{
			UART_SendByte(Copy_UartNumber,Copy_Pu8DataString[i]);
		}
		UART_SendByte(Copy_UartNumber,'\0');
	}

}

/*******************************************************************************
* Function Name:		UART_SendStream
* Description:			Function to send stream of data using UART */
void UART_SendStream(UART_ID Copy_UartNumber, u8* Copy_pu8DataByte, u16 Copy_u8DataSize){

	if(Copy_pu8DataByte != NULL)
	{
		while(Copy_u8DataSize --)
		{
			UART_SendByte(Copy_UartNumber,*Copy_pu8DataByte);
			Copy_pu8DataByte++;
		}
	}

}

/*******************************************************************************
* Function Name:		UART_ReceiveByte
* Description:			Function to receive one byte using UART */
void UART_ReceiveByte(UART_ID Copy_UartNumber, u8* Copy_pu8DataByte){

	u32 time_error = 0;
	if(Copy_pu8DataByte != NULL)
	{
		while(GET_BIT(UART_IDS[Copy_UartNumber]->SR,5) == 0)
		{
			time_error++;
			if(time_error == 65000)
			{
				*Copy_pu8DataByte = 255;
				break;
			}
		}
		if(time_error!=65000){
			*Copy_pu8DataByte = UART_IDS[Copy_UartNumber]->DR;
			CLEAR_BIT(UART_IDS[Copy_UartNumber]->SR,5); /* Clear the flag */
		}
	}
}

/*******************************************************************************
* Function Name:		UART_ReceiveString
* Description:			Function to receive string using UART */
void UART_ReceiveString(UART_ID Copy_UartNumber, u8* Copy_pu8DataByte){

	if(Copy_pu8DataByte != NULL)
	{
		u16 i = 0;
		UART_ReceiveByte(Copy_UartNumber,Copy_pu8DataByte+i);
		while(Copy_pu8DataByte[i] !='#' && Copy_pu8DataByte[i] != '\0')
		{
			i++;
			UART_ReceiveByte(Copy_UartNumber,Copy_pu8DataByte+i);
		}
		Copy_pu8DataByte[i] = '\0';
	}

}

/*******************************************************************************
* Function Name:		UART_ReceiveStream
* Description:			Function to receive string using UART */
void UART_ReceiveStream(UART_ID Copy_UartNumber, u8* Copy_pu8DataByte, u16 Copy_u8DataSize){

	if(Copy_pu8DataByte != NULL)
	{
		while(Copy_u8DataSize--)
		{
			UART_ReceiveByte(Copy_UartNumber,Copy_pu8DataByte++);
		}
	}
}

/*******************************************************************************
* Function Name:		UART_u8SetCallBack
* Description:			Function to set the ISR */
void UART_SetCallBack(UART_ID Copy_UartNumber, void(*Copy_pfCallback)(void)){

	if(Copy_pfCallback != NULL)
	{
		UART_SetCallbacks[Copy_UartNumber] = Copy_pfCallback;
	}
}


void USART1_IRQHandler(void)
{
	CLEAR_BIT(UART1->SR,5); /* Clear the flag */
	if(UART_SetCallbacks[0] != NULL)
	{
		UART_SetCallbacks[0]();
	}
}

void USART2_IRQHandler(void)
{
	CLEAR_BIT(UART2->SR,5); /* Clear the flag */
	if(UART_SetCallbacks[1] != NULL)
	{
		UART_SetCallbacks[1]();
	}
}

void USART3_IRQHandler(void)
{
	//UART_DATA=(u8)UART_IDS[2]->DR;
	CLEAR_BIT(UART3->SR,5); /* Clear the flag */
	if(UART_SetCallbacks[2]!= NULL)
	{
		UART_SetCallbacks[2]();
	}
}

