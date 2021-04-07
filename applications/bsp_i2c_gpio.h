
#ifndef __BSP_I2C_GPIO_H__
#define __BSP_I2C_GPIO_H__

#include <stdint.h>


#define I2C_WR 0
#define I2C_RD 1


void bsp_i2c_init(void);

void i2c_start(void);

void i2c_stop(void);


void i2c_send_byte(uint8_t _ucByte);

uint8_t i2c_read_byte(void);

uint8_t i2c_wait_ack(void);

void i2c_ack(void);

void i2c_nack(void);


uint8_t i2c_check_device(uint8_t _addr);

#endif // __BSP_I2C_GPIO_H__
