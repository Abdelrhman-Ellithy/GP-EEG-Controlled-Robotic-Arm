/*=================================================================================*/
/*  File        : GPIO_INTERFACE_H                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: GPIO
 *  																				*/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "LIB/STD_TYPES.h"
/*******************************************************************************
*                        			Nibbles 	  	                               *
*******************************************************************************/
typedef enum{
	 Frist_nibble=0
	,Second_nibble=4
	,Third_nibble=8
	,Fourth_nibble=12
}Nibble_ID;
/*******************************************************************************
*                        			PORTs 	  	                               *
*******************************************************************************/
#define GPIO_PORTA						0
#define GPIO_PORTB						1
#define GPIO_PORTC						2
#define NeedPortHere				 	1
/*******************************************************************************
*                        			PINs 	  	                               **/
#define GPIO_PIN0						0
#define GPIO_PIN1						1
#define GPIO_PIN2						2
#define GPIO_PIN3						3
#define GPIO_PIN4						4
#define GPIO_PIN5						5
#define GPIO_PIN6						6
#define GPIO_PIN7						7
#define GPIO_PIN8						8
#define GPIO_PIN9						9
#define GPIO_PIN10						10
#define GPIO_PIN11						11
#define GPIO_PIN12						12
#define GPIO_PIN13						13
#define GPIO_PIN14						14
#define GPIO_PIN15						15

/*******************************************************************************
*                        			INPUT MODES 	  	                       *
*******************************************************************************/
#define GPIO_INPUT_ANALOG					0b0000
#define GPIO_INPUT_FLOATING					0b0100
#define GPIO_INPUT_PULL_DOWN				0b1000
#define GPIO_INPUT_PULL_UP					0b11000

/*******************************************************************************
*                        			OUTPUT MODES 	  	                       *
*******************************************************************************/
#define GPIO_OUTPUT_GP_PP_10MHZ				0b0001
#define GPIO_OUTPUT_GP_OD_10MHZ				0b0101
#define GPIO_OUTPUT_AF_PP_10MHZ				0b1001
#define GPIO_OUTPUT_AF_OD_10MHZ				0b1101

#define GPIO_OUTPUT_GP_PP_2MHZ				0b0010
#define GPIO_OUTPUT_GP_OD_2MHZ				0b0110
#define GPIO_OUTPUT_AF_PP_2MHZ				0b1010
#define GPIO_OUTPUT_AF_OD_2MHZ				0b1110

#define GPIO_OUTPUT_GP_PP_50MHZ				0b0011
#define GPIO_OUTPUT_GP_OD_50MHZ				0b0111
#define GPIO_OUTPUT_AF_PP_50MHZ				0b1011
#define GPIO_OUTPUT_AF_OD_50MHZ				0b1111

/*******************************************************************************
*                        			OUTPUT VALUES 	  	                       *
*******************************************************************************/
#define GPIO_HIGH                       1
#define GPIO_LOW                        0
#define INPUT_FLOATING					0

#if NeedPortHere==1
void GPIO_PORT_voidInit(void);
#endif
void GPIO_HIGH_2Nibble_Write(u8 Copy_PortId, u8 Copy_PortValue);

void GPIO_LOW_2Nibble_Write(u8 Copy_PortId, u8 Copy_PortValue);

void GPIO_Nibble_Write(u8 Copy_PortId, Nibble_ID Copy_NiibleId,  u8 Copy_PortValue);

void GPIO_SetPinMode	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode);

void GPIO_WritePinValue	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_u8PinValue);

void GPIO_GetPinValue	(u8 Copy_PortId, u8 Copy_PinId , u8 * Copy_Pu8RetunredPinValue);

void GPIO_TogPinValue	(u8 Copy_PortId, u8 Copy_PinId);

void GPIO_LockPort		(u8 Copy_PortId, u8 Copy_PortValue);

#endif
