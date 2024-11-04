/*=================================================================================*/
/*  File        : TIMER1_program.c                                                 */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: TIMER1
 *  																				*/

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/stm32f103c8t6.h"
#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/TIMER1/TIMER1_private.h"
#include "MCAL/TIMER1/TIMER1_config.h"
#include "HAL/LCD/CLCD_interface.h"

static void (*TIMER1_callback)(void) = NULL;

void TIMER1_Init(Count_Mode Copy_Direction , u16 Copy_u16Prescaler)
{
	TIMER1->CR1 = 0;
	SET_BIT(TIMER1->CR1,7); /* Auto reload pre-load enable */
	TIMER1->CR1 |= ((Copy_Direction) << 4); /* Set the direction up or down */
	TIMER1->PSC = ( Copy_u16Prescaler - 1 ) ;
}

void TIMER1_InitPwmChannel(PWM_CHANNEL Copy_PwmChannel)
{
	switch(Copy_PwmChannel)
	{
	case TIMER1_PWM_CHANNEL1:
		SET_BIT(TIMER1->CCMR1,3);
		CLR_BIT(TIMER1->CCMR1,0);  /* Channel is output compare */ /* Output compare preload enable */
		CLR_BIT(TIMER1->CCMR1,1);  /* Channel is output compare */ /* Output compare preload enable */
		TIMER1->CCMR1 |= (0b111 << 4); /* PWM mode 2 */
		CLR_BIT(TIMER1->CCER,1); /* high output polarity */
		SET_BIT(TIMER1->CCER,0); /* Output enable */
		break;

	case TIMER1_PWM_CHANNEL2:
		TIMER1->CCMR1 &= ~(0b11<<8);
		SET_BIT(TIMER1->CCMR1,11);
		TIMER1->CCMR1 |= (0b111 << 12);
		CLR_BIT(TIMER1->CCER,5);
		SET_BIT(TIMER1->CCER,4);
		break;

	case TIMER1_PWM_CHANNEL3:
		TIMER1->CCMR2 &= ~(0b11);
		SET_BIT(TIMER1->CCMR2,3);
		TIMER1->CCMR2 |= (0b111 << 4);
		CLR_BIT(TIMER1->CCER,9);
		SET_BIT(TIMER1->CCER,8);
		break;

	case TIMER1_PWM_CHANNEL4:
		TIMER1->CCMR2 &= ~(0b11<<8);
		SET_BIT(TIMER1->CCMR2,11);
		TIMER1->CCMR2 |= (0b111 << 12);
		CLR_BIT(TIMER1->CCER,13);
		SET_BIT(TIMER1->CCER,12);
		break;
	}

}

void TIMER1_SetPWM_FREQ(PWM_CHANNEL Copy_PwmChannel , u32 Copy_PwmFrequency , u8 Copy_PwmDutyCycle)
{
	if( Copy_PwmDutyCycle < 101)
	{	//							((8000000/(10000*1)*100)-1
	    u16 ARR_Value = ((u16)(u64)(F_CPU /((u64)Copy_PwmFrequency *(TIMER1->PSC + 1))) - 1);
	    u16 CCR_Value;
	    if(Copy_PwmDutyCycle!=0){
	    	CCR_Value = ((u16)(((u64)Copy_PwmDutyCycle * (ARR_Value + 1)) / 100)-1);
	    }
	    else{
	    	CCR_Value=0;
	    }
	    //ARR_Value/=10;
	    //CCR_Value/=10;
	    if(Copy_PwmChannel>=TIMER1_PWM_CHANNEL1 && Copy_PwmChannel<=TIMER1_PWM_CHANNEL4){
			TIMER1->ARR = ARR_Value ; 																								/* Setup Frequency */
			TIMER1->CCR[Copy_PwmChannel] = CCR_Value; 																							/* Setup Duty Cycle */
			SET_BIT(TIMER1->BDTR,15); 																						/* Enable MOE */
			SET_BIT(TIMER1->CR1,0); 																						/* Enable the timer */
	    }

	}

}
void TIMER1_SetFREQ(PWM_CHANNEL Copy_PwmChannel , u32 Copy_PwmFrequency)
{
	    u16 ARR_Value = (u16)((u64)(F_CPU /((u64)Copy_PwmFrequency *(TIMER1->PSC + 1))) - 1);
	    if(Copy_PwmChannel>=TIMER1_PWM_CHANNEL1 && Copy_PwmChannel<=TIMER1_PWM_CHANNEL4){
			TIMER1->ARR = ARR_Value ; 																								/* Setup Frequency */
			SET_BIT(TIMER1->BDTR,15); 																						/* Enable MOE */
			SET_BIT(TIMER1->CR1,0); 																						/* Enable the timer */
	    }

}
void TIMER1_SetARRValue( u16 ARR_Value)
{
	    if(ARR_Value< 65536){
			TIMER1->ARR = ARR_Value ; 																						/* Setup Frequency */
			//SET_BIT(TIMER1->BDTR,15); 																						/* Enable MOE */
			//SET_BIT(TIMER1->CR1,0); 																						/* Enable the timer */
	    }

}
void TIMER1_Set_CRR_Value(PWM_CHANNEL Copy_PwmChannel , u16 Copy_Value )
{
	if( Copy_Value < 65536)
	{
	    if(Copy_PwmChannel>=TIMER1_PWM_CHANNEL1 && Copy_PwmChannel<=TIMER1_PWM_CHANNEL4){																							/* Setup Frequency */
			TIMER1->CCR[Copy_PwmChannel] = Copy_Value; 																							/* Setup Duty Cycle */
			SET_BIT(TIMER1->BDTR,15); 																						/* Enable MOE */
			SET_BIT(TIMER1->CR1,0); 																						/* Enable the timer */
	    }

	}
}
/*
void TIMER1_PWM_ICU_Init(ICU_CHANNEL ICU_channel_ID, ICU_EDGE edge){
	switch(ICU_channel_ID){
	  case TIMER1_ICU_CHANNEL1:
		  CLR_BIT(TIMER1->CCMR1, 1);
		  SET_BIT(TIMER1->CCMR1, 0);
		  CLR_BIT(TIMER1->CCER, 1);
		  CLR_BIT(TIMER1->CCMR1, 8);
		  SET_BIT(TIMER1->CCMR1, 9);
		  SET_BIT(TIMER1->CCER, 5);
		  TIMER1->SMCR&=(~(0b111<<4));
		  TIMER1->SMCR|=(0b101<<4);
		  TIMER1->SMCR&=(~(0b111));
		  TIMER1->SMCR|=(0b100);
		  SET_BIT(TIMER1->CCER, 0);
		  SET_BIT(TIMER1->CCER, 4);
		  break;
	  case TIMER1_ICU_CHANNEL2:
		  break;
	  case TIMER1_ICU_CHANNEL3:
		  break;
	  case TIMER1_ICU_CHANNEL4:
		  break;
	}
}
*/
void TIMER1_ICU_EdgeDetect(ICU_CHANNEL ICU_channel_ID, ICU_EDGE edge);

void TIMER1_ICU_SetCallBack( void(*Copy_pfCallback)(void));
/*******************************************************************************
* Function Name:		TIMER1_u8Stop
********************************************************************************/
void TIMER1_Stop(void)
{
	TIMER1->CR1 = 0;
	TIMER1->ARR = 0;
	TIMER1->RCR = 0;
	TIMER1->PSC = 0;
	CLR_BIT(TIMER1->DIER,0); /* Disable the interrupt */
	SET_BIT(TIMER1->EGR,0);
}
/*******************************************************************************
*                       Interrupt Service Routines                            *
*******************************************************************************/
void TIM1_UP_IRQHandler(void)
{
	if(TIMER1_callback != NULL)
	{
		TIMER1_callback();
	}
	CLR_BIT(TIMER1->SR,0); /* Clear the update flag */
}
