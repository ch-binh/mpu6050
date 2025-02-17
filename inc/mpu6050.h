#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>

/* Recommended value */
#define USE_INT_PIN // comment this if not use int pin

#define DEFAULT 0x00 // use default setting

#define DEF_SAMPLE_RATE_DIV DEFAULT
#define DEF_FSYNC DEFAULT // if you bought the module without fsynce pin, make it 0, else refer to the datasheet
#define DEF_DLPF 0x02     // Acc: 94Hz, 3ms delay, Gyro: 98Hz, 2.8ms delay

#define DEF_DISABLE_TEST DEFAULT // default: off
#define DEF_GYR_CFG 0x01         // +-500 deg/s
#define DEF_ACC_CFG DEFAULT      // +-2g

#define DEF_INT_LVL DEFAULT        // When this bit is equal to 0, the logic level for the INT pin is active high.
#define DEF_INT_OP DEFAULT         // When this bit is equal to 0, the INT pin is configured as push-pull.
#define DEF_EN_LATCH 0x01          // When this bit is equal to 1, the INT pin is held high until the interrupt is cleared.
#define DEF_INT_CLR_MODE DEFAULT   // When this bit is equal to 0, interrupt status bits are cleared only by reading INT_STATUS
#define DEF_FSYNC_LV DEFAULT       // When this bit is equal to 0, the logic level for the FSYNC pin is active high.
#define DEF_DIS_FSYNC_INT DEFAULT  // When equal to 0, this bit disables the FSYNC pin
#define DEF_DIS_I2C_BYPASS DEFAULT // When this bit is equal to 0, the host application processor will not be able to directly access the auxiliary I2C bus

#define DEF_EN_MOT_INT 0x01
#define DEF_DIS_FFULL_INT DEFAULT   // off
#define DEF_DIS_I2C_MST_INT DEFAULT // off
#define DEF_DIS_DATA_RDY DEFAULT    // off

typedef struct {
    struct {
        int16_t x;
        int16_t y;
        int16_t z;
    } accel_raw;  // Raw accelerometer data (16-bit ADC value)

    struct {
        int16_t x;
        int16_t y;
        int16_t z;
    } gyro_raw;   // Raw gyroscope data (16-bit ADC value)

    int16_t tempt_raw; // Raw temperature data
} mpu_rawdata_t;

typedef struct {
    struct {
        float x;
        float y;
        float z;
    } accel;  // Accelerometer data (g)

    struct {
        float x;
        float y;
        float z;
    } gyro;   // Gyroscope data (°/s)

    float tempt; // Temperature data (°C)
} mpu_data_t;




/*======================== HANDY FUNCTIONS ===========================*/
/**
 * @brief
 */
void mpu6050_init_reg(void);
/*======================== SETUP FUNCTIONS ===========================*/

/* REG 0x25*/
void mpu6050_cfg_set_smprt_div(uint8_t value);
/**
 * @brief REG 0x26
 * @note
 */
void mpu6050_cfg_set_config(uint8_t fsync, uint8_t dlpf);

/* REG 0x1B */
void mpu6050_cfg_gyro(uint8_t en_gyr_test, uint8_t fs_sel);
/* REG 0x1C */
void mpu6050_cfg_accel(uint8_t en_acc_test, uint8_t fs_sel);
/* REG 0x1F */
void mpu6050_cfg_set_mot_thr(uint8_t val);
/* REG 0x23 */
void mpu6050_cfg_en_fifo(uint8_t val);
/* REG 0x37 */
void mpu6050_cfg_int_pin(uint8_t int_lvl, uint8_t int_open,
                         uint8_t is_latch, uint8_t int_clr_mode,
                         uint8_t fsync_int_lv, uint8_t fsync_int_en,
                         uint8_t i2c_bypass_en);

/* REG 0x38 */
void mpu6050_cfg_int_mode(uint8_t mot, uint8_t ffull, uint8_t i2c_mst_int, uint8_t data_rdy_int);

/* REG 0x6B*/
void mpu6050_cfg_pwr_mng(uint8_t mode);

/*======================== GET DATA FUNCTIONS ===========================*/

/* REG 0x3A */
int mpu6050_get_int_sts(void);
/* REG 0x3B to 0x40*/
uint8_t mpu6050_get_accel_raw(mpu_rawdata_t *r_data);
/* REG 0x75 */
int mpu6050_get_chip_id(void);

#endif // MPU6050_H