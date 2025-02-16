#include "../inc/mpu6050.h"
#include "../inc/mpu6050_registers.h"
#include "../inc/mpu6050_i2c.h"

/*======================== SETUP FUNCTIONS ===========================*/

/*======================== GET DATA FUNCTIONS ===========================*/

void mpu6050_get_chip_id(void)
{
    uint8_t size = 1;
    uint8_t values[size];

    mpu6050_i2c_read_reg(REG_WHO_AM_I, values, size);
    return values[1];
}