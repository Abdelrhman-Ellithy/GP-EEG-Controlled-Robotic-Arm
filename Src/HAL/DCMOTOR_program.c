/*
 * Dc_Motor.c
 *
 * Created: 2023-12-08 4:12:28 AM
 *  Author: Abdelrahman Ellithy
 */

 

#include "LIB/BIT_OPERATIONS.h"

#include "HAL/DC Motor/DCMOTOR_Interface.h"
void DCMOTOR_Control (DCMOTOR * DcMotor)
{
	switch (DcMotor->State)
	{
		case DCMOTOR_FW:
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,GPIO_HIGH);
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,GPIO_LOW);
			break;
		case DCMOTOR_BK:
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,GPIO_LOW);
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,GPIO_HIGH);
			break;
		case DCMOTOR_STOP :
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinA,GPIO_LOW);
			GPIO_WritePinValue(DcMotor->DcMotorPort,DcMotor->DcMotorPinB,GPIO_LOW);
			break;
	}
}
