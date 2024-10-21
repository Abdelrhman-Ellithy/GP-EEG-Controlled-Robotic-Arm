#include "LIB/BIT_OPERATIONS.h"
#include "LIB/BIT_MATH.h"
#include "LIB/stm32f103c8t6.h"
#include "LIB/STD_TYPES.h"
#include "LIB/Types.h"
#include "MCAL/GPT/GPT_Interface.h"
#include "MCAL/GPT/GPT_Private.h"
#include "MCAL/GPT/GPT_Config.h"

static GPT_RegDef_t * GPT[]={TIMER2,TIMER3,TIMER4};
static fptr_t Global_pfArr[3] = {NULL,NULL,NULL};
