/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This Program file includes GPIO Program for STM32f103C8T6        */
/* Abdelrahman Ellithy
 * 															   */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_Config.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/GPIO/GPIO_private.h"
#include "LIB/stm32f103c8t6.h"

static GPIO_RegDef_t * GPIO_Astr[] = {GPIOA,GPIOB,GPIOC};


/*  $ Choose:-
			1- INPUT_FLOATING
			3- OUTPUT_LOW
			4- OUTPUT_HIGH
*/

void GPIO_HIGH_2Nibble_Write(u8 Copy_PortId, u8 Copy_PortValue){
	GPIO_Astr[Copy_PortId]->ODR &=(0x00FF);
	GPIO_Astr[Copy_PortId]->ODR|=(Copy_PortValue<<8);

}
void GPIO_LOW_2Nibble_Write(u8 Copy_PortId, u8 Copy_PortValue){
	GPIO_Astr[Copy_PortId]->ODR &=(0xFF00);
	GPIO_Astr[Copy_PortId]->ODR|=Copy_PortValue;
}
void GPIO_Nibble_Write(u8 Copy_PortId, Nibble_ID Copy_NiibleId,  u8 Copy_PortValue){
	GPIO_Astr[Copy_PortId]->ODR &=~(0xF<<Copy_NiibleId);
	GPIO_Astr[Copy_PortId]->ODR|=(Copy_PortValue<<Copy_NiibleId);
}

#if NeedPortHere==1
void GPIO_PORT_voidInit(void)
{	u8 port,pin;
	for(port=GPIO_PORTA; port<=GPIO_PORTC; port++){
		for(pin=GPIO_PIN0; pin<=GPIO_PIN15 ; pin++){
			switch(port){
			#if PORTA_EN==1
			case GPIO_PORTA:
				GPIO_SetPinMode(port , pin, PORTA_DIR[pin]);
				break;
			#endif

			#if PORTB_EN==1
			case GPIO_PORTB:
				GPIO_SetPinMode(port , pin, PORTB_DIR[pin]);
				break;

			#endif
			#if PORTC_EN==1

			case GPIO_PORTC:
				if(pin<=GPIO_PIN13){
					pin=GPIO_PIN13;
				}
				GPIO_SetPinMode(port , pin, PORTC_DIR[pin]);
				break;
			#endif
			  }
			}
		}

	for(port=GPIO_PORTA; port<=GPIO_PORTC; port++){
		for(pin=GPIO_PIN0; pin<=GPIO_PIN15 ; pin++){
			switch(port){
			#if PORTA_EN==1
			case GPIO_PORTA:
				GPIO_WritePinValue(port , pin, PORTA_init_val[pin]);
				break;
			#endif

			#if PORTB_EN==1
			case GPIO_PORTB:
				GPIO_WritePinValue(port , pin, PORTB_init_val[pin]);
				break;

			#endif
			#if PORTC_EN==1

			case GPIO_PORTC:
				if(pin<=GPIO_PIN13){
					pin=GPIO_PIN13;
				}
				GPIO_WritePinValue(port , pin, PORTC_init_val[pin]);
				break;
			#endif
			  }
			}
		}

}
#endif

void GPIO_SetPinMode (u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode)
{
	if(Copy_PortId <= GPIO_PORTC)
	{
		u8 Local_PullUpDown_Flag = GET_BIT(Copy_PinMode,4); /* Equal one in case of pull up only */
		CLR_BIT(Copy_PinMode,4); /*Get the Mode back to its value if it was input pull up */

		if(Copy_PinId <= GPIO_PIN7)
		{
			GPIO_Astr[Copy_PortId]->CRL &= (~((0b1111) << (Copy_PinId * 4)));
			GPIO_Astr[Copy_PortId]->CRL |= (Copy_PinMode << (Copy_PinId * 4));

			if((Copy_PinMode == GPIO_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 0))
			{
				/* Then the mode was input pull down */
				/* Turn off the internal pull up resistor */
				CLR_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
			else if((Copy_PinMode == GPIO_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 1))
			{
				/* Then the mode was input pull up */
				/* Turn on the internal pull up resistor */
				SET_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
		}
		else if(Copy_PinId <= GPIO_PIN15)
		{
			Copy_PinId -= 8;
			GPIO_Astr[Copy_PortId]->CRH &= (~((0b1111) << (Copy_PinId * 4)));
			GPIO_Astr[Copy_PortId]->CRH |= (Copy_PinMode << (Copy_PinId * 4));

			if((Copy_PinMode == GPIO_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 0))
			{
				/* Then the mode was input pull down */
				/* Turn off the internal pull up resistor */
				CLR_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
			else if((Copy_PinMode ==GPIO_INPUT_PULL_DOWN) && (Local_PullUpDown_Flag == 1))
			{
				/* Then the mode was input pull up */
				/* Turn on the internal pull up resistor */
				SET_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
			}
		}

	}

}

void GPIO_WritePinValue	(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_u8PinValue)
{

	if(Copy_PortId <= GPIO_PORTC && Copy_PinId <= GPIO_PIN15)
	{
		switch(Copy_u8PinValue)
		{
		case GPIO_HIGH:
			GPIO_Astr[Copy_PortId]->BSRR = (1<<Copy_PinId);
			break;
		case GPIO_LOW:
			GPIO_Astr[Copy_PortId]->BRR = (1<<Copy_PinId);
			break;
		}
	}
}

void GPIO_GetPinValue(u8 Copy_PortId, u8 Copy_PinId , u8 * Copy_Pu8RetunredPinValue)
{


	if(Copy_PortId <= GPIO_PORTC && Copy_PinId <= GPIO_PIN15)
	{
		*Copy_Pu8RetunredPinValue = GET_BIT(GPIO_Astr[Copy_PortId]->IDR,Copy_PinId);
	}
}

void GPIO_TogPinValue(u8 Copy_PortId, u8 Copy_PinId)
{

	if(Copy_PortId <= GPIO_PORTC && Copy_PinId <= GPIO_PIN15)
	{
		TOG_BIT(GPIO_Astr[Copy_PortId]->ODR,Copy_PinId);
	}

}


void GPIO_LockPort(u8 Copy_PortId, u8 Copy_PortValue)
{
	if(Copy_PortId <= GPIO_PORTC && Copy_PortValue <= 0xFF)
	{
		GPIO_Astr[Copy_PortId]->LCKR = Copy_PortValue;

		/* use the sequence to apply the lock */
		SET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 1 */
		CLR_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 0 */
		SET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16); /* Write 1 */
		while(GET_BIT(GPIO_Astr[Copy_PortId]->LCKR,16) );

	}
}
