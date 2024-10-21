/*=================================================================================*/
/*  File        : PORT_CONFIG_H_                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW component: PORT
 */

 
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

#define PORTA_EN							1
#define PORTB_EN							1
#define PORTC_EN							0

/************* PINS Direction   *********************/

#define GPIO_INPUT_ANALOG					0000
#define GPIO_INPUT_FLOATING					0100
#define GPIO_INPUT_PULL_DOWN				1000
#define GPIO_INPUT_PULL_UP					1000 /* To know if it is pull up or down */

/*******************************************************************************
*                        			OUTPUT MODES 	  	                       *
*******************************************************************************/
#define GPIO_OUTPUT_GP_PP_10MHZ				0001
#define GPIO_OUTPUT_GP_OD_10MHZ				0101
#define GPIO_OUTPUT_AF_PP_10MHZ				1001
#define GPIO_OUTPUT_AF_OD_10MHZ				1101

#define GPIO_OUTPUT_GP_PP_2MHZ				0010
#define GPIO_OUTPUT_GP_OD_2MHZ				0110
#define GPIO_OUTPUT_AF_PP_2MHZ				1010
#define GPIO_OUTPUT_AF_OD_2MHZ				1110

#define GPIO_OUTPUT_GP_PP_50MHZ				0011
#define GPIO_OUTPUT_GP_OD_50MHZ				0111
#define GPIO_OUTPUT_AF_PP_50MHZ				1011
#define GPIO_OUTPUT_AF_OD_50MHZ				1111

/* 
	$ Options :-
	
		GPIO_INPUT_ANALOG
		GPIO_INPUT_FLOATING
		GPIO_INPUT_PULL_DOWN
		GPIO_INPUT_PULL_UP

		***********************

		***********************
		GPIO_OUTPUT_GP_PP_10MHZ
		GPIO_OUTPUT_GP_OD_10MHZ
		GPIO_OUTPUT_AF_PP_10MHZ
		GPIO_OUTPUT_AF_OD_10MHZ

		GPIO_OUTPUT_GP_PP_2MHZ
		GPIO_OUTPUT_GP_OD_2MHZ
		GPIO_OUTPUT_AF_PP_2MHZ
		GPIO_OUTPUT_AF_OD_2MHZ

		GPIO_OUTPUT_GP_PP_50MHZ
		GPIO_OUTPUT_GP_OD_50MHZ
		GPIO_OUTPUT_AF_PP_50MHZ
		GPIO_OUTPUT_AF_OD_50MHZ

*/
		   
#define PORTA_PIN0_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN1_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN2_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN3_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN4_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN5_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN6_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN7_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN8_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN9_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN10_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN11_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN12_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN13_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN14_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTA_PIN15_DIR				GPIO_OUTPUT_GP_PP_2MHZ

#define PORTB_PIN0_DIR				GPIO_INPUT_PULL_UP
#define PORTB_PIN1_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN2_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN3_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN4_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN5_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN6_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN7_DIR				GPIO_INPUT_FLOATING
#define PORTB_PIN8_DIR				GPIO_INPUT_PULL_UP
#define PORTB_PIN9_DIR				GPIO_INPUT_PULL_UP
#define PORTB_PIN10_DIR				GPIO_INPUT_PULL_UP
#define PORTB_PIN11_DIR				GPIO_INPUT_PULL_UP
#define PORTB_PIN12_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTB_PIN13_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTB_PIN14_DIR				GPIO_OUTPUT_GP_PP_2MHZ
#define PORTB_PIN15_DIR				GPIO_OUTPUT_GP_PP_2MHZ

#define PORTC_PIN13_DIR				GPIO_INPUT_PULL_UP
#define PORTC_PIN14_DIR				GPIO_INPUT_PULL_UP
#define PORTC_PIN15_DIR				GPIO_INPUT_PULL_UP


/********  do not play her	**************************
 * 		***********************************************/
/********  do not play her	**************************
 * 		***********************************************/
#define PORTC_PIN8_DIR				GPIO_INPUT_FLOATING
#define PORTC_PIN9_DIR				GPIO_INPUT_FLOATING
#define PORTC_PIN10_DIR				GPIO_INPUT_FLOATING

/********  do not play her	**************************
 * 		***********************************************/
/********  do not play her	**************************
 * 		***********************************************/
#define PORTC_PIN11_DIR				GPIO_INPUT_FLOATING
#define PORTC_PIN12_DIR				GPIO_INPUT_FLOATING

/********  do not play her	**************************
 * 		***********************************************/
/********  do not play her	**************************
 * 		***********************************************/

/******	set initial values for the pins	******************
 * *******************************************************
 * *******************************************************/


#define INPUT_FLOATING 0
#define OUTPUT_LOW     0
#define OUTPUT_HIGH    1

/*  $ Choose:-
			1- INPUT_FLOATING
			3- OUTPUT_LOW
			4- OUTPUT_HIGH
*/

#define PORTA_PIN0_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN1_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN2_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN3_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN4_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN5_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN6_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN7_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN8_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN9_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN10_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN11_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN12_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN13_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN14_INITIAL_VALUE	OUTPUT_HIGH
#define PORTA_PIN15_INITIAL_VALUE	OUTPUT_HIGH

#define PORTB_PIN0_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN1_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN2_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN3_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN4_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN5_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN6_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN7_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN8_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN9_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN10_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN11_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN12_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN13_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN14_INITIAL_VALUE	OUTPUT_HIGH
#define PORTB_PIN15_INITIAL_VALUE	OUTPUT_HIGH

#define PORTC_PIN13_INITIAL_VALUE	INPUT_FLOATING
#define PORTC_PIN14_INITIAL_VALUE	INPUT_FLOATING
#define PORTC_PIN15_INITIAL_VALUE	INPUT_FLOATING





#endif
