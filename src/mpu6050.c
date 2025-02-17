#include "../inc/mpu6050.h"
#include "../inc/mpu6050_registers.h"
#include "../inc/mpu6050_i2c.h"

/*======================== HANDY FUNCTIONS ===========================*/

void mpu6050_init_reg(void)
{
    mpu6050_cfg_set_smprt_div(DEF_SAMPLE_RATE_DIV);
    mpu6050_cfg_set_config(DEF_FSYNC, DEF_DLPF);
    mpu6050_cfg_gyro(DEF_DISABLE_TEST, DEF_GYR_CFG);
    mpu6050_cfg_accel(DEF_DISABLE_TEST, DEF_ACC_CFG);
#if defined(USE_INT_PIN)
    mpu6050_cfg_int_pin(DEF_INT_LVL, DEF_INT_OP, DEF_EN_LATCH,
                        DEF_INT_CLR_MODE, DEF_FSYNC_LV, DEF_DIS_FSYNC_INT,
                        DEF_DIS_I2C_BYPASS);

    mpu6050_cfg_int_mode(DEF_EN_MOT_INT, DEF_DIS_FFULL_INT, DEF_DIS_I2C_MST_INT, DEF_DIS_DATA_RDY);

#endif
}

int mpu6050_get_data(mpu_data_t *data)
{
    uint8_t rawData[14]; // 14 bytes (6 accel, 2 temp, 6 gyro)

    uint8_t size = 1;
    uint8_t values[size];

    mpu6050_i2c_read_reg(REG_INT_STS, values, size);

    // Convert raw data (Assuming default sensitivity settings)
    data->accel.x = (int16_t)(rawData[0] << 8 | rawData[1]) / 16384.0f; // ±2g range
    data->accel.y = (int16_t)(rawData[2] << 8 | rawData[3]) / 16384.0f;
    data->accel.z = (int16_t)(rawData[4] << 8 | rawData[5]) / 16384.0f;

    data->tempt = (int16_t)(rawData[6] << 8 | rawData[7]) / 340.0f + 36.53f;

    data->gyro.x = (int16_t)(rawData[8] << 8 | rawData[9]) / 131.0f; // ±250°/s range
    data->gyro.y = (int16_t)(rawData[10] << 8 | rawData[11]) / 131.0f;
    data->gyro.z = (int16_t)(rawData[12] << 8 | rawData[13]) / 131.0f;

    return 0;
}

/*======================== SETUP FUNCTIONS ===========================*/

/* REG 0x19*/
void mpu6050_cfg_set_smprt_div(uint8_t val)
{
    mpu6050_i2c_write_reg(REG_SMPRT_DIV, val);
}

/* REG 0x1A*/
void mpu6050_cfg_set_config(uint8_t fsync, uint8_t dlpf)
{
    mpu6050_i2c_write_reg(REG_CFG, (fsync << 3) | dlpf);
}

/* REG 0x1B */
void mpu6050_cfg_gyro(uint8_t en_gyr_test, uint8_t fs_sel)
{
    uint8_t en_gyr_test_val = 0;
    if (en_gyr_test)
    {
        en_gyr_test_val = 0xE0;
    }
    mpu6050_i2c_write_reg(REG_GYRO_CFG, en_gyr_test_val | (fs_sel << 3));
}

/* REG 0x1C */
void mpu6050_cfg_accel(uint8_t en_acc_test, uint8_t fs_sel)
{
    uint8_t en_acc_test_val = 0;
    if (en_acc_test)
    {
        en_acc_test_val = 0xE0;
    }
    mpu6050_i2c_write_reg(REG_ACCEL_CFG, en_acc_test_val | (fs_sel << 3));
}

/* REG 0x1F */
void mpu6050_cfg_set_mot_thr(uint8_t val)
{
    mpu6050_i2c_write_reg(REG_MOT_THR, val);
}

/* REG 0x23 */
void mpu6050_cfg_en_fifo(uint8_t val)
{
    mpu6050_i2c_write_reg(REG_FIFO_EN, val);
}

/* REG 0x37 */
void mpu6050_cfg_int_pin(uint8_t int_lvl, uint8_t int_open,
                         uint8_t is_latch, uint8_t int_clr_mode,
                         uint8_t fsync_int_lv, uint8_t fsync_int_en,
                         uint8_t i2c_bypass_en)
{
    mpu6050_i2c_write_reg(
        REG_INT_PIN_CFG,
        (int_lvl << 7) | (int_open << 6) |
            (is_latch << 5) | (int_clr_mode << 4) |
            (fsync_int_lv << 3) | (fsync_int_en << 2) |
            (i2c_bypass_en << 1));
}

/* REG 0x38 */
void mpu6050_cfg_int_mode(uint8_t mot, uint8_t ffull, uint8_t i2c_mst_int, uint8_t data_rdy_int)
{
    mpu6050_i2c_write_reg(
        REG_INT_EN,
        (mot << 6) | (ffull << 4) |
            (i2c_mst_int << 3) | (data_rdy_int));
}

/* REG 0x6B*/
void mpu6050_cfg_pwr_mng(uint8_t mode)
{
    mpu6050_i2c_write_reg(REG_PWR_MGMT_1, mode);
}
/*======================== GET DATA FUNCTIONS ===========================*/

/* REG 0x3A */
int mpu6050_get_int_sts(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    mpu6050_i2c_read_reg(REG_INT_STS, val, size);
    return val[1];
}

/* REG 0x3B to 0x48 */
float mpu6050_get_temp(void)
{
    uint8_t size = 1;
    uint8_t val[size];
    uint16_t temp;
    mpu6050_i2c_read_reg(REG_TEMP_MSB, val, size);
    temp |= val[1] << 8;
    mpu6050_i2c_read_reg(REG_TEMP_LSB, val, size);
    temp |= val[1];

    return ((float)temp) / 340 + 36.53;
}

uint8_t mpu6050_get_accel_raw(mpu_rawdata_t *r_data)
{
    uint8_t size = 6;
    uint8_t rawData[size];                                   // Buffer for all 6 accelerometer bytes
    mpu6050_i2c_read_reg(REG_ACCEL_XOUT_MSB, rawData, size); // Read all at once

    // Convert raw data to 16-bit signed values
    r_data->accel_raw.x = (int16_t)((rawData[0] << 8) | rawData[1]);
    r_data->accel_raw.y = (int16_t)((rawData[2] << 8) | rawData[3]);
    r_data->accel_raw.z = (int16_t)((rawData[4] << 8) | rawData[5]);

    return 0;
}

/* REG 0x75 */
int mpu6050_get_chip_id(void)
{
    uint8_t size = 1;
    uint8_t values[size];

    mpu6050_i2c_read_reg(REG_WHO_AM_I, values, size);
    return values[0];
}