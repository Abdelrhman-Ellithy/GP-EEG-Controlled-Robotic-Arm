/*
 *  Keypad.h
 *  Author: Abdelrahman Ellithy
 *  Layer: HAL
 *  SW: Keypad
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "MCAL/GPIO/GPIO_interface.h"


#define keypad_port 	 GPIO_PORTB
#define keypad_port_bits 0xf0



#define row1 GPIO_PIN3
#define row2 GPIO_PIN4
#define row3 GPIO_PIN5
#define row4 GPIO_PIN6

#define Col1 GPIO_PIN7
#define Col2 GPIO_PIN8
#define Col3 GPIO_PIN9
#define Col4 GPIO_PIN10



u8 keypad_Buttons[4][4]={
	/*c1  c2  c3  c4*/
	{'7','8','9','/'}, /* row1 */
	{'4','5','6','*'}, /* row2 */
	{'1','2','3','-'}, /* row3 */
	{'o','0','=','+'}  /* row4 */
};

#endif /* KEYPAD_H_ */
