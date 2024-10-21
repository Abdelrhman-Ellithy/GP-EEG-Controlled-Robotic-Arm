/*=================================================================================*/
/*  File        : NVIC_CONFIG_H.                                                 */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        *
 *  Author : Abdekrahman Ellithy
 *  Layer  : MCAL
 *  SW: NVIC
 */

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define NVIC_16GROUPS_0SUB	0x5FA00300
#define NVIC_8GROUPS_2SUBS	0x5FA00400
#define NVIC_4GROUPS_4SUBS	0x5FA00500
#define NVIC_2GROUPS_8SUBS	0x5FA00600
#define NVIC_0GROUP_16SUBS	0x5FA00700

#define NVIC_GROUP_SUBSelected	NVIC_4GROUPS_4SUBS
#endif
