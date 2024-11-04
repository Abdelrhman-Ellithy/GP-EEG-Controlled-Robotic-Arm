################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/Button_progaram.c \
../Src/HAL/Buzzer_Program.c \
../Src/HAL/CLCD_program.c \
../Src/HAL/DCMOTOR_program.c \
../Src/HAL/Keypad_Program.c \
../Src/HAL/LED_Program.c \
../Src/HAL/Servo_Program.c 

OBJS += \
./Src/HAL/Button_progaram.o \
./Src/HAL/Buzzer_Program.o \
./Src/HAL/CLCD_program.o \
./Src/HAL/DCMOTOR_program.o \
./Src/HAL/Keypad_Program.o \
./Src/HAL/LED_Program.o \
./Src/HAL/Servo_Program.o 

C_DEPS += \
./Src/HAL/Button_progaram.d \
./Src/HAL/Buzzer_Program.d \
./Src/HAL/CLCD_program.d \
./Src/HAL/DCMOTOR_program.d \
./Src/HAL/Keypad_Program.d \
./Src/HAL/LED_Program.d \
./Src/HAL/Servo_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/%.o Src/HAL/%.su Src/HAL/%.cyclo: ../Src/HAL/%.c Src/HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-HAL

clean-Src-2f-HAL:
	-$(RM) ./Src/HAL/Button_progaram.cyclo ./Src/HAL/Button_progaram.d ./Src/HAL/Button_progaram.o ./Src/HAL/Button_progaram.su ./Src/HAL/Buzzer_Program.cyclo ./Src/HAL/Buzzer_Program.d ./Src/HAL/Buzzer_Program.o ./Src/HAL/Buzzer_Program.su ./Src/HAL/CLCD_program.cyclo ./Src/HAL/CLCD_program.d ./Src/HAL/CLCD_program.o ./Src/HAL/CLCD_program.su ./Src/HAL/DCMOTOR_program.cyclo ./Src/HAL/DCMOTOR_program.d ./Src/HAL/DCMOTOR_program.o ./Src/HAL/DCMOTOR_program.su ./Src/HAL/Keypad_Program.cyclo ./Src/HAL/Keypad_Program.d ./Src/HAL/Keypad_Program.o ./Src/HAL/Keypad_Program.su ./Src/HAL/LED_Program.cyclo ./Src/HAL/LED_Program.d ./Src/HAL/LED_Program.o ./Src/HAL/LED_Program.su ./Src/HAL/Servo_Program.cyclo ./Src/HAL/Servo_Program.d ./Src/HAL/Servo_Program.o ./Src/HAL/Servo_Program.su

.PHONY: clean-Src-2f-HAL

