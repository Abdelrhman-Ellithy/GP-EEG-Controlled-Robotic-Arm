/*=================================================================================*/
/*  File        : ADC INTERFACE                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: ADC */


#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADC1_CR2_ADON      		0
#define ADC1_CR2_CONT      		1
#define ADC1_CR2_DMA       		8
#define ADC1_CR2_SWSTART   		22
#define ADC1_CR1_EOCIE     		5
#define ADC1_SR_EOC    			1

#define BUSY	 0
#define NOT_BUSY 1

#endif
