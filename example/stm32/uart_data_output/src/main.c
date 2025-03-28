
#include "main.h"
#include "hal_i2c.h"
#include "hal_uart.h"
#include "hal_gpio.h"
#include "board_config.h"
#include "syscfg.h"
#include "mpu6050.h"

/* Init MPU6050 for STM32 mcu related */
void mpu6050_com_init(void)
{
  mpu6050_i2c_ops_t ops = {
      .i2c_write = stm32_i2c_write_reg,
      .i2c_read = stm32_i2c_read_reg};
  mpu6050_set_i2c_spec(&ops);
}

static void peripheral_init(void)
{
  /* STM32 related */
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();

  /* Application related*/
  mpu6050_com_init();
  mpu6050_init_reg();
  mpu6050_cfg_pwr_mng(0x00);
}

int main(void)
{
  peripheral_init();

  int err;
  mpu_cfg_t mpu_cfg;
  mpu_rawdata_t r_data;
  mpu_data_t data;

  uint8_t uart_data[7];
  while (1)
  {

    HAL_GPIO_WritePin(BUILTIN_LED_PORT, BUILTIN_LED_PIN, GPIO_PIN_RESET);
    mpu6050_get_accel_raw(&r_data);
    mpu6050_get_gyro_raw(&r_data);
    mpu6050_get_temp_raw(&r_data);
    mpu6050_raw_data_to_readable_data(&data, &r_data);

    uart_data[0] = (uint8_t)(data.accel.x * 100);
    uart_data[1] = (uint8_t)(data.accel.y * 100);
    uart_data[2] = (uint8_t)(data.accel.z * 100);
    uart_data[3] = (uint8_t)(data.gyro.x * 100);
    uart_data[4] = (uint8_t)(data.gyro.y * 100);
    uart_data[5] = (uint8_t)(data.gyro.z * 100);
    uart_data[6] = (uint8_t)(data.tempt);

    uart_send(uart_data, 7);
    HAL_GPIO_WritePin(BUILTIN_LED_PORT, BUILTIN_LED_PIN, GPIO_PIN_SET);
    HAL_Delay(1000); // sampling rate is 94Hz, so make it > 10ms
  }
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
    ;
}