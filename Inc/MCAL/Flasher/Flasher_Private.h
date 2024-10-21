/*=================================================================================*/
/*  File        : FLASHER_PRIVATE_H                                                  */
/*  Description : This Program file includes AFIO program for STM32f103C8T6        */
/*  Abdelrahman Ellithy
 *  layer: MCAL
 *  SW component: Flasher
 *  																				*/
#ifndef FLASHER_PRIVATE_H
#define FLASHER_PRIVATE_H


#define FLASH_CR_PER  ((uint32_t)0x00000002)  // Page Erase bit
#define FLASH_SR_BSY  ((uint32_t)0x00000001)  // Busy flag
#define FLASH_SR_EOP  ((uint32_t)0x00000020)  // End of operation flag


// Flash memory base address
#define FLASH_BASE_ADDRESS 0x08000000

// Flash page size (1 KB for STM32F103C8T6)
#define FLASH_PAGE_SIZE 1024

// Flash keys for unlocking
#define FLASH_KEY1 0x45670123
#define FLASH_KEY2 0xCDEF89AB

// Flash status flags
#define FLASH_BUSY_FLAG FLASH_SR_BSY
#define FLASH_EOP_FLAG FLASH_SR_EOP

// Flash control commands
#define FLASH_START_ERASE FLASH_CR_STRT

// Error codes
#define FLASH_OK 1
#define FLASH_ERROR 0
#define FLASH_TIMEOUT 2


#endif //FLASHER_PRIVATE_H


