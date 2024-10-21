/*=================================================================================*/
/*  File        : SysTK_INTERFACE_H                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: SYSTICK
 */

#ifndef SysTK_INTERFACE_H
#define SysTK_INTERFACE_H

/*******************************************************************************
*                        		Clock Source	                               *
*******************************************************************************/
typedef enum{
	 SysTK_AHB=0
	,SysTK_AHB_8
}SysTK_clk;

void SysTKInit(SysTK_clk Copy_ClockSource);


void SysTKSetmSBusyWait(u32 Copy_u32TimeInTicks);


void SysTKSetIntervalSingle(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));


void SysTKSetIntervalPeriodic(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));


void SysTKStop(void);


void SysTKGetElapsedTime      (u32 * Copy_pu32ElapsedTime);


void SysTKGetRemainingTime    (u32 * Copy_pu32RemainingTime);

#endif
