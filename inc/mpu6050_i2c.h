#ifndef MPU6050_I2C_H
#define MPU6050_I2C_H

#include <stdint.h>

typedef struct {
    void (*i2c_write)(uint8_t reg, uint8_t value);
    int (*i2c_read)(uint8_t reg, uint8_t *data, uint8_t size);
} mpu6050_i2c_ops_t;

void mpu6050_set_i2c_spec(mpu6050_i2c_ops_t *ops);

int mpu6050_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size);
int mpu6050_i2c_write_reg(uint8_t reg, uint8_t value);

#endif
