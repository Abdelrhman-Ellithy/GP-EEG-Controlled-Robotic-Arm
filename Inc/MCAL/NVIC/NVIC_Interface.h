/*=================================================================================*/
/*  File        : NVIC_INTERFACE_H                                                */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: NVIC
 */


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/****************************************************************************
*                     	NVIC INTERTUPT NUMBER                              **/

typedef enum{
	 NVIC_WWDG=0
	,NVIC_PVD
	,NVIC_TAMPER
	,NVIC_RTC
	,NVIC_FLASH
	,NVIC_RCC
	,NVIC_EXTI0
	,NVIC_EXTI1
	,NVIC_EXTI2
	,NVIC_EXTI3
	,NVIC_EXTI4
	,NVIC_DMA1_CHANNEL1
	,NVIC_DMA1_CHANNEL2
	,NVIC_DMA1_CHANNEL3
	,NVIC_DMA1_CHANNEL4
	,NVIC_DMA1_CHANNEL5
	,NVIC_DMA1_CHANNEL6
	,NVIC_DMA1_CHANNEL7
	,NVIC_ADC1_2
	,NVIC_CAN_TX
	,NVIC_CAN_RX0
	,NVIC_CAN_RX1
	,NVIC_CAN_SCE
	,NVIC_EXTI9_5
	,NVIC_TIM1_BRK
	,NVIC_TIM1_UP
	,NVIC_TIM1_TRG_COM
	,NVIC_TIM1_CC
	,NVIC_TIM2
	,NVIC_TIM3
	,NVIC_TIM4
	,NVIC_I2C1_EV
	,NVIC_I2C1_ER
	,NVIC_I2C2_EV
	,NVIC_I2C2_ER
	,NVIC_SPI1
	,NVIC_SPI2
	,NVIC_USART1
	,NVIC_USART2
	,NVIC_USART3
	,NVIC_EXTI15_10
	,NVIC_RTCALARM
	,NVIC_USBWAKEUP
	,NVIC_TIM8_BRK
	,NVIC_TIM8_UP
	,NVIC_TIM8_TRG_COM
	,NVIC_TIM8_CC
	,NVIC_ADC3
	,NVIC_FSMC
	,NVIC_SDIO
	,NVIC_TIM5
	,NVIC_SPI3
	,NVIC_UART4
	,NVIC_UART5
	,NVIC_TIM6
	,NVIC_TIM7
	,NVIC_DMA2_Channel1
	,NVIC_DMA2_Channel2
	,NVIC_DMA2_Channel3
	,NVIC_DMA2_Channel4_5

}NVIC_INTERTUPT_id;

#define NVIC_GROUP0_SUB0	0b000000000
#define NVIC_GROUP0_SUB1	0b000100000

#define NVIC_GROUP1_SUB0	0b010000000
#define NVIC_GROUP1_SUB1	0b010100000

void NVIC_Init(void);

void NVIC_EnableInterrupt(NVIC_INTERTUPT_id Copy_InterruptID);

void NVIC_DisableInterrupt(NVIC_INTERTUPT_id Copy_InterruptID);


void NVIC_SetInterruptPending(NVIC_INTERTUPT_id Copy_InterruptID);

void NVIC_SClearInterruptPending(NVIC_INTERTUPT_id Copy_InterruptID);

void NVIC_SetGroupPriority(NVIC_INTERTUPT_id Copy_InterruptID,u8 Copy_u8GroupPriority);

void NVIC_GenerateSWInerrupt(NVIC_INTERTUPT_id Copy_InterruptID);

#endif
