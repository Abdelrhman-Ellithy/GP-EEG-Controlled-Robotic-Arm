/*=================================================================================*/
/*  File        : RCC_Program.c                                               */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: RCC
 */

#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/RCC/RCC_private.h"
#include "MCAL/RCC/RCC_config.h"
#include "LIB/stm32f103c8t6.h"


void RCC_InitSysClk(void){

	RCC->CR = (RCC->CR &~ (0b11111<<3)) | (RCC_HSI_TRIM<<3); /* Setting the TRIM value for HSI */
	#if (RCC_CLK_SYS == RCC_HSI)

		SET_BIT(RCC->CR,0); /* write one bit no0 HSION to enable it*/
		CLR_BIT(RCC->CFGR,0); /* Select HSI as clock source from SW registers */
		CLR_BIT(RCC->CFGR,1);

	#elif (RCC_CLK_SYS == RCC_HSE)
		#if (_HSE_TYPE == RCC_HSE_BYPASS)
			SET_BIT(RCC->CR,18);
		#elif (RCC_HSE_TYPE == RCC_HSE_NOT_BYPASS)
			CLR_BIT(RCC->CR,18);
		#else
			#error"Wrong System Clock Choice"
		#endif
		SET_BIT(RCC->CR,16); /* write one bit no16 HSEON */
		SET_BIT(RCC->CFGR,0); /* select HSE as system clock in SW registers */
		CLR_BIT(RCC->CFGR,1);

	#elif (RCC_CLK_SYS == RCC_PLL)
		/* Starting of First Nested If */
		#if ((RCC_PLL_MULTIPLIER >= RCC_PLL_MULTIPLY_BY_2) && (RCC_PLL_MULTIPLIER <= RCC_PLL_MULTIPLY_BY_16))
			RCC->CFGR = (RCC->CFGR &~ (0b1111 << 18)) | (RCC_PLL_MULTIPLIER << 18) ;
		#else
			#warning "Wrong Multiplication Factor"
		#endif
		/* End of First Nested If */

		/* Starting of First Nested If */
		#if (RCC_PLL_SOURCE == RCC_PLL_HSI_DIVIDED_BY_2)
			CLR_BIT(RCC->CFGR,16);
		#elif (RCC_u8_PLL_SOURCE == RCC_PLL_HSE)
			SET_BIT(RCC->CR,16); /* Enable the HSE first */
			SET_BIT(RCC->CFGR,16);
			CLR_BIT(RCC->CFGR,17);
		#elif (RCC_PLL_SOURCE == RCC_PLL_HSE_DIVIDED_BY_2)
			SET_BIT(RCC->CR,16); /* Enable the HSE first */
			SET_BIT(RCC->CFGR,16);
			SET_BIT(RCC->CFGR,17);
		#else
			#error"Wrong System Clock Choice"
		#endif
		/* End of First Nested If */

		SET_BIT(RCC->CR,24); /* write one bit no24 PLLON */
		/* wait until PLL RDY flag = 1 */
		SET_BIT(RCC->CFGR,1); /* select PLL as system clock in SW registers */
		CLR_BIT(RCC->CFGR,0);

	#else
		#error"Wrong System Clock Choice"
	#endif

	/* Setting the Prescaler */
	RCC->CFGR = (RCC->CFGR &~ (0b11<<14))  | (RCC_ADC_PRESCALER<<14);  /* ADC */
	RCC->CFGR = (RCC->CFGR &~ (0b111<<11)) | (RCC_APB2_PRESCALER<<11); /* APB2 */
	RCC->CFGR = (RCC->CFGR &~ (0b111<<8))  | (RCC_APB1_PRESCALER<<8);  /* APB1 */
	RCC->CFGR = (RCC->CFGR &~ (0b1111<<4)) | (RCC_AHB_PRESCALER<<4);   /* AHB */
	
}

void RCC_PeripheralClk(RCC_PER_ID Copy_PeripheralId ,PER_STATE Copy_State){

	if(Copy_PeripheralId < 32) /* from 0 to 31 AHB BUS */
	{
		switch(Copy_State)
		{
		case RCC_Enable:
			SET_BIT(RCC->AHBENR,Copy_PeripheralId);
			break;
		case RCC_Disable:
			CLR_BIT(RCC->AHBENR,Copy_PeripheralId);
			break;
		}
	}
	else if(Copy_PeripheralId < 64) /* from 32 to 63 APB2 BUS */
	{
		Copy_PeripheralId -= 32;
		switch(Copy_State)
		{
		case RCC_Enable:
			SET_BIT(RCC->APB2ENR,Copy_PeripheralId);
			break;
		case RCC_Disable:
			CLR_BIT(RCC->APB2ENR,Copy_PeripheralId);
			break;
		}
	}
	else if(Copy_PeripheralId < 96) /* from 64 to 95 APB1 BUS */
	{
		Copy_PeripheralId -= 64;
		switch(Copy_State)
		{
		case RCC_Enable:
			SET_BIT(RCC->APB1ENR,Copy_PeripheralId);
			break;
		case RCC_Disable:
			CLR_BIT(RCC->APB1ENR,Copy_PeripheralId);
			break;
		}
	}

}
