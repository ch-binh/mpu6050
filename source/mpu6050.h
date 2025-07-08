/**
 ******************************************************************************
 * @file    mpu6050.h
 * @brief   [Short module description, e.g.] Interface for Template Math Module
 * @details This file provides declarations for configuration macros, types,
 *          and public API for the Template module. Designed for embedded use.
 *
 * @date    2025/07/08
 * @author  Binh Pham
 * @version 1.0.0
 * @license MIT
 ******************************************************************************
 * @attention
 * This is a template header file. Replace placeholder content before use.
 ******************************************************************************
 */

#ifndef __MPU6050_H
#define __MPU6050_H

/* Includes ----------------------------------------------------------------- */
/* Standard libraries */
#include <stdint.h>

/* Project-specific headers */

/* Configuration ------------------------------------------------------------ */

/* Public defines ----------------------------------------------------------- */

/* Recommended value */
#define USE_INT_PIN // comment this if not use int pin

#define DEFAULT 0x00 // use default setting

#define DEF_SAMPLE_RATE_DIV DEFAULT
#define DEF_FSYNC \
  DEFAULT             // if you bought the module without fsynce pin, make it 0, else refer to the datasheet
#define DEF_DLPF 0x02 // Acc: 94Hz, 3ms delay, Gyro: 98Hz, 2.8ms delay

#define DEF_DISABLE_TEST DEFAULT // default: off
#define DEF_GYR_CFG      0x01    // +-500 deg/s
#define DEF_ACC_CFG      DEFAULT // +-2g

#define DEF_INT_LVL DEFAULT // When this bit is equal to 0, the logic level for the INT pin is active high.
#define DEF_INT_OP  DEFAULT // When this bit is equal to 0, the INT pin is configured as push-pull.
#define DEF_EN_LATCH \
  0x01 // When this bit is equal to 1, the INT pin is held high until the interrupt is cleared.
#define DEF_INT_CLR_MODE \
  DEFAULT // When this bit is equal to 0, interrupt status bits are cleared only by reading INT_STATUS
#define DEF_FSYNC_LV      DEFAULT // When this bit is equal to 0, the logic level for the FSYNC pin is active high.
#define DEF_DIS_FSYNC_INT DEFAULT // When equal to 0, this bit disables the FSYNC pin
#define DEF_DIS_I2C_BYPASS \
  DEFAULT // When this bit is equal to 0, the host application processor will not be able to directly access
          // the auxiliary I2C bus

#define DEF_EN_MOT_INT      0x01
#define DEF_DIS_FFULL_INT   DEFAULT // off
#define DEF_DIS_I2C_MST_INT DEFAULT // off
#define DEF_DIS_DATA_RDY    DEFAULT // off

#define ACCEL_SENS_2G  16384.0f // LSB/g for ±2g range
#define ACCEL_SENS_4G  8192.0f
#define ACCEL_SENS_8G  4096.0f
#define ACCEL_SENS_16G 2048.0f

#define GYRO_SENS_250  131.0f // LSB/(°/s) for ±250°/s range
#define GYRO_SENS_500  65.5f
#define GYRO_SENS_1000 32.8f
#define GYRO_SENS_2000 16.4f

/* Registers ---------------------------------------------------------------- */
/* Registers 13 to 16 – Self Test Registers
* These registers are used for gyroscope and accelerometer self-tests that permit the user to test the
mechanical and electrical portions of the gyroscope and the accelerometer
*/
#define REG_SELF_TEST_X 0x0D
#define REG_SELF_TEST_Y 0x0E
#define REG_SELF_TEST_Z 0x0F
#define REG_SELF_TEST_A 0x10

/* CONFIG REG */
#define REG_SMPRT_DIV 0x19 // Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
#define REG_CFG \
  0x1A // This register configures the external Frame Synchronization (FSYNC) pin sampling and the Digital Low
       // Pass Filter (DLPF)
#define REG_GYRO_CFG \
  0x1B // This register is used to trigger gyroscope self-test and configure the gyroscopes’ full scale range.
#define REG_ACCEL_CFG \
  0x1C // This register is used to trigger accelerometer self-test and configure the gyroscopes’ full scale
       // range.

/* FEATURE REG */
#define REG_MOT_THR 0x1F // This register configures the detection threshold for Motion interrupt generation
#define REG_FIFO_EN \
  0x23 // This register determines which sensor measurements are loaded into the FIFO buffer.

/* I2C settings */
#define REG_MST_CTRL      0x24 // Dont care
#define REG_I2C_SLV0_ADDR 0x25 // Dont care
#define REG_I2C_SLV0_REG  0x26 // Dont care
#define REG_I2C_SLV0_CTRL 0x27 // Dont care
#define REG_I2C_SLV1_ADDR 0x28 // Dont care
#define REG_I2C_SLV1_REG  0x29 // Dont care
#define REG_I2C_SLV1_CTRL 0x2A // Dont care
#define REG_I2C_SLV2_ADDR 0x2B // Dont care
#define REG_I2C_SLV2_REG  0x2C // Dont care
#define REG_I2C_SLV2_CTRL 0x2D // Dont care
#define REG_I2C_SLV3_ADDR 0x2E // Dont care
#define REG_I2C_SLV3_REG  0x2F // Dont care
#define REG_I2C_SLV3_CTRL 0x30 // Dont care
#define REG_I2C_SLV4_ADDR 0x31 // Dont care
#define REG_I2C_SLV4_REG  0x32 // Dont care
#define REG_I2C_SLV4_DO   0x33 // Dont care
#define REG_I2C_SLV4_CTRL 0x34 // Dont care
#define REG_I2C_SLV4_DI   0x35 // Dont care
#define REG_I2C_MST_STS   0x36

/* INTERRUPT SETTINGS */
#define REG_INT_PIN_CFG \
  0x37                   // This register configures the behavior of the interrupt signals at the INT pins.
#define REG_INT_EN  0x38 // This register enables interrupt generation by interrupt sources.
#define REG_INT_STS 0x39 // This register shows the interrupt status of each interrupt generation source

/* ACCEL, GYRO, TEMP DATA */
#define REG_ACCEL_XOUT_MSB 0x3B
#define REG_ACCEL_XOUT_LSB 0x3C
#define REG_ACCEL_YOUT_MSB 0x3D
#define REG_ACCEL_YOUT_LSB 0x3E
#define REG_ACCEL_ZOUT_MSB 0x3F
#define REG_ACCEL_ZOUT_LSB 0x40

#define REG_TEMP_MSB 0x41
#define REG_TEMP_LSB 0x42

#define REG_GYRO_XOUT_MSB 0x43
#define REG_GYRO_XOUT_LSB 0x44
#define REG_GYRO_YOUT_MSB 0x45
#define REG_GYRO_YOUT_LSB 0x46
#define REG_GYRO_ZOUT_MSB 0x47
#define REG_GYRO_ZOUT_LSB 0x48

#define REG_PWR_MGMT_1 0x6B
#define REG_PWR_MGMT_2 0x69

/* */
#define REG_WHO_AM_I       0x75 // This register is used to verify the identity of the device
#define REG_WHO_AMW_I_DEFV 0x68 // Default value for REG_WHO_AM_I

/* Public macros ------------------------------------------------------------ */
/* Helper macros ------------------------------------------------------------ */
/* Public typedefs ---------------------------------------------------------- */
typedef struct
{
  struct
  {
    int16_t x;
    int16_t y;
    int16_t z;
  } accel_raw; // Raw accelerometer data (16-bit ADC value)

  struct
  {
    int16_t x;
    int16_t y;
    int16_t z;
  } gyro_raw; // Raw gyroscope data (16-bit ADC value)

  int16_t tempt_raw; // Raw temperature data
} mpu_rawdata_t;

typedef struct
{
  struct
  {
    float x;
    float y;
    float z;
  } accel; // Accelerometer data (g)

  struct
  {
    float x;
    float y;
    float z;
  } gyro; // Gyroscope data (°/s)

  float tempt; // Temperature data (°C)
} mpu_data_t;

typedef struct
{
  struct
  {
    float accel;
    float gyro;
  } fs_range;

  struct
  {
    float div;
  } smprt;

  struct
  {
    uint32_t smprt;
    uint8_t  is_en;
    uint8_t  op_mode;
  } fsync;

  struct
  {
    uint8_t dlpf;
  } filter;

  struct
  {
    uint8_t is_gyr_en;
    uint8_t is_accel_en;
  } test;

  struct
  {
    uint8_t is_en;
    uint8_t thr;
  } mot;

} mpu_cfg_t;

typedef struct
{
  void (*i2c_write)(uint8_t reg, uint8_t value);
  int (*i2c_read)(uint8_t reg, uint8_t *data, uint8_t size);
} mpu6050_i2c_ops_t;

/* Enumerations ------------------------------------------------------------- */
/* Structures --------------------------------------------------------------- */
/* Error codes -------------------------------------------------------------- */
/* Function prototypes ------------------------------------------------------ */

void mpu6050_set_i2c_spec(mpu6050_i2c_ops_t *ops);

int mpu6050_read_reg(uint8_t reg, uint8_t *data, uint8_t size);
int mpu6050_write_reg(uint8_t reg, uint8_t value);

/*======================== HANDY FUNCTIONS ===========================*/
/**
 * @brief
 */
void mpu6050_init_reg(void);
int  mpu6050_get_raw_data(mpu_rawdata_t *r_data);
int  mpu6050_raw_data_to_readable_data(mpu_data_t *data, mpu_rawdata_t *r_data);

/**
 * @brief helper to copy an instance of system configuration
 * @return mpu_cfg_t
 */
mpu_cfg_t mpu6050_get_sys_cfg(void);
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
void mpu6050_cfg_int_pin(uint8_t int_lvl, uint8_t int_open, uint8_t is_latch, uint8_t int_clr_mode,
                         uint8_t fsync_int_lv, uint8_t fsync_int_en, uint8_t i2c_bypass_en);

/* REG 0x38 */
void mpu6050_cfg_int_mode(uint8_t mot, uint8_t ffull, uint8_t i2c_mst_int, uint8_t data_rdy_int);

/* REG 0x6B*/
void mpu6050_cfg_pwr_mng(uint8_t mode);

/*======================== GET DATA FUNCTIONS ===========================*/

/* REG 0x1B, 0x1C */
int mpu6050_get_fs(mpu_cfg_t *mpu_cfg);
/* REG 0x3A */
int mpu6050_get_int_sts(void);
/* REG 0x3B to 0x40*/
uint8_t mpu6050_get_accel_raw(mpu_rawdata_t *r_data);
/* REG 0x41 to 0x42 */
uint8_t mpu6050_get_temp_raw(mpu_rawdata_t *r_data);
/* REG 0x43 to 0x48*/
uint8_t mpu6050_get_gyro_raw(mpu_rawdata_t *r_data);

/* REG 0x75 */
int mpu6050_get_chip_id(void);

#endif /* __MPU6050_H */

/* End of File -------------------------------------------------------------- */