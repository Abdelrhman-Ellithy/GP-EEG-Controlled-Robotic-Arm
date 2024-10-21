# 🎓 Graduation_Project_Robotic_Arm 🤖

This project showcases the development of an **EEG-controlled 4DOF Robotic Arm** using the **STM32f103c8t6** microcontroller (Blue Pill). The arm is designed to perform basic movements controlled by EEG signals, making it suitable for assistive technologies and prosthetic applications.

## ✨ Features

- 🦾 **4 Degrees of Freedom (DOF)** Robotic Arm controlled by EEG signals.
- 💻 **STM32F103C8T6** microcontroller (Blue Pill) for handling motor control and sensor interfacing.
- 🧩 Modular design with separate layers for **HAL** (Hardware Abstraction Layer), **MCAL** (Microcontroller Abstraction Layer), and **LIB** (Utility Libraries).
- ⚙️ Control peripherals like **Servo Motors**, **DC Motors**, **LCD**, **LED**, **Keypad**, **Buzzer**, and **Button** modules.
- 💾 Embedded software development with **C** programming language.

## Project Structure

```
Graduation_Project_Robotic_Arm
├── .settings
├── Inc
│   ├── HAL
│   │   ├── BUTTON
│   │   │   └── Button_Config.h
│   │   │   └── Button_Interface.h
│   │   │   └── Button_Private.h
│   │   ├── BUZZER
│   │   │   └── Buzzer_Interface.h
│   │   │   └── Buzzer_Private.h
│   │   │   └── Buzzzer_Config.h
│   │   ├── DC Motor
│   │   │   └── DCMOTOR_Interface.h
│   │   │   └── DC_Motor_Config.h
│   │   │   └── DC_Motor_Private.h
│   │   ├── Keypad
│   │   │   └── Keypad_Config.h
│   │   │   └── Keypad_Private.h
│   │   │   └── Keypad_interface.h
│   │   ├── LCD
│   │   │   └── CLCD_config.h
│   │   │   └── CLCD_extrachar.h
│   │   │   └── CLCD_interface.h
│   │   │   └── CLCD_private.h
│   │   ├── LED
│   │   │   └── LED_Config.h
│   │   │   └── LED_Interface.h
│   │   │   └── LED_Private.h
│   │   ├── Servo
│   │   │   └── Servo_Interface.h
│   │   │   └── Servo_conifg.h
│   │   │   └── Servo_private.h
│   ├── LIB
│   │   └── BIT_MATH.h
│   │   └── BIT_OPERATIONS.h
│   │   └── STD_TYPES.h
│   │   └── Types.h
│   │   └── ellithy_delay.h
│   │   └── stm32f103c8t6.h
│   ├── MCAL
│   │   ├── ADC
│   │   │   └── ADC_Config.h
│   │   │   └── ADC_Interface.h
│   │   │   └── ADC_Private.h
│   │   ├── AFIO
│   │   │   └── AFIO_Config.h
│   │   │   └── AFIO_Private.h
│   │   │   └── AFIO_interface.h
│   │   ├── DMA
│   │   │   └── DMA_config.h
│   │   │   └── DMA_interface.h
│   │   │   └── DMA_private.h
│   │   ├── EXTI
│   │   │   └── EXTI_Config.h
│   │   │   └── EXTI_Private.h
│   │   │   └── EXTI_interface.h
│   │   ├── Flasher
│   │   │   └── Flasher_Config.h
│   │   │   └── Flasher_Interface.h
│   │   │   └── Flasher_Private.h
│   │   ├── GPIO
│   │   │   └── GPIO_Config.h
│   │   │   └── GPIO_interface.h
│   │   │   └── GPIO_private.h
│   │   ├── GPT
│   │   │   └── GPT_Config.h
│   │   │   └── GPT_Interface.h
│   │   │   └── GPT_Private.h
│   │   ├── NVIC
│   │   │   └── NVIC_Config.h
│   │   │   └── NVIC_Interface.h
│   │   │   └── NVIC_Private.h
│   │   ├── PORT
│   │   │   └── PORT_config.h
│   │   │   └── PORT_interface.h
│   │   │   └── PORT_private.h
│   │   ├── RCC
│   │   │   └── RCC_config.h
│   │   │   └── RCC_interface.h
│   │   │   └── RCC_private.h
│   │   ├── SYSTICK
│   │   │   └── SysTicK_private.h
│   │   │   └── SysTick_Interface.h
│   │   │   └── Systick._Config.h
│   │   ├── TIMER1
│   │   │   └── TIMER1_config.h
│   │   │   └── TIMER1_interface.h
│   │   │   └── TIMER1_private.h
│   │   ├── UART
│   │   │   └── UART_Config.h
│   │   │   └── UART_interface.h
│   │   │   └── UART_private.h
├── Src
│   ├── HAL
│   │   └── Button_progaram.c
│   │   └── Buzzer_Program.c
│   │   └── CLCD_program.c
│   │   └── DCMOTOR_program.c
│   │   └── Keypad_Program.c
│   │   └── LED_Program.c
│   │   └── Servo_Program.c
│   ├── MCAL
│   │   └── ADC_program.c
│   │   └── AFIO_program.c
│   │   └── DMA_program.c
│   │   └── EXTI_program.c
│   │   └── Flasher_program.c
│   │   └── GPIO_program.c
│   │   └── GPT_Program.c
│   │   └── NVIC_program.c
│   │   └── PORT_program.c
│   │   └── RCC_program.c
│   │   └── SYSTICK_program.c
│   │   └── TIMER1_program.c
│   │   └── UART_Program.c
│   └── ellithy_dalay.c
│   └── main.c
│   └── syscalls.c
│   └── sysmem.c
├── Startup
│   └── startup_stm32f103c8tx.s
└── .cproject
└── .project
└── LICENSE
└── README.md
└── STM32F103C8TX_FLASH.ld
```

## 🛠️ Components Used

- 🔌 **Microcontroller**: STM32F103C8T6 (Blue Pill)
- 🧠 **EEG Sensor**: Captures EEG signals and sends commands to control the robotic arm.
- 🦿 **Servo Motors**: For movement of the robotic arm joints.
- 🔄 **DC Motor**: For base rotation of the robotic arm.
- 📟 **LCD**: Displays information to the user.
- 🔢 **Keypad**: Provides manual input control.
- 🔔 **Buzzer/LED**: Used for notifications.

## 🧑‍💻 How to Build and Run

### Prerequisites

- ⚙️ **STM32CubeMX**: To configure peripherals and generate initialization code.
- 🖥️ **Keil uVision** or **STM32CubeIDE**: To compile and upload the code to the STM32 microcontroller.
- 🛠️ **ST-Link** or **USB-to-Serial**: For flashing the firmware onto the microcontroller.

### 🚀 Building

1. Clone the repository:
   ```bash
   git clone <repository_link>
   ```

2. Open the project in **STM32CubeIDE** or **Keil uVision**.
3. Configure the project settings and peripherals in **STM32CubeMX**.
4. Build the project and flash the code onto the STM32 microcontroller using **ST-Link** or **USB-to-Serial**.

### 📈 Running the Project

1. Connect the **STM32F103C8T6** microcontroller to the robotic arm components (motors, LCD, sensors).
2. Power up the microcontroller.
3. The robotic arm will respond to EEG signals and perform the programmed movements.
4. Use the **LCD** and **Keypad** for manual control and displaying system status.

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
