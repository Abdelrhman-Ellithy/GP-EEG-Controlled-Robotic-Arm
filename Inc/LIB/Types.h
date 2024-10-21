/*
 * Types.h
 *
 * Created: 2023-07-20 2:57:46 PM
 *  Author: Abdelrahman Ellithy
 *  Layer: LIB
 */ 


#ifndef TYPES_H_
#define TYPES_H_

#define OK           	0
#define NOK          	1
#define NULL_POINTER 	2
#define BUSY_STATE	 	3
#define TIMEOUT_STATE   4
#define NULL 			((void *)0)

typedef unsigned char	     u8 ;
typedef unsigned short		 u16;
typedef unsigned long		 u32;
typedef unsigned long long	 u64;

typedef signed char          s8 ;
typedef signed short		 s16 ;
typedef signed long			 s32 ;

typedef float				f32 ;
typedef double				f64 ;

/*
typedef union{
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	}BitAccess;
	u8 ByteAccess;
}Register;
*/
#define TRUE 1
#define FALSE 0
#define NULLPTR   ((void*)0)
#endif /* TYPES_H_ */
