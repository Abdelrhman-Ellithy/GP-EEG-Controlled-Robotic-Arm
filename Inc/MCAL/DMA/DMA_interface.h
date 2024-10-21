/*=================================================================================*/
/*  File        : DMA_INTERFACE_H_                                                  */
/*  Description : This Program file  for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: DMA
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include <LIB/stm32f103c8t6.h>

typedef enum{
	 DMA_CHANNEL1= 0
	,DMA_CHANNEL2
	,DMA_CHANNEL3
	,DMA_CHANNEL4
	,DMA_CHANNEL5
	,DMA_CHANNEL6
	,DMA_CHANNEL7
}DMA_CHANNEL_t;

typedef enum{
	 DMA_PRIORITY_LOW=0
	,DMA_PRIORITY_MEDIUM
	,DMA_PRIORITY_HIGH
	,DMA_PRIORITY_VERYHIGH
}DMA_PRIORITY_t;

typedef enum{
	 DMA_DATA_SIZE_1BYTE=0
	,DMA_DATA_SIZE_2BYTES
	,DMA_DATA_SIZE_4BYTES
}DMA_DATA_Transfer_Size_t;

typedef enum{
	 DMA_PER_TO_MEM=0
	,DMA_MEM_TO_PER
	,DMA_MEM_TO_MEM
	,DMA_PER_TO_PER
}DMA_DATA_Transfer_type_t;


typedef enum{
	 DMA_TC_INT_DISABLE	=0
	,DMA_TC_INT_ENABLE
}DMA_TC_INT_EN_t;

typedef enum{
	 DMA_CH_DisEN=0
	,DMA_TCH_EN
}DMA_CH_EN_t;

typedef enum
{
	 DMA_SOURCE_INC_DISEN=0
	 ,DMA_SOURCE_INC_EN
}DMA_Source_INC_t;

typedef enum
{
	  DMA_DIST_INC_DISEN=0
	 ,DMA_DIST_INC_EN
}DMA_DIST_INC_t;

typedef enum
{
	  only_once=0
	 ,circular
}DMA_Cicular_Mode_t;

//DMA Flags
#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3

/*******************************************************************************
*              	PERIPHERALS index AND CHANNEL	                   **/

#define DMA_Transfeer_UART1_CH4				0
#define DMA_Recieve_UART1_CH5				1
#define DMA_Transfeer_UART2_CH7				2
#define DMA_Recieve_UART2_CH6				3
#define DMA_Transfeer_UART3_CH2				4
#define DMA_Recieve_UART3_CH3				5
#define DMA_Transfeer_SPI1_CH3				6
#define DMA_Recieve_SPI1_CH2				7
#define DMA_Transfeer_SPI2_CH5				8
#define DMA_Recieve_SPI2_CH4				9

void DMA_voidChannelInit	(
							  DMA_CHANNEL_t ChannelNumber ,
							  DMA_PRIORITY_t ChannelPriority   ,
							  DMA_DATA_Transfer_Size_t Mem_DataSize   ,
							  DMA_DATA_Transfer_Size_t Per_DataSize  ,
							  DMA_DATA_Transfer_type_t DataTransferType ,
							  DMA_Source_INC_t  source_IncrementMode    ,
							  DMA_DIST_INC_t Dist_IncrementMode  ,
							  DMA_TC_INT_EN_t EnableTCInt   ,
							  DMA_Cicular_Mode_t cicular_mode   );

void DMA_void_DMA_Enable( DMA_CHANNEL_t ChannelNumber );

void DMA_void_DMA_Disable( DMA_CHANNEL_t ChannelNumber );

void DMA_ChannelTransfer(DMA_CHANNEL_t Channel, u32 Copy_u32MemAddress, u32 Copy_u32PerAddress, u16 Data_Transfer_length);

void DMA_CheckIfErrorOccurred	(DMA_CHANNEL_t Channel, u8 * Copy_Pu8ErrorState);

void DMA_SetCallBack(DMA_CHANNEL_t Channel, void(*Copy_pfCallback)(void));

#endif /* DMA_INTERFACE_H_ */
