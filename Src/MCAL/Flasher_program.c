#include "LIB/STD_TYPES.h"
#include "LIB/BIT_OPERATIONS.h"
#include "LIB/BIT_MATH.h"
#include "LIB/Types.h"
#include "LIB/stm32f103c8t6.h"
#include "MCAL/Flasher/Flasher_Config.h"
#include "MCAL/Flasher/Flasher_Interface.h"
#include "MCAL/Flasher/Flasher_Private.h"



void Flash_Init(void) {
    // Unlock sequence
	FPEC->KEYR = FLASH_KEY1;
	FPEC->KEYR = FLASH_KEY2;
}
void Flash_EraseAppArea(void)
{
	u8 i ;
	for (i=20;i<64;i++)
	{
		Flash_PageErase(i);
	}
}

u8 Flash_PageErase(u8 PageNumber)
{
	u32 pageAddress= (u32)(PageNumber * FLASH_PAGE_SIZE) + FLASH_BASE_ADDRESS;
	   // Ensure the address is within bounds
	if (pageAddress < FLASH_START_ADDRESS || pageAddress > FLASH_END_ADDRESS) {
	        return FLASH_ERROR;
	 }
	/* Wait Busy Flag */
	while (GET_BIT( FPEC-> SR,0) == 1);

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC -> CR , 7) == 1)
	{
		FPEC -> KEYR = FLASH_KEY1;
		FPEC -> KEYR = FLASH_KEY2;
	}
	/* Page Erase Operation */
	SET_BIT(FPEC -> CR , 1);

	/* Write Page address */
	FPEC -> AR = pageAddress;

	/* Start operation */
	SET_BIT(FPEC -> CR , 6);

	/* Wait Busy Flag */
	while (GET_BIT(FPEC -> SR , 0) == 1);

	/* EOP */
	SET_BIT(FPEC -> SR , 5);
	CLR_BIT(FPEC -> CR , 1);
	return FLASH_OK;
}

u8 Flash_Write(u32 address, u8* data, u32 length){


    if (address < FLASH_START_ADDRESS || address + length > FLASH_END_ADDRESS) {
        return FLASH_ERROR;
    }

	while (GET_BIT(FPEC -> SR , 0) == 1);

	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC -> CR , 7) == 1)
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}

	volatile u16 temp;
	u32 i;
	for (i = 0 ; i< length ; i++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC -> CR , 0);

		/* Half word operation */

		temp = (data[i] |(data[i + 1] << 8) );
		*((volatile u16*)address) = temp;
		address += 2 ;

		/* Wait Busy Flag */
		while (GET_BIT(FPEC -> SR , 0) == 1);

		/* EOP */
		SET_BIT(FPEC -> SR , 5);
		CLR_BIT(FPEC -> CR , 0);
	}
	return FLASH_OK;

}

void Flash_Read(u32 address, u8* buffer, u32 length) {
    for (u32 i = 0; i < length; i++) {
        buffer[i] = *(volatile u8*)(address + i);
    }
}
