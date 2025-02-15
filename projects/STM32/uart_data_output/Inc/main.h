/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#include <stm32f1xx_hal.h>

#define LED_BLINK_DELAY 1000
#define I2C1_ADDRESS 0x00

void Error_Handler(void);

#endif /* __MAIN_H */
