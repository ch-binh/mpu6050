#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

/*======================| GPIO |======================*/
#define BUILTIN_LED_PORT GPIOC
#define BUILTIN_LED_PIN GPIO_PIN_13

/*======================| I2C |======================*/
#define I2C1_SCL_PORT GPIOB
#define I2C1_SCL_PIN GPIO_PIN_6
#define I2C1_SDA_PORT GPIOB
#define I2C1_SDA_PIN GPIO_PIN_7

#define I2C1_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2C1_GPIO_CLK_DISABLE() __HAL_RCC_GPIOB_CLK_DISABLE()

/*======================| UART |======================*/

#endif // BOARD_CONFIG_H