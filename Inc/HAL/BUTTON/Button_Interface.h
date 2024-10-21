/*
 * Button_Interface.h
 * Created: 2023-7-30 7:40:05 AM
 *  Author: Abdelrahman Ellithy
 *  Layer: HAL
 *  SW: Button
 */ 

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

typedef enum{
	Inputfloating=0,
	PullDown,
	PullUp,
}PullState;
typedef struct{
	u8 BtnPort;
	u8 BtnPin;
	PullState BtnPullState;
}Button;

void Button_read(Button * Btn, u8 *val);

#endif /* BUTTON_H_ */
