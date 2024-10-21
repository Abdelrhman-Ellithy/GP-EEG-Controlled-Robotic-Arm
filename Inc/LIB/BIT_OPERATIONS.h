/*
 * BIT_OPERATIONS.h
 *
 * Created: 2023-08-05 10:37:02 AM
 *  Author: lenovo
 */ 


#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#define SET_REG(Reg)				(Reg|=0xFF)
#define MASK_REG(Reg,val)			(Reg&=val)
#define CLEAR_REG(Reg)				(Reg&=0x00)
#define TOGGLE_REG(Reg)				(Reg^=0xFF)
#define WRITE_REG(Reg,Val)			(Reg=Val)
#define GET_REG(Reg, val)			(val=(Reg & 0xFF ))
#define CLEAR_bits(Reg,bits)		(Reg&=~(bits))
#define Set_bits(Reg,bits)			(Reg|=bits)
#define CLEAR_High_nipple(Reg)		(Reg&=0x0f)
#define CLEAR_low_nipple(Reg)		(Reg&=0xf0)

#define SET_BIT(Reg,bit)			 (Reg|=(1<<bit) )
#define CLEAR_BIT(Reg,bit)			 (Reg&=~(1<<bit) ) 
#define TOGGLE_BIT(Reg,bit)			(Reg^=(1<<bit) )
#define GET_BIT(Reg,bit)			((Reg>>bit) &0x01 )

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define ret()  __asm__ __volatile__ ("ret" ::)
# define reti() __asm__ __volatile__ ("reti" ::)


#endif /* BIT_OPERATIONS_H_ */