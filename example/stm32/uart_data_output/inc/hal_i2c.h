
#ifndef __I2C_H__
#define __I2C_H__

#include "main.h"

extern I2C_HandleTypeDef hi2c1;

void MX_I2C1_Init(void);
void I2C_Send_Data(uint8_t *data, uint16_t size);

void stm32_i2c_write_reg(uint8_t reg, uint8_t value); 
int stm32_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size);

#endif /* __I2C_H__ */
