################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/subdir.mk
-include Src/HAL/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := GP-EEG-Controlled-Robotic-Arm
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GP-EEG-Controlled-Robotic-Arm.elf \

MAP_FILES += \
GP-EEG-Controlled-Robotic-Arm.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GP-EEG-Controlled-Robotic-Arm.list \

OBJCOPY_HEX += \
GP-EEG-Controlled-Robotic-Arm.hex \


# All Target
all: main-build

# Main-build Target
main-build: GP-EEG-Controlled-Robotic-Arm.elf secondary-outputs

# Tool invocations
GP-EEG-Controlled-Robotic-Arm.elf GP-EEG-Controlled-Robotic-Arm.map: $(OBJS) $(USER_OBJS) C:\Users\lenovo\STM32CubeIDE\workspace_1.14.0\GP-EEG-Controlled-Robotic-Arm\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "GP-EEG-Controlled-Robotic-Arm.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\lenovo\STM32CubeIDE\workspace_1.14.0\GP-EEG-Controlled-Robotic-Arm\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GP-EEG-Controlled-Robotic-Arm.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GP-EEG-Controlled-Robotic-Arm.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GP-EEG-Controlled-Robotic-Arm.list"
	@echo 'Finished building: $@'
	@echo ' '

GP-EEG-Controlled-Robotic-Arm.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "GP-EEG-Controlled-Robotic-Arm.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) GP-EEG-Controlled-Robotic-Arm.elf GP-EEG-Controlled-Robotic-Arm.hex GP-EEG-Controlled-Robotic-Arm.list GP-EEG-Controlled-Robotic-Arm.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
