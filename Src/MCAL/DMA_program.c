/*=================================================================================*/
/*  File        : DMA_Program.c                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: DMA																				*/

#include "LIB/stm32f103c8t6.h"
#include "LIB/Types.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/DMA/DMA_config.h"
#include "MCAL/DMA/DMA_interface.h"
#include "MCAL/DMA/DMA_private.h"

static u32 DMA_COMMUNACTION_PER_ADD[]={
		 (u32)(&(UART1->DR))
		,(u32)(&(UART1->DR))
		,(u32)(&(UART2->DR))
		,(u32)(&(UART2->DR))
		,(u32)(&(UART3->DR))
		,(u32)(&(UART3->DR))
		,(u32)(&(SPI1->DR))
		,(u32)(&(SPI1->DR))
		,(u32)(&(SPI2->DR))
		,(u32)(&(SPI2->DR))
};
typedef void(*fun_ptr_t)(void);

static fun_ptr_t Setcallbaks_Ptr[7] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};

static void DMA_voidClearFlag( DMA_CHANNEL_t ChannelNumber , u8 Copy_u8Flag );

void DMA_voidChannelInit	( DMA_CHANNEL_t ChannelNumber ,
							  DMA_PRIORITY_t ChannelPriority   ,
							  DMA_DATA_Transfer_Size_t Mem_DataSize   ,
							  DMA_DATA_Transfer_Size_t Per_DataSize  ,
							  DMA_DATA_Transfer_type_t DataTransferType ,
							  DMA_Source_INC_t  source_IncrementMode    ,
							  DMA_DIST_INC_t Dist_IncrementMode  ,
							  DMA_TC_INT_EN_t EnableTCInt   ,
							  DMA_Cicular_Mode_t cicular_mode   )
{
	// wait until DMA CHannel is disabled
		DMA->CHANNEL[ChannelNumber].CCR=0;
		while(GET_BIT(DMA->CHANNEL[ChannelNumber].CCR,0)==1);
		switch(DataTransferType){
		 case DMA_PER_TO_MEM:
			 CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR,14);
			 CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR,4);
				DMA->CHANNEL[ChannelNumber].CCR|=(source_IncrementMode<<6); // suppose Peripheral is source
				DMA->CHANNEL[ChannelNumber].CCR|=(Dist_IncrementMode<<7);	// suppose memory is destination
			 break;
		 case DMA_MEM_TO_MEM:
			 SET_BIT(DMA->CHANNEL[ChannelNumber].CCR,14);
			 SET_BIT(DMA->CHANNEL[ChannelNumber].CCR,4);
				DMA->CHANNEL[ChannelNumber].CCR|=(source_IncrementMode<<6); // suppose Peripheral is source
				DMA->CHANNEL[ChannelNumber].CCR|=(Dist_IncrementMode<<7);	// suppose memory is destination
			 break;
		 case DMA_MEM_TO_PER:
			 CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR,14);
			 SET_BIT(DMA->CHANNEL[ChannelNumber].CCR,4);
				DMA->CHANNEL[ChannelNumber].CCR|=(source_IncrementMode<<7); // suppose Peripheral is source
				DMA->CHANNEL[ChannelNumber].CCR|=(Dist_IncrementMode<<6);	// suppose memory is destination
			 break;
		 case DMA_PER_TO_PER:
			 CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR,14);
			 CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR,4);
				DMA->CHANNEL[ChannelNumber].CCR|=(source_IncrementMode<<7); // suppose Peripheral is source
				DMA->CHANNEL[ChannelNumber].CCR|=(Dist_IncrementMode<<6);	// suppose memory is destination
			 break;
		}
		DMA->CHANNEL[ChannelNumber].CCR|=(ChannelPriority<<12);
		DMA->CHANNEL[ChannelNumber].CCR|=(Per_DataSize<<8);
		DMA->CHANNEL[ChannelNumber].CCR|=(Mem_DataSize<<10);
		DMA->CHANNEL[ChannelNumber].CCR|=(cicular_mode<<5);
		DMA->CHANNEL[ChannelNumber].CCR|=(EnableTCInt<<1);
}


void DMA_void_DMA_Enable( DMA_CHANNEL_t ChannelNumber ){
	DMA_voidClearFlag( ChannelNumber , DMA_GIF  );
	DMA_voidClearFlag( ChannelNumber , DMA_TCIF );
	DMA_voidClearFlag( ChannelNumber , DMA_HTIF );
	DMA_voidClearFlag( ChannelNumber , DMA_TEIF );
	SET_BIT(DMA->CHANNEL[ChannelNumber].CCR, 0);
}

void DMA_void_DMA_Disable( DMA_CHANNEL_t ChannelNumber ){

	CLEAR_BIT(DMA->CHANNEL[ChannelNumber].CCR, 0);
	while(GET_BIT(DMA->CHANNEL[ChannelNumber].CCR,0));
}

void DMA_CheckIfErrorOccurred	(DMA_CHANNEL_t ChannelNumber, u8 * Copy_Pu8ErrorState){

	* Copy_Pu8ErrorState=GET_BIT(DMA->ISR,( (ChannelNumber*4)+3) );
}
void DMA_ChannelTransfer(DMA_CHANNEL_t ChannelNumber, u32 Copy_u32MemAddress, u32 Copy_u32PerAddress, u16 Data_Transfer_length){

	DMA_void_DMA_Disable(ChannelNumber);
	if(Copy_u32PerAddress <10){

		DMA->CHANNEL[ChannelNumber].CPAR=DMA_COMMUNACTION_PER_ADD[Copy_u32PerAddress];
	}
	else if(Copy_u32PerAddress >9){

		DMA->CHANNEL[ChannelNumber].CPAR=Copy_u32PerAddress;
	}
	if(Copy_u32MemAddress<10){

		DMA->CHANNEL[ChannelNumber].CMAR=DMA_COMMUNACTION_PER_ADD[Copy_u32MemAddress];
	}
	else if(Copy_u32MemAddress>9){

		DMA->CHANNEL[ChannelNumber].CMAR=Copy_u32MemAddress;
	}

	DMA->CHANNEL[ChannelNumber].CNDTR=Data_Transfer_length;
}

void DMA_SetCallBack(DMA_CHANNEL_t ChannelNumber, void(*Copy_pfCallback)(void)){

	Setcallbaks_Ptr[ChannelNumber]=Copy_pfCallback;
}

static void DMA_voidClearFlag( DMA_CHANNEL_t ChannelNumber , u8 Copy_u8Flag ){

	ChannelNumber *= 4 ;

	SET_BIT( DMA->IFCR , (ChannelNumber + Copy_u8Flag) );

}
/* DMA1 Channel1 global interrupt                   */
void	DMA1_Channel1_IRQHandler  (void){
	if(Setcallbaks_Ptr[0]!=NULL){
		Setcallbaks_Ptr[0]();
	}
}


/* DMA1 Channel2 global interrupt                   */
void	DMA1_Channel2_IRQHandler  (void){
	if(Setcallbaks_Ptr[1]!=NULL){
		Setcallbaks_Ptr[1]();
	}
}



/* DMA1 Channel3 global interrupt                   */
void	DMA1_Channel3_IRQHandler  (void){
	if(Setcallbaks_Ptr[2]!=NULL){
		Setcallbaks_Ptr[2]();
	}
}


/* DMA1 Channel4 global interrupt                   */
void	DMA1_Channel4_IRQHandler  (void){
	if(Setcallbaks_Ptr[3]!=NULL){
		Setcallbaks_Ptr[3]();
	}
}

/* DMA1 Channel5 global interrupt                   */
void	DMA1_Channel5_IRQHandler  (void){
	if(Setcallbaks_Ptr[4]!=NULL){
		Setcallbaks_Ptr[4]();
	}
}


/* DMA1 Channel6 global interrupt                   */
void	DMA1_Channel6_IRQHandler  (void){
	if(Setcallbaks_Ptr[5]!=NULL){
		Setcallbaks_Ptr[5]();
	}
}


/* DMA1 Channel7 global interrupt                   */
void	DMA1_Channel7_IRQHandler  (void){
	if(Setcallbaks_Ptr[6]!=NULL){
		Setcallbaks_Ptr[6]();
	}
}

