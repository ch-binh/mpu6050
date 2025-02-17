#ifndef MPU6050_REGISTERS_H
#define MPU6050_REGISTERS_H

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
#define REG_CFG 0x1A       // This register configures the external Frame Synchronization (FSYNC) pin sampling and the Digital Low Pass Filter (DLPF)
#define REG_GYRO_CFG 0x1B  // This register is used to trigger gyroscope self-test and configure the gyroscopes’ full scale range.
#define REG_ACCEL_CFG 0x1C // This register is used to trigger accelerometer self-test and configure the gyroscopes’ full scale range.

/* FEATURE REG */
#define REG_MOT_THR 0x1F // This register configures the detection threshold for Motion interrupt generation
#define REG_FIFO_EN 0x23 // This register determines which sensor measurements are loaded into the FIFO buffer.

/* I2C settings */
#define REG_MST_CTRL 0x24      // Dont care
#define REG_I2C_SLV0_ADDR 0x25 // Dont care
#define REG_I2C_SLV0_REG 0x26  // Dont care
#define REG_I2C_SLV0_CTRL 0x27 // Dont care
#define REG_I2C_SLV1_ADDR 0x28 // Dont care
#define REG_I2C_SLV1_REG 0x29  // Dont care
#define REG_I2C_SLV1_CTRL 0x2A // Dont care
#define REG_I2C_SLV2_ADDR 0x2B // Dont care
#define REG_I2C_SLV2_REG 0x2C  // Dont care
#define REG_I2C_SLV2_CTRL 0x2D // Dont care
#define REG_I2C_SLV3_ADDR 0x2E // Dont care
#define REG_I2C_SLV3_REG 0x2F  // Dont care
#define REG_I2C_SLV3_CTRL 0x30 // Dont care
#define REG_I2C_SLV4_ADDR 0x31 // Dont care
#define REG_I2C_SLV4_REG 0x32  // Dont care
#define REG_I2C_SLV4_DO 0x33   // Dont care
#define REG_I2C_SLV4_CTRL 0x34 // Dont care
#define REG_I2C_SLV4_DI 0x35   // Dont care
#define REG_I2C_MST_STS 0x36

/* INTERRUPT SETTINGS */
#define REG_INT_PIN_CFG 0x37 // This register configures the behavior of the interrupt signals at the INT pins.
#define REG_INT_EN 0x38      // This register enables interrupt generation by interrupt sources.
#define REG_INT_STS 0x39     // This register shows the interrupt status of each interrupt generation source

/* ACCEL, GYRO, TEMP DATA */
#define REG_ACCEL_XOUT_MSB 0x3B
#define REG_ACCEL_XOUT_LSB 0x3C
#define REG_ACCEL_YOUT_MSB 0x3D
#define REG_ACCEL_YOUT_LSB 0x3E
#define REG_ACCEL_ZOUT_MSB 0x3F
#define REG_ACCEL_ZOUT_LSB 0x40

#define REG_TEMP_MSB 0x41
#define REG_TEMP_LSB 0x42

#define REG_PWR_MGMT_1 0x6B
#define REG_PWR_MGMT_2 0x69

/* */
#define REG_WHO_AM_I 0x75       // This register is used to verify the identity of the device
#define REG_WHO_AMW_I_DEFV 0x68 // Default value for REG_WHO_AM_I

#endif // MPU6050_REGISTERS_H