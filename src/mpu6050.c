#include "../inc/mpu6050.h"
#include "../inc/mpu6050_registers.h"
#include "../inc/mpu6050_i2c.h"


static mpu_cfg_t sys_cfg;
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

int mpu6050_get_raw_data(mpu_rawdata_t *r_data)
{
    mpu6050_get_accel_raw(&r_data);
    mpu6050_get_temp_raw(&r_data);
    mpu6050_get_gyro_raw(&r_data);

    return 0;
}

int mpu6050_raw_data_to_readable_data(mpu_data_t *data, mpu_rawdata_t *r_data)
{
    if (!data || !r_data)
    {
        return -1; // Return error if NULL pointers are passed
    }

    mpu_cfg_t mpu_cfg;

    mpu6050_get_fs(&mpu_cfg);

    // Convert acceleration raw values to g (gravity)
    data->accel.x = r_data->accel_raw.x / mpu_cfg.fs_range.accel;
    data->accel.y = r_data->accel_raw.y / mpu_cfg.fs_range.accel;
    data->accel.z = r_data->accel_raw.z / mpu_cfg.fs_range.accel;

    // Convert gyroscope raw values to degrees per second (°/s)
    data->gyro.x = r_data->gyro_raw.x / mpu_cfg.fs_range.gyro;
    data->gyro.y = r_data->gyro_raw.y / mpu_cfg.fs_range.gyro;
    data->gyro.z = r_data->gyro_raw.z / mpu_cfg.fs_range.gyro;

    // Convert temperature raw value to degrees Celsius
    data->tempt = (r_data->tempt_raw / 340.0f) + 36.53f;

    return 0; // Success
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

int mpu6050_get_fs(mpu_cfg_t *mpu_cfg)
{
    uint8_t size = 2;
    uint8_t val[size];

    mpu6050_i2c_read_reg(REG_GYRO_CFG, val, size);

    const uint8_t gyro_index = (val[0] & 0b00011000) >> 3;
    const uint8_t accel_index = (val[1] & 0b00011000) >> 3;

    const float gyro_sensitivities[] = {
        GYRO_SENS_250,
        GYRO_SENS_500,
        GYRO_SENS_1000,
        GYRO_SENS_2000};

    const float accel_sensitivities[] = {
        ACCEL_SENS_2G,
        ACCEL_SENS_4G,
        ACCEL_SENS_8G,
        ACCEL_SENS_16G};

    mpu_cfg->fs_range.gyro = gyro_sensitivities[gyro_index];
    mpu_cfg->fs_range.accel = accel_sensitivities[accel_index];

    return 0;
}

/* REG 0x3A */
int mpu6050_get_int_sts(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    mpu6050_i2c_read_reg(REG_INT_STS, val, size);
    return val[1];
}

uint8_t mpu6050_get_accel_raw(mpu_rawdata_t *r_data)
{
    uint8_t size = 6;
    uint8_t val[size];                                   // Buffer for all 6 accelerometer bytes
    mpu6050_i2c_read_reg(REG_ACCEL_XOUT_MSB, val, size); // Read all at once

    // Convert raw data to 16-bit signed values
    r_data->accel_raw.x = (int16_t)((val[0] << 8) | val[1]);
    r_data->accel_raw.y = (int16_t)((val[2] << 8) | val[3]);
    r_data->accel_raw.z = (int16_t)((val[4] << 8) | val[5]);

    return 0;
}
/* REG 0x41 to 0x42 */
uint8_t mpu6050_get_temp_raw(mpu_rawdata_t *r_data)
{
    uint8_t size = 2;
    uint8_t val[size];
    mpu6050_i2c_read_reg(REG_TEMP_MSB, val, size);
    r_data->tempt_raw = val[0] << 8 | val[1];
    //((float)temp) / 340 + 36.53
    return 0;
}

/* REG 0x43 to 0x48*/
uint8_t mpu6050_get_gyro_raw(mpu_rawdata_t *r_data)
{
    uint8_t size = 6;
    uint8_t val[size];                                  // Buffer for all 6 accelerometer bytes
    mpu6050_i2c_read_reg(REG_GYRO_XOUT_MSB, val, size); // Read all at once

    // Convert raw data to 16-bit signed values
    r_data->gyro_raw.x = (int16_t)((val[0] << 8) | val[1]);
    r_data->gyro_raw.y = (int16_t)((val[2] << 8) | val[3]);
    r_data->gyro_raw.z = (int16_t)((val[4] << 8) | val[5]);

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