#include "LIB/Types.h"
#include "LIB/stm32f103c8t6.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/ADC/ADC_Config.h"
#include "MCAL/ADC/ADC_Private.h"

static u8 currunetChannel=0xff, Channelreaded=1 ;

void ADC1_voidInit(void)
{
	/* ADC1 Enable Condition    */
	#if ADC1_STATUS == ADC_ENABLE

	/* Enable ADC Peripheral */
	SET_BIT( ADC1_CR2 , ADC1_CR2_ADON );

	/***********************************************************************************/
	/*************************  ADC1 Config  *******************************************/
	/***********************************************************************************/

	/* Conversion Mode */
	#if ADC1_CON_MODE == ADC_SINGLE_CON_MODE
		CLEAR_BIT( ADC1_CR2 , ADC1_CR2_CONT );

	#elif ADC1_CON_MODE == ADC_CONTINUOUS_CON_MODE
		SET_BIT( ADC1_CR2 , ADC1_CR2_CONT );

	#endif
	/*******************/

	/* Set conversion sequence length to 1 L[3:0]*/
	ADC1_SQR1 &=0xff0fffff ;
	/*******************/
	//ADC1_SMPR2 |=0b100;

	/*  Set start of conversion sequence to ch 0 (PA0)*/
	ADC1_SQR3 = 0 ;
	/*******************/

	/* Enable DMA */
	#if DMA_STATUS == DMA_DISABLE
		CLEAR_BIT( ADC1_CR2 , ADC1_CR2_DMA );

	#elif DMA_STATUS == DMA_ENABLE
		SET_BIT( ADC1_CR2 , ADC1_CR2_DMA );

	#endif
	/*******************/



	/***********************************************************************************/

/* ADC1 Disable Condition    */
#elif ADC1_STATUS == ADC_DISABLE

	/* Disable ADC1 Peripheral */
	CLR_BIT( ADC1_CR2 , ADC1_CR2_ADON );

#endif


}

u8 ADC1_u8GetResultSync( u16* Copy_pu16Result )
{

	u8 LOC_u8ErrorState = OK ;

	u32 LOC_u32Counter = 0 ;

			/*
				Hint:
					=> We may config the channel here and take it as an argument from the user in this func
					   if we had many channels
					=> In This App we config this for Ch1 @ ADC1_voidInit
			*/
			/*Start conversion*/
			SET_BIT( ADC1_CR2 , ADC1_CR2_ADON );
			SET_BIT(ADC1_CR2,ADC1_CR2_SWSTART);

			/***********************************************************************************************************************/
			/* Polling (Busy Waiting) until The conversion complete (EOC flag is set) OR  LOC_u32Counter reached ADC_TIMEOUT */

			while( ( GET_BIT( ADC1_SR , ADC1_SR_EOC ) == 0 ) && ( LOC_u32Counter != ADC_TIMEOUT) )
			{
				LOC_u32Counter ++ ;
			}
			/* Check The reason of breaking the loop   */
			if (LOC_u32Counter == ADC_TIMEOUT)
			{
				/* Loop is broken because time_out is reached */
				LOC_u8ErrorState = NOK ;
			}
			else
			{
				/* Loop is broken because Flag is raised */

				/*
					Clear the conversion complete flag
				    CLR_BIT( ADC1_SR , ADC1_SR_EOC ); we will clear it by reading ADC1_DR
				*/

				/* Return The Reading & Clear EOC flag */
				* Copy_pu16Result = ADC1_DR ;
			}
	return LOC_u8ErrorState ;
}

void ADC1_voidChangeCh(u8 Copy_u8Channel)
{
	/*  Set start of conversion sequence to ch 0 (PA0)*/
	ADC1_SQR3 = Copy_u8Channel ;

}
u8  ADC1_u8GetResultASync(ADC_Channel Channel, u16* Copy_pu16Reading){

	u8 ADC_u18BusyFlag=(GET_BIT(ADC1_SR, ADC1_SR_EOC));

	    if ( ADC_u18BusyFlag == BUSY)
	    {
			Channelreaded=0;
	        return 0;
	    }
	    else if(ADC_u18BusyFlag==NOT_BUSY)
	    {
			if(Channel==currunetChannel){

				*Copy_pu16Reading=(u16)ADC1_DR;
					Channelreaded=1;
					return 1;
			}
			else
			{

			if(Channelreaded)
				{
					currunetChannel=Channel;
					/*   Select channel   */
					if (Channel<ADC_Channel_9+1 )
					{
						ADC1_SQR3 &=(0xFFFFFFF0);
						ADC1_SQR3 |= Channel;
					}
					/*start cnversion*/
				    SET_BIT(ADC1_CR2, ADC1_CR2_SWSTART);
					Channelreaded=0;
				}
				else
				{
					return 0;
				}
			}
		}

}
