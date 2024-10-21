/******************************************************************************
*  File name:		stm32f103xx.h
 * 	Created: 2024-01-24 2:57:46 PM
 *  Author: Abdelrahman Ellithy
 *  Layer: LIB
 */
#ifndef STM32F103xx_H
#define STM32F103xx_H

#include "STD_TYPES.h"
/*******************************************************************************
*                      				RCC                     		           *
*******************************************************************************/
#define RCC_u32_BASE_ADDRESS						0x40021000
typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_RegDef_t;

#define RCC						((RCC_RegDef_t *)RCC_u32_BASE_ADDRESS)



/*******************************************************************************
*                      				GPIO                     		           *
*******************************************************************************/
#define GPIOA_u32_BASE_ADDRESS						0x40010800U
#define GPIOB_u32_BASE_ADDRESS						0x40010C00U
#define GPIOC_u32_BASE_ADDRESS						0x40011000U

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA					((GPIO_RegDef_t *)GPIOA_u32_BASE_ADDRESS)
#define GPIOB					((GPIO_RegDef_t *)GPIOB_u32_BASE_ADDRESS)
#define GPIOC					((GPIO_RegDef_t *)GPIOC_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				AFIO                     		           *
*******************************************************************************/
#define AFIO_u32_BASE_ADDRESS						0x40010000U

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 RESERVED1;
	volatile u32 MAPR2;
}AFIO_RegDef_t;

#define AFIO					((AFIO_RegDef_t*)AFIO_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				EXTI                   		           *
*******************************************************************************/
#define EXTI_u32_BASE_ADDRESS						0x40010400U

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_RegDef_t;

#define EXTI						((EXTI_RegDef_t*)EXTI_u32_BASE_ADDRESS)


/*******************************************************************************
*                      				NVIC                    		           *
*******************************************************************************/

#define NVIC_BASE_ADDRESS						0xE000E100U

#define NVIC_ISER0								*((volatile u32*) (NVIC_BASE_ADDRESS+0x000) )
#define NVIC_ISER1	                            *((volatile u32*) (NVIC_BASE_ADDRESS+0x004) )
#define NVIC_ISER2                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x008) )
#define NVIC_ICER0                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x080) )
#define NVIC_ICER1                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x084) )
#define NVIC_ICER2                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x088) )
#define NVIC_ISPR0                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x100) )
#define NVIC_ISPR1                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x104) )
#define NVIC_ISPR2                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x108) )
#define NVIC_ICPR0                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x180) )
#define NVIC_ICPR1                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x184) )
#define NVIC_ICPR2                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x188) )
#define NVIC_IABR0                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x200) )
#define NVIC_IABR1                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x204) )
#define NVIC_IABR2                              *((volatile u32*) (NVIC_BASE_ADDRESS+0x208) )
#define NVIC_IPR_ptr           /*Pointer to u8*/  ((volatile u8*) (NVIC_BASE_ADDRESS+0x300) )
//#define NVIC_IPR20                             (* (volatile (u32*) NVIC_BASE_ADDRESS+0x320 ) )
#define NVIC_STIR                               *((volatile u32*) (NVIC_BASE_ADDRESS+0xE00) )
#define SCB_AIRCR								*((volatile u32*)				0xE000ED0CU )

/*			defined in NVIC_private.h
u16 NVIC_IPR_offsets[]={
		 0x0040
		,0x0044
		,0x0048
		,0x004C
		,0x0050
		,0x0054
		,0x0058
		,0x005C
		,0x0060
		,0x0064
		,0x0068
		,0x006C
		,0x0070
		,0x0074
		,0x0078
		,0x007C
		,0x0080
		,0x0084
		,0x0088
		,0x008C
		,0x0090
		,0x0094
		,0x0098
		,0x009C
		,0x00A0
		,0x00A4
		,0x00A8
		,0x00AC
		,0x00B0
		,0x00B4
		,0x00B8
		,0x00BC
		,0x00C0
		,0x00C4
		,0x00C8
		,0x00CC
		,0x00D0
		,0x00D4
		,0x00D8
		,0x00DC
		,0x00E0
		,0x00E4
		,0x00E8
		,0x00EC
		,0x00F0
		,0x00F4
		,0x00F8
		,0x00FC
		,0x0100
		,0x0104
		,0x0108
		,0x010C
		,0x0110
		,0x0114
		,0x0118
		,0x011C
		,0x0120
		,0x0124
		,0x0128
		,0x012C
};
*/

/*******************************************************************************
*                      				SysTicK	                    		           *
*******************************************************************************/

#define SysTK_BASE_ADDRESS						0xE000E010U

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SysTK_RegDef_t;

#define SysTK						((SysTK_RegDef_t *)SysTK_BASE_ADDRESS)

/*******************************************************************************
*                      				DMA	                    		           *
*******************************************************************************/
#define DMA_BASE_ADDRES				 0x40020000
/* struct for every channel */
typedef struct{

	volatile u32 CCR       ;//0x000
	volatile u32 CNDTR     ;//0x004
	volatile u32 CPAR      ;//0x008
	volatile u32 CMAR      ;//0x00C
	volatile u32 RESERVED  ;//0x010

}DMACHANNEL;

typedef struct{

	volatile u32 ISR  ;//0x000
	volatile u32 IFCR ;//0x004
	DMACHANNEL CHANNEL[7];//0x008

}DMA;

#define DMA	((volatile DMA *)DMA_BASE_ADDRES)

/*******************************************************************************
*                      			UART	                    		          *
*******************************************************************************/

#define UART1_BASE_ADDRESS						0x40013800U
#define UART2_BASE_ADDRESS						0x40004400U
#define UART3_BASE_ADDRESS						0x40004800U

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_RegDef_t;

#define UART1						((UART_RegDef_t*)UART1_BASE_ADDRESS)
#define UART2						((UART_RegDef_t*)UART2_BASE_ADDRESS)
#define UART3						((UART_RegDef_t*)UART3_BASE_ADDRESS)

/*******************************************************************************
*                      			TIMER1	                    		          *
*******************************************************************************/

#define TIMER1_u32_BASE_ADDRESS						0x40012C00U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR[4];
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}TIMER1_RegDef_t;

#define TIMER1				((TIMER1_RegDef_t *)TIMER1_u32_BASE_ADDRESS)

/*******************************************************************************
*                      				GPT	                      		           *
*******************************************************************************/

#define TIMER2_u32_BASE_ADDRESS						0x40000000U
#define TIMER3_u32_BASE_ADDRESS						0x40000400U
#define TIMER4_u32_BASE_ADDRESS						0x40000800U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 :32;
	volatile u32 CCR[4];
	volatile u32 :32;
	volatile u32 DCR;
	volatile u32 DMAR;
}GPT_RegDef_t;

#define TIMER2				((GPT_RegDef_t *)TIMER2_u32_BASE_ADDRESS)
#define TIMER3				((GPT_RegDef_t *)TIMER3_u32_BASE_ADDRESS)
#define TIMER4				((GPT_RegDef_t *)TIMER4_u32_BASE_ADDRESS)

/*******************************************************************************
*                      			ADC	1                    		          *
*******************************************************************************/


/* Register Definitions For ADC1 */  /* P:51,252 (Reg Des) */

#define ADC1_BASE_ADDRESS											0x40012400

#define ADC1_SR                *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x00) )
#define ADC1_CR1               *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x04) )
#define ADC1_CR2               *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x08) )
#define ADC1_SMPR1             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x0C) )
#define ADC1_SMPR2             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x10) )
#define ADC1_JOFR1             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x14) )
#define ADC1_JOFR2             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x18) )
#define ADC1_JOFR3             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x1C) )
#define ADC1_JOFR4             *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x20) )
#define ADC1_HTR               *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x24) )
#define ADC1_LTR               *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x28) )
#define ADC1_SQR1              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x2C) )
#define ADC1_SQR2              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x30) )
#define ADC1_SQR3              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x34) )
#define ADC1_JSQR              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x38) )
#define ADC1_JDR1              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x3C) )
#define ADC1_JDR2              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x40) )
#define ADC1_JDR3              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x44) )
#define ADC1_JDR4              *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x48) )
#define ADC1_DR                *( (volatile u32*) (ADC1_BASE_ADDRESS + 0x4C) )

/*******************************************************************************
*                      			SPI                   		          *
*******************************************************************************/

#define SPI1_BASE_ADDRESS						0x40013000U
#define SPI2_BASE_ADDRESS						0x40003800U

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_RegDef_t;

#define SPI1						((SPI_RegDef_t*)SPI1_BASE_ADDRESS)
#define SPI2						((SPI_RegDef_t*)SPI2_BASE_ADDRESS)

/*******************************************************************************
*                      			FPEC	                    		          *
*******************************************************************************/

#define FPEC_BASE_ADDRESS						0x40022000U

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_RegDef_t;

#define FPEC 				((FPEC_RegDef_t*)FPEC_BASE_ADDRESS)

#endif
