# UART Data Output with MPU6050 and STM32

This project demonstrates how to interface the MPU6050 sensor with an STM32 microcontroller to output data via UART.

## Requirements

- STM32 microcontroller
- MPU6050 sensor module
- UART interface
- STM32CubeMX
- Preferred IDE

## Setup

1. **Hardware Connections:**
    - Connect the MPU6050 to the STM32 microcontroller using I2C.
    - Connect the UART pins of the STM32 to a serial-to-USB converter for data output.

2. **Software Configuration:**
    - Use STM32CubeMX to configure the I2C and UART peripherals.
    - Generate the initialization code and open it in your preferred IDE.

## Code Overview

- **main.c:** Initializes the MPU6050 and UART, reads sensor data, and sends it over UART.
- **mpu6050.c/.h:** Contains functions to initialize and read data from the MPU6050.
- **usart.c/.h:** Contains functions to configure and use the UART interface.

## Usage

1. Flash the generated code to the STM32 microcontroller.
2. Open a serial terminal on your PC and connect to the appropriate COM port.
3. Observe the MPU6050 data being output via UART.

## License

This project is licensed under the MIT License.

## References

- [MPU6050 Datasheet](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
- [STM32CubeMX Documentation](https://www.st.com/en/development-tools/stm32cubemx.html)
