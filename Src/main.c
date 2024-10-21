/**
 ******************************************************************************
 * @file           : Graduation Project main.c
 * @author         : Abdelrahman Ellithy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 Abdelrahman Ellithy.
 * All rights reserved.
 ******************************************************************************
 */
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/AFIO/AFIO_interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/UART/UART_interface.h"
#include "HAL/Servo/Servo_Interface.h"
#include "LIB/ellithy_delay.h"
#include "MCAL/DMA/DMA_interface.h"
u8 servoAngle;
void controlServos(){
	switch(servoAngle){
	case '0': servoAngle=0;break;
	case '1': servoAngle=45;break;
	case '2': servoAngle=63;break;
	case '3': servoAngle=90;break;
	case '4': servoAngle=135;break;
	case '5': servoAngle=180;break;
	}
		Servo_setAngle(SERVO_1, servoAngle);
		Servo_setAngle(SERVO_2, servoAngle);
		Servo_setAngle(SERVO_3, servoAngle);
		Servo_setAngle(SERVO_4, servoAngle);
}
int main(void)
{
		RCC_InitSysClk();
		RCC_PeripheralClk(RCC_GPIOA, RCC_Enable);
		RCC_PeripheralClk(RCC_AFIO,   RCC_Enable);
		RCC_PeripheralClk(RCC_USART2, RCC_Enable);
		RCC_PeripheralClk(RCC_TIM1, RCC_Enable);
		RCC_PeripheralClk(RCC_DMA1, RCC_Enable);
		GPIO_PORT_voidInit();
		TIMER1_Init(TIMER1_COUNT_UP,4);
		SERVO_Init(SERVO_1);
		SERVO_Init(SERVO_2);
		SERVO_Init(SERVO_3);
		SERVO_Init(SERVO_4);
		NVIC_Init();
		UART_Init();
		DMA_voidChannelInit(DMA_CHANNEL6,
							DMA_PRIORITY_HIGH,
							DMA_DATA_SIZE_1BYTE,
							DMA_DATA_SIZE_1BYTE,
							DMA_PER_TO_MEM,
							DMA_SOURCE_INC_DISEN,
							DMA_DIST_INC_DISEN,
							DMA_TC_INT_ENABLE,
							circular
							);
		DMA_SetCallBack(DMA_CHANNEL6, controlServos);
		DMA_ChannelTransfer(DMA_CHANNEL6,(u32)&servoAngle,(u32)DMA_Recieve_UART2_CH6,1);
		DMA_void_DMA_Enable(DMA_CHANNEL6);
		NVIC_EnableInterrupt(NVIC_DMA1_CHANNEL6);
		NVIC_EnableInterrupt(NVIC_USART2);
		while(1){

		}
}
