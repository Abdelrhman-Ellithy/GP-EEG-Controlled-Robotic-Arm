/*=================================================================================*/
/*  File        : AFIO ADC_CONFIG                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: ADC */

#ifndef ADC_CONFIG
#define ADC_CONFIG


#define ADC_DISABLE  			  0
#define ADC_ENABLE   			  1

#define ADC_SINGLE_CON_MODE       0
#define ADC_CONTINUOUS_CON_MODE   1

#define DMA_DISABLE      		  0
#define DMA_ENABLE        		  1



/**** config ***********/
#define ADC1_STATUS  ADC_ENABLE


#define ADC1_CON_MODE   ADC_CONTINUOUS_CON_MODE


#define DMA_STATUS  DMA_DISABLE

/* TIMEOUT to avoid infinite loops in Busy waiting */
#define  ADC_TIMEOUT      50000


#endif
