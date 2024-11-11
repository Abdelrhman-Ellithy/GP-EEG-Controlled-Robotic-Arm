/**
 ******************************************************************************
 * @file           : Graduation Project main.c
 * @author         : Abdelrahman Ellithy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
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

/*
 * Movements
 */
#define GRAB '1'
#define RELEASE '2'
#define UP '3'
#define DOWN '4'
#define RIGHT_MOST '5'
#define LEFT_MOST '6'
#define INIT_STATE '7'

/*
 *Angles I mesured,maybe modifed latter after Test
 */

#define BACK_MOST_ANGLE 50
#define FORWARD_MOST_ANGLE 130

#define RIGHT_MOST_ANGLE 0
#define LEFT_MOST_ANGLE 160

#define DOWN_MOST_ANGLE 10
#define UP_MOST_ANGLE 120

#define RELEASE_MOST_ANGLE 10
#define GRAB_MOST_ANGLE 120


 /* Servo Motors */

#define Servo_RIGHT_LIFT_Rotation 	SERVO_1 // PA8
#define Servo_FORWARD_BACKWARD 		SERVO_2 // PA9
#define Servo_UP_DOWN		 		SERVO_3 // PA10
#define Servo_GRABBER 				SERVO_4 // PA11

volatile u8 EEG_CMD,
			arrServoLastValue[4];

void solveCMD();
void grab();
void release();
void moveUp();
void moveDown();
void rotateLeft();
void rotateRight();
void returnToInitialState();

//delay for smooth movements
void setAngle(ServoID_t servo_ID, u8 angle);

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
		DMA_SetCallBack(DMA_CHANNEL6, solveCMD);
		DMA_ChannelTransfer(DMA_CHANNEL6,(u32)&EEG_CMD,(u32)DMA_Recieve_UART2_CH6,1);
		DMA_void_DMA_Enable(DMA_CHANNEL6);
		NVIC_EnableInterrupt(NVIC_DMA1_CHANNEL6);
		NVIC_EnableInterrupt(NVIC_USART2);
		EEG_CMD=INIT_STATE;
		solveCMD();
		while(1){

		}
}

void solveCMD() {
  switch (EEG_CMD) {
    case GRAB: grab(); break;
    case RELEASE: release(); break;
    case UP: moveUp(); break;
    case DOWN: moveDown(); break;
    case RIGHT_MOST: rotateRight(); break;
    case LEFT_MOST: rotateLeft(); break;
    case INIT_STATE: returnToInitialState(); break;
    default: break;
  }
}
void moveUp() {
	setAngle(Servo_UP_DOWN, UP_MOST_ANGLE/4);
	setAngle(Servo_FORWARD_BACKWARD, BACK_MOST_ANGLE/4);
	setAngle(Servo_UP_DOWN, UP_MOST_ANGLE/2);
	setAngle(Servo_FORWARD_BACKWARD, BACK_MOST_ANGLE/2);
	setAngle(Servo_UP_DOWN, UP_MOST_ANGLE);
	setAngle(Servo_FORWARD_BACKWARD, BACK_MOST_ANGLE);

}

void moveDown() {
	setAngle(Servo_UP_DOWN, DOWN_MOST_ANGLE/4);
	setAngle(Servo_FORWARD_BACKWARD, FORWARD_MOST_ANGLE/4);
	setAngle(Servo_UP_DOWN, DOWN_MOST_ANGLE/2);
	setAngle(Servo_FORWARD_BACKWARD, FORWARD_MOST_ANGLE/2);
	setAngle(Servo_UP_DOWN, DOWN_MOST_ANGLE);
	setAngle(Servo_FORWARD_BACKWARD, FORWARD_MOST_ANGLE);
}

void grab() {
	setAngle(Servo_GRABBER, GRAB_MOST_ANGLE);
}

void release() {
	setAngle(Servo_GRABBER, RELEASE_MOST_ANGLE);
}

void rotateLeft() {
	setAngle(Servo_RIGHT_LIFT_Rotation, LEFT_MOST_ANGLE);
}

void rotateRight() {
	setAngle(Servo_RIGHT_LIFT_Rotation, RIGHT_MOST_ANGLE);
}

void returnToInitialState() {
	setAngle(Servo_RIGHT_LIFT_Rotation, (RIGHT_MOST_ANGLE + LEFT_MOST_ANGLE) / 2);
	setAngle(Servo_GRABBER, RELEASE_MOST_ANGLE);
	setAngle(Servo_FORWARD_BACKWARD, (FORWARD_MOST_ANGLE + BACK_MOST_ANGLE) / 2);
	setAngle(Servo_UP_DOWN, (UP_MOST_ANGLE + DOWN_MOST_ANGLE) / 2);
}

void setAngle(ServoID_t servo_ID, u8 targetAngle) {

  u8 currentAngle = arrServoLastValue[servo_ID];
  if (currentAngle == targetAngle){
	  return;
  }
  else {
	  arrServoLastValue[servo_ID]=targetAngle;
	  s8 step = (targetAngle > currentAngle) ? 1 : -1;
	  for (u8 angle = currentAngle; angle != targetAngle; angle += step) {
		  Servo_setAngle(servo_ID,angle);
	      _delay_ms(8);
	  }
	  Servo_setAngle(servo_ID,targetAngle);
	  return;
  }
}
