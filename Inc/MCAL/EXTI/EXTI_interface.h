/*=================================================================================*/
/*  File        : EXTI_INTERFACE_H                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: EXTI
 *  																				*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
	ANY_LOGIC_CHANGE=0,
	FALLING_EDGE,
	RISING_EDGE,
}Edge_trriger;

typedef enum{
	EXTI0=0
	,EXTI1
	,EXTI2
	,EXTI3
	,EXTI4
	,EXTI5
	,EXTI6
	,EXTI7
	,EXTI8
	,EXTI9
	,EXTI10
	,EXTI11
	,EXTI12
	,EXTI13
	,EXTI14
	,EXTI15
}EXTI_ID;

void EXTI_Interrupt_Enable(EXTI_ID Copy_u8EXTINumber ,Edge_trriger Edge );
void EXTI_Interrupt_Disable(EXTI_ID Copy_u8EXTINumber  );
void EXTI_SetCallBack(EXTI_ID Copy_u8EXTINumber , void(*Copy_pfCallback)(void));

#endif
