/*=================================================================================*/
/*  File        : FLASHER_INTERFACE_H                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: Flasher
 *  																				*/
#ifndef FLASHER_INTERFACE_H
#define FLASHER_INTERFACE_H


void Flash_Init(void);

// Function to read data from flash memory
void Flash_Read(u32 address, u8* buffer, u32 length);

// Function to write data to flash memory
u8 Flash_Write(u32 address, u8* data, u32 length);

void Flash_EraseAppArea(void);

u8 Flash_PageErase(u8 PageNumber);

#endif //FLASHER_INTERFACE_H
