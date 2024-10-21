/*=================================================================================*/
/*  File        : RCC_INTERFACE_H                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: RCC
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "LIB/STD_TYPES.h"
/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

typedef enum{
	 RCC_DMA1	=0
	,RCC_DMA2	=1
	,RCC_SRAM	=2
	,RCC_FLITF	=4
	,RCC_CRC	=6
	,RCC_FSMC	=8

/*******************************************************************************
*                        		APB2 Peripherals                               */
	,RCC_AFIO	=(0  +32)
	,RCC_GPIOA	=(2  +32)
	,RCC_GPIOB	=(3  +32)
	,RCC_GPIOC	=(4  +32)
	,RCC_ADC1	=(9  +32)
	,RCC_ADC2	=(10 +32)
	,RCC_TIM1	=(11 +32)
	,RCC_SPI1	=(12 +32)
	,RCC_TIM8	=(13 +32)
	,RCC_USART1	=(14 +32)
	,RCC_ADC3	=(15 +32)
	,RCC_TIM9	=(19 +32)
	,RCC_TIM10	=(20 +32)
	,RCC_TIM11	=(21 +32)

/*******************************************************************************
*                        		APB1 Peripherals                               *
*******************************************************************************/
	,RCC_TIM2		=(0  +64)
	,RCC_TIM3		=(1  +64)
	,RCC_TIM4		=(2  +64)
	,RCC_TIM5		=(3  +64)
	,RCC_TIM6		=(4  +64)
	,RCC_TIM7		=(5  +64)
	,RCC_TIM12		=(6  +64)
	,RCC_TIM13		=(7  +64)
	,RCC_TIM14		=(8  +64)
	,RCC_WWD		=(11 +64)
	,RCC_SPI2		=(14 +64)
	,RCC_SPI3		=(15 +64)
	,RCC_USART2		=(17 +64)
	,RCC_USART3		=(18 +64)
	,RCC_USART4		=(19 +64)
	,RCC_USART5		=(20 +64)
	,RCC_I2C1		=(21 +64)
	,RCC_I2C2		=(22 +64)
	,RCC_USB		=(23 +64)
	,RCC_CAN		=(25 +64)
	,RCC_BKP		=(27 +64)
	,RCC_PWR		=(28 +64)
	,RCC_DAC		=(29 +64)
}RCC_PER_ID;

typedef enum{
	RCC_Disable=0
	,RCC_Enable
}PER_STATE;


void RCC_InitSysClk	(void);

void RCC_PeripheralClk(RCC_PER_ID Copy_PeripheralId ,PER_STATE Copy_State);

#endif
