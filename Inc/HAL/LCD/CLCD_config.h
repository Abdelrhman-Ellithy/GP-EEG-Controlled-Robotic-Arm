/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    CLCD_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *  Author : Abdelrahman Ellithy
 *	LAYER: HAL
 *	SW copmonent : LCD
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#include "MCAL/GPIO/GPIO_interface.h"
/***************************************************************************************/
/* LCD Mode */

	/* Choose 8 for 8_bit connection, 4 for 4_bit connection */

/* $ Options :-

	1- 4
	2- 8
	
 */
#define CLCD_MODE  4
#define CLCD_Type  CLCd_2_16
/***************************************************************************************/


/* D0 ------> D7 */
/*

  Options:-
 	 1-GPIO_PORTA
 	 2-GPIO_PORTB
 	 3-GPIO_PORTC


 */
/***************************************************************************************/


#define CLCD_DATA_PORT      GPIO_PORTB
/* RS,RW,EN */
#define CLCD_CONTROL_PORT   GPIO_PORTB


#if CLCD_MODE==8

#define  lOWER_2NIBBLE		0
#define  HIGHER_2NIBBLE		1

#endif

#if CLCD_MODE==4

#define  Frist_NIBBLE		Frist_nibble
#define  Second_NIBBLE		Second_nibble
#define  Third__NIBBLE		Third_nibble
#define  Fourth_NIBBLE		Fourth_nibble

#endif

#define CLCD_DATA_PORT_NIBBLE Fourth_nibble

/***************************************************************************************/


/*

 Options:-
 	 1-GPIO_PIN0
 	 2-GPIO_PIN1
 	 3-GPIO_PIN2
 	 4-GPIO_PIN3
 	 5-GPIO_PIN4
 	 6-GPIO_PIN5
 	 7-GPIO_PIN6
 	 8-GPIO_PIN7

 */
#define CLCD_RS             GPIO_PIN0
#define CLCD_EN             GPIO_PIN1

/*Conected to GND */#define CLCD_RW             GPIO_PIN

#define Cursor_Mode lcd_DisplayOn_CursorOff
/***************************************************************************************/


#endif /* CLCD_CONFIG_H_ */
