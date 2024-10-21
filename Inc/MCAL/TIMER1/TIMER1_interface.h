/*=================================================================================*/
/*  File        : TIMER1_INTERFACE_H_                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: Timer1
 *  																				*/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


typedef enum{
	 TIMER1_COUNT_UP=0
	,TIMER1_COUNT_DOWN
}Count_Mode;


typedef enum{
	 TIMER1_PWM_CHANNEL1=0
	,TIMER1_PWM_CHANNEL2
	,TIMER1_PWM_CHANNEL3
	,TIMER1_PWM_CHANNEL4

}PWM_CHANNEL;

typedef enum{
	 TIMER1_ICU_CHANNEL1=0
	,TIMER1_ICU_CHANNEL2
	,TIMER1_ICU_CHANNEL3
	,TIMER1_ICU_CHANNEL4

}ICU_CHANNEL;

typedef enum{
	 TIMER1_ICU_RISING=0
	,TIMER1_ICU_FALLING

}ICU_EDGE;

void TIMER1_SetFREQ(PWM_CHANNEL Copy_PwmChannel , u32 Copy_PwmFrequency);

void TIMER1_Set_CRR_Value(PWM_CHANNEL Copy_PwmChannel , u16 Copy_Value );

void TIMER1_Init(Count_Mode Copy_Direction , u16 Copy_u16Prescaler);

void TIMER1_InitPwmChannel(PWM_CHANNEL Copy_PwmChannel);

void TIMER1_SetPWM_FREQ(PWM_CHANNEL Copy_PwmChannel , u32 Copy_u8PwmFrequency , u8 Copy_u8PwmDutyCycle);

void TIMER1_Stop(void);
/*
void TIMER1_PWM_ICU_Init();

void TIMER1_ICU_SetCallBack( void(*Copy_pfCallback)(void));
*/
#endif /* TIMER1_INTERFACE_H_ */
