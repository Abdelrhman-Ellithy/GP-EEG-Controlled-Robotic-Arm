/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    PORT.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SWC    : PORT
 *
 */ 
#include "LIB/Types.h"
#include "MCAL/PORT/PORT_config.h"
#include "MCAL/PORT/PORT_private.h"
#include "MCAL/PORT/PORT_interface.h"
#include "LIB/stm32f103c8t6.h"
void PORT_voidInit(void)
{

	/*Set pin directions */
	#if PORTA_EN==1
	GPIOA->CRL=PORTAL_DIRCTION;
	GPIOA->CRH=PORTAH_DIRCTION;
	GPIOA->BSRR=PORTA_INITIAL_VALUE;
	GPIOA->BRR=~(PORTA_INITIAL_VALUE);
	#endif

	#if PORTB_EN==1
	GPIOB->CRL=PORTBL_DIRCTION;
	GPIOB->CRH=PORTBH_DIRCTION;
	GPIOB->BSRR=PORTB_INITIAL_VALUE;
	GPIOB->BRR=~(PORTB_INITIAL_VALUE);
	#endif

	#if PORTC_EN==1
	GPIOC->CRH=PORTCH_DIRCTION;
	GPIOC->BSRR=PORTC_INITIAL_VALUE;
	GPIOC->BRR=~(PORTC_INITIAL_VALUE);
	#endif
}
