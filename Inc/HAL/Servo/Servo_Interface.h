/*
 * Servo_interface.h
 *
 * Created: 2023-12-03 1:20:34 PM
 *  Author: Abdelrahman Ellithy
 */ 

#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"

typedef enum{
	SERVO_1=TIMER1_PWM_CHANNEL1,
	SERVO_2=TIMER1_PWM_CHANNEL2,
	SERVO_3=TIMER1_PWM_CHANNEL3,
	SERVO_4=TIMER1_PWM_CHANNEL4
}ServoID_t;

void SERVO_Init(ServoID_t servo);
void Servo_setAngle(ServoID_t servo, u8 angle);

#endif /* SERVO_INTERFACE_H */
