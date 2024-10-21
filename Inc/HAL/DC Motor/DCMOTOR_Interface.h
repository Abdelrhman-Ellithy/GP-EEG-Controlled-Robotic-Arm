/*
 * DC_Motor_Interface.h
 *  Author: Abdelrahman Ellithy
 *  Layer: HAL
 *  SW: DC_Motor
 */ 

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "MCAL/GPIO/GPIO_interface.h"
typedef enum{
	 DCMOTOR_FW	=0,
	 DCMOTOR_BK	,
	 DCMOTOR_STOP
}MotorStatus;
	
typedef struct 
{
	u8 DcMotorPort ;
	u8 DcMotorPinA ;
	u8 DcMotorPinB ;
	MotorStatus State;
} DCMOTOR ;

void DCMOTOR_Control (DCMOTOR * DcMotor) ;

#endif
