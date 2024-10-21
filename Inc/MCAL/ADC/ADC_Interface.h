/*=================================================================================*/
/*  File        : ADC INTERFACE                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: ADC */

#ifndef ADC_INTERFACE
#define ADC_INTERFACE

typedef enum{
	  ADC_Channel_0
	 ,ADC_Channel_1
	 ,ADC_Channel_2
	 ,ADC_Channel_3
	 ,ADC_Channel_4
	 ,ADC_Channel_5
	 ,ADC_Channel_6
	 ,ADC_Channel_7
	 ,ADC_Channel_8
	 ,ADC_Channel_9
}ADC_Channel;


void ADC1_voidInit(void);
u8  ADC1_u8GetResultSync(  u16* Copy_pu16Result );
u8  ADC1_u8GetResultASync(ADC_Channel Channel, u16* Copy_pu16Reading);
void ADC1_voidChangeCh(u8 Copy_u8Channel);

#endif
