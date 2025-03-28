// example of init ""
/*

void mpu6050_init(void) {
  mpu6050_i2c_ops_t ops = {
      .i2c_write = stm32_i2c_write, // replace this
      .i2c_read = stm32_i2c_read  // replace this
  };
  mpu6050_set_i2c_spec(&ops);
}

*/

#include "mpu6050_hw.h"


static mpu6050_i2c_ops_t i2c_ops;

void mpu6050_set_i2c_spec(mpu6050_i2c_ops_t *ops) {
    i2c_ops = *ops; // Copy the function pointers
}

int mpu6050_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size) {
    if (i2c_ops.i2c_read) {
        return i2c_ops.i2c_read(reg, data, size);
    }
    return -1; // Error: function not set
}

int mpu6050_i2c_write_reg(uint8_t reg, uint8_t value) {
    if (i2c_ops.i2c_write) {
        i2c_ops.i2c_write(reg, value);
        return 0;
    }
    return -1; // Error: function not set
}


