/*=================================================================================*/
/*  File        : UART_CONFIG_H_                                                  */
/*  Description : This Program file for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: UART
 */


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define UART1_EN           0
#define UART2_EN           1
#define UART3_EN           0

/*******************************************************************************
*                       	   	STOP BITS		   		                       *
*******************************************************************************/
typedef enum{
	 UART_STOP_1_BIT	=0b00
	,UART_STOP_0_5_BIT	=0b01
	,UART_STOP_2_BITS	=0b10
	,UART_STOP_1_5_BITS =0b11
}UART_StopBit;
/*******************************************************************************
*                       	   	DATA SIZE		                	           *
*******************************************************************************/
typedef enum{

	 UART_8_BITS=0
	,UART_9_BITS

}UART_DataSize;

/*******************************************************************************
*                       	   	 Dublex	 mode  		             	           *
*******************************************************************************/
typedef enum{
	   UART_FULL_dublex=3
	  ,UART_Transmit_Only=2
	  ,UART_Recive_Only=1
}UART_Dublex_M;
/*******************************************************************************
*                       	   	PARTIY		   		             	           *
*******************************************************************************/
typedef enum{
	   UART_PARITY_DISABLED=0b00
	  ,UART_PARITY_EVEN	=0b10
	  ,UART_PARITY_ODD=	0b11
}UART_Parity;
/*******************************************************************************
*                       	   	RECEIVE METHOD		                	       *
*******************************************************************************/
/*		DMA send EN		DMA rec EN		TRAN EN		REC EN
     0b 0				0				0			0
	 0b 1				1
       	0b1001
		0b0100
		0b1100
		0b0011
*/
typedef enum{
	 UART_POLLING=0b0000             /* DMA disabled, send and receive with poling */
	,UART_INTERRUPT_RX= 0b0001       /* DMA disabled, send with polling and receive with interrupt */
	,UART_INTERRUPT_TX_RX= 0b0011 	 /* DMA disabled, send and receive with interrupt */
	,UART_DMA_TX_POL_RX	=0b1000      /* Send with DMA receive with polling */
	,UART_DMA_TX_INT_RX	= 0b1010     /* Send with DMA receive with interrupt */
	,UART_DMA_RX= 0b0100             /* Receive with DMA send with polling */
	,UART_DMA_TX_RX=0b1100           /* Send with DMA receive with DMA */
	,UART_DMA_TX_INTERRUPT_RX=0b1001 /* Send with DMA receive with interrupt */
}UART_Recive_M;

#define UART_BAUD_RATE_9600 				 0x0341

#define UART_BAUD_RATE_115200 				 0x0045

#if UART1_EN==1

#define UART1_Recive_Method		UART_DMA_RX
#define UART1_Parity_bit		UART_PARITY_DISABLED
#define UART1_DataSize			UART_8_BITS
#define UART1_StopBit			UART_STOP_1_BIT
#define UART1_BUAD_Rate			0x01A0					/*calculate it */
#define UART1_Dublex_Mode		UART_FULL_dublex
#endif

#if UART2_EN==1

#define UART2_Recive_Method      UART_DMA_TX_RX
#define UART2_Parity_bit         UART_PARITY_DISABLED
#define UART2_DataSize           UART_8_BITS
#define UART2_StopBit            UART_STOP_1_BIT
#define UART2_BUAD_Rate          UART_BAUD_RATE_9600
#define UART2_Dublex_Mode        UART_FULL_dublex
#endif


#if UART3_EN==1
#define UART3_Recive_Method      UART_DMA_TX_INTERRUPT_RX
#define UART3_Parity_bit         UART_PARITY_DISABLED
#define UART3_DataSize           UART_8_BITS
#define UART3_StopBit            UART_STOP_1_BIT
#define UART3_BUAD_Rate          0x01A0
#define UART3_Dublex_Mode        UART_FULL_dublex
#endif

#endif
