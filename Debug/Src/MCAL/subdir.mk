################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/ADC_program.c \
../Src/MCAL/AFIO_program.c \
../Src/MCAL/DMA_program.c \
../Src/MCAL/EXTI_program.c \
../Src/MCAL/Flasher_program.c \
../Src/MCAL/GPIO_program.c \
../Src/MCAL/GPT_Program.c \
../Src/MCAL/NVIC_program.c \
../Src/MCAL/PORT_program.c \
../Src/MCAL/RCC_program.c \
../Src/MCAL/SYSTICK_program.c \
../Src/MCAL/TIMER1_program.c \
../Src/MCAL/UART_Program.c 

OBJS += \
./Src/MCAL/ADC_program.o \
./Src/MCAL/AFIO_program.o \
./Src/MCAL/DMA_program.o \
./Src/MCAL/EXTI_program.o \
./Src/MCAL/Flasher_program.o \
./Src/MCAL/GPIO_program.o \
./Src/MCAL/GPT_Program.o \
./Src/MCAL/NVIC_program.o \
./Src/MCAL/PORT_program.o \
./Src/MCAL/RCC_program.o \
./Src/MCAL/SYSTICK_program.o \
./Src/MCAL/TIMER1_program.o \
./Src/MCAL/UART_Program.o 

C_DEPS += \
./Src/MCAL/ADC_program.d \
./Src/MCAL/AFIO_program.d \
./Src/MCAL/DMA_program.d \
./Src/MCAL/EXTI_program.d \
./Src/MCAL/Flasher_program.d \
./Src/MCAL/GPIO_program.d \
./Src/MCAL/GPT_Program.d \
./Src/MCAL/NVIC_program.d \
./Src/MCAL/PORT_program.d \
./Src/MCAL/RCC_program.d \
./Src/MCAL/SYSTICK_program.d \
./Src/MCAL/TIMER1_program.d \
./Src/MCAL/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/%.o Src/MCAL/%.su Src/MCAL/%.cyclo: ../Src/MCAL/%.c Src/MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-MCAL

clean-Src-2f-MCAL:
	-$(RM) ./Src/MCAL/ADC_program.cyclo ./Src/MCAL/ADC_program.d ./Src/MCAL/ADC_program.o ./Src/MCAL/ADC_program.su ./Src/MCAL/AFIO_program.cyclo ./Src/MCAL/AFIO_program.d ./Src/MCAL/AFIO_program.o ./Src/MCAL/AFIO_program.su ./Src/MCAL/DMA_program.cyclo ./Src/MCAL/DMA_program.d ./Src/MCAL/DMA_program.o ./Src/MCAL/DMA_program.su ./Src/MCAL/EXTI_program.cyclo ./Src/MCAL/EXTI_program.d ./Src/MCAL/EXTI_program.o ./Src/MCAL/EXTI_program.su ./Src/MCAL/Flasher_program.cyclo ./Src/MCAL/Flasher_program.d ./Src/MCAL/Flasher_program.o ./Src/MCAL/Flasher_program.su ./Src/MCAL/GPIO_program.cyclo ./Src/MCAL/GPIO_program.d ./Src/MCAL/GPIO_program.o ./Src/MCAL/GPIO_program.su ./Src/MCAL/GPT_Program.cyclo ./Src/MCAL/GPT_Program.d ./Src/MCAL/GPT_Program.o ./Src/MCAL/GPT_Program.su ./Src/MCAL/NVIC_program.cyclo ./Src/MCAL/NVIC_program.d ./Src/MCAL/NVIC_program.o ./Src/MCAL/NVIC_program.su ./Src/MCAL/PORT_program.cyclo ./Src/MCAL/PORT_program.d ./Src/MCAL/PORT_program.o ./Src/MCAL/PORT_program.su ./Src/MCAL/RCC_program.cyclo ./Src/MCAL/RCC_program.d ./Src/MCAL/RCC_program.o ./Src/MCAL/RCC_program.su ./Src/MCAL/SYSTICK_program.cyclo ./Src/MCAL/SYSTICK_program.d ./Src/MCAL/SYSTICK_program.o ./Src/MCAL/SYSTICK_program.su ./Src/MCAL/TIMER1_program.cyclo ./Src/MCAL/TIMER1_program.d ./Src/MCAL/TIMER1_program.o ./Src/MCAL/TIMER1_program.su ./Src/MCAL/UART_Program.cyclo ./Src/MCAL/UART_Program.d ./Src/MCAL/UART_Program.o ./Src/MCAL/UART_Program.su

.PHONY: clean-Src-2f-MCAL

