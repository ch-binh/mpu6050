
#ifndef __MAIN_H
#define __MAIN_H

#include <stm32f1xx_hal.h>

#include "board_config.h"

#define LED_BLINK_DELAY 1000
#define I2C1_ADDRESS (0x68 << 1)

void Error_Handler(void);

#endif /* __MAIN_H */
