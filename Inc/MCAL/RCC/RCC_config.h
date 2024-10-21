/*=================================================================================*/
/*  File        : RCC_CONFIG_H                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: RCC
 */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*******************************************************************************
*                      Configure the system clock
*                      1- RCC_u8_HSI
*                      2- RCC_u8_HSE
*                      3- RCC_u8_PLL
****************************************************************************/
#define RCC_CLK_SYS			RCC_HSE

/*******************************************************************************
*                      Configure the PLL clock source
*                       1- RCC_u8_PLL_HSI_DIVIDED_BY_2
*                       2- RCC_u8_PLL_HSE
*                       3- RCC_u8_PLL_HSE_DIVIDED_BY_2
*
*                      Configure the HSE clock source
*                       1-  RCC_u8_PLL_MULTIPLY_BY_2
*                       2-  RCC_u8_PLL_MULTIPLY_BY_3
*                       3-  RCC_u8_PLL_MULTIPLY_BY_4
*						4-  RCC_u8_PLL_MULTIPLY_BY_5
*						5-  RCC_u8_PLL_MULTIPLY_BY_6
*						6-  RCC_u8_PLL_MULTIPLY_BY_7
*						7-  RCC_u8_PLL_MULTIPLY_BY_8
*						8-  RCC_u8_PLL_MULTIPLY_BY_9
*						9-  RCC_u8_PLL_MULTIPLY_BY_10
*						10- RCC_u8_PLL_MULTIPLY_BY_11
*						11- RCC_u8_PLL_MULTIPLY_BY_12
*						12- RCC_u8_PLL_MULTIPLY_BY_13
*						13- RCC_u8_PLL_MULTIPLY_BY_14
*						14- RCC_u8_PLL_MULTIPLY_BY_15
*						15- RCC_u8_PLL_MULTIPLY_BY_16
*******************************************************************************/
#if (RCC_CLK_SYS == RCC_PLL)
	#define RCC_PLL_SOURCE			RCC_PLL_HSI_DIVIDED_BY_2
	#define RCC_PLL_MULTIPLIER		RCC_PLL_MULTIPLY_BY_2
#endif

/*******************************************************************************
*                      Configure the HSE clock source
*                       1- RCC_u8_HSE_NOT_BYPASS
*                       2- RCC_u8_HSE_BYPASS
*******************************************************************************/
#if (RCC_CLK_SYS == RCC_HSE)

	#define RCC_HSE_TYPE			RCC_HSE_NOT_BYPASS

#endif

/*******************************************************************************
*                      The Trim Value of HSI
*                      Any value between 0~31
*                      Default = 16
*******************************************************************************/
#define RCC_HSI_TRIM				16

/****************************************************************************
*                   Configure the prescaler for the ADC
*                   1- RCC_u8_ADC_DIVIDED_BY_2
*					2- RCC_u8_ADC_DIVIDED_BY_4
*					3- RCC_u8_ADC_DIVIDED_BY_6
*					4- RCC_u8_ADC_DIVIDED_BY_8
****************************************************************************/
#define RCC_ADC_PRESCALER				RCC_ADC_DIVIDED_BY_2

/*******************************************************************************
*                      Configure the prescaler for the APBx bus
*                       1- RCC_u8_APBx_DIVIDED_BY_1
*						2- RCC_u8_APBx_DIVIDED_BY_2
*						3- RCC_u8_APBx_DIVIDED_BY_4
*						4- RCC_u8_APBx_DIVIDED_BY_8
*						5- RCC_u8_APBx_DIVIDED_BY_16
*
*                      Configure the prescaler for the AHB bus
*                       1- RCC_u8_AHB_DIVIDED_BY_1
*						2- RCC_u8_AHB_DIVIDED_BY_2
*						3- RCC_u8_AHB_DIVIDED_BY_4
*						4- RCC_u8_AHB_DIVIDED_BY_8
*						5- RCC_u8_AHB_DIVIDED_BY_16
*						6- RCC_u8_AHB_DIVIDED_BY_64
*						7- RCC_u8_AHB_DIVIDED_BY_128
*						8- RCC_u8_AHB_DIVIDED_BY_256
*						8- RCC_u8_AHB_DIVIDED_BY_512
*******************************************************************************/
#define RCC_APB1_PRESCALER				RCC_APBx_DIVIDED_BY_1
#define RCC_APB2_PRESCALER				RCC_APBx_DIVIDED_BY_1
#define RCC_AHB_PRESCALER				RCC_AHB_DIVIDED_BY_1

#endif
