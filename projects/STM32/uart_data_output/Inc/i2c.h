/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    i2c.h
 * @brief   This file contains all the function prototypes for
 *          the i2c.c file
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
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H__
#define __I2C_H__

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

void MX_I2C1_Init(void);
void I2C_Send_Data(uint8_t *data, uint16_t size);

void stm32_i2c_write_reg(uint8_t reg, uint8_t value); 
int stm32_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size);

#endif /* __I2C_H__ */
