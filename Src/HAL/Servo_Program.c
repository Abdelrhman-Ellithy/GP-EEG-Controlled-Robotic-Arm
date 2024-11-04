#include "HAL/Servo/Servo_Interface.h"
#include "HAL/Servo/Servo_conifg.h"
#include "HAL/Servo/Servo_private.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/TIMER1/TIMER1_interface.h"


void SERVO_Init(ServoID_t  servo){
	TIMER1_InitPwmChannel(servo);
	TIMER1_SetFREQ(servo,SERVO_FREQUENCY);
	TIMER1_SetARRValue(39999);
	Servo_setAngle(servo,0);
}

void Servo_setAngle(ServoID_t servo, u8 angle){
	u32 loc_angle=angle;
	u16 loc_Value= (u16)((u32)((u32)((loc_angle*100U) )/9U)+1999 );
	TIMER1_Set_CRR_Value(servo,loc_Value);
}
