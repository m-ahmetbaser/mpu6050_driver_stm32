/*
 * MPU6050.h
 *
 *  Created on: May 24, 2022
 *      Author: baser
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stdint.h"
#include "main.h"


// MACROS
#define MPU6050_ID  0x68 // AD0 bacagi low da ise --> 1101 0000 olmalı id
#define WHO_AM_I_Memory_Adress  0x75
// 0x68 << 1 yaptigimizda 1101 0000 elde ederiz

#define MPU6050_I2C_ADRESS_AD0 ( 0x68 )
#define MPU6050_I2C_ADRESS_AD1 ( 0x69 )

#define MPU_REG_SELF_TEST_X	( 13 )
#define MPU_REG_SELF_TEST_Y	( 14 )
#define MPU_REG_SELF_TEST_Z	( 15 )
#define MPU_REG_SELF_TEST_A	( 16 )
#define MPU_REG_SMPLRT_DIV	( 25 )
#define MPU_REG_CONFIG	( 26 )
#define MPU_REG_GYRO_CONFIG	( 27 )
#define MPU_REG_ACCEL_CONFIG	( 28 )
#define MPU_REG_ACCEL_XOUT_H	( 59 )
#define MPU_REG_ACCEL_XOUT_L	( 60 )
#define MPU_REG_ACCEL_YOUT_H	( 61 )
#define MPU_REG_ACCEL_YOUT_L	( 62 )
#define MPU_REG_ACCEL_ZOUT_H	( 63 )
#define MPU_REG_ACCEL_ZOUT_L	( 64 )
#define MPU_REG_ACCEL_TEMP_OUT_H ( 65 )
#define MPU_REG_ACCEL_TEMP_OUT_L	( 66 )
#define MPU_REG_GYRO_XOUT_H	( 67 )
#define MPU_REG_GYRO_XOUT_L	( 68 )
#define MPU_REG_GYRO_YOUT_H	( 69 )
#define MPU_REG_GYRO_YOUT_L	( 70 )
#define MPU_REG_GYRO_ZOUT_H	( 71 )
#define MPU_REG_GYRO_ZOUT_L	( 72 )
#define MPU_REG_USER_CTRL	( 106)
#define MPU_REG_PWR_MGMT_1	( 107 )
#define MPU_REG_PWR_MGMT_2	( 108 )
#define MPU_REG_FIFO_COUNTH ( 114 )
#define MPU_REG_FIFO_COUNTL ( 115 )
#define MPU_REG_FIFO_R_W	( 116 )
#define MPU_REG_WHO_AM_I	( 117 )

#define MPU_BIT_PWR_MGMT_1_SLEEP_MODE ( 6 )
#define MPU_REG_GYRO_CONFIG_GYRO_RANGE_BITS_POSITION ( 3 )
#define MPU_REG_ACC_CONFIG_ACC_RANGE_BITS_POSITION ( 3 )

typedef enum
{
	FS_250,
	FS_500,
	FS_1000,
	FS_2000,
}fs_enum;

typedef enum
{
	AFS_2G,
	AFS_4G,
	AFS_8G,
	AFS_16G,
}afs_enum;

typedef enum
{
	SENSOR_OK,
	SENSOR_ERROR
}sensor_status_enum;

typedef struct
{
	int16_t X;
	int16_t Y;
	int16_t Z;
}axis_rawVal_st;

typedef struct
{
	double X;
	double Y;
	double Z;
}axis_val_st;

typedef struct
{
	axis_rawVal_st acc_raw;
	axis_rawVal_st gyro_raw;
	axis_val_st acc;
	axis_val_st gyro;
	double acc_coeff;
	double gyro_coeff;

}MPU6050_datas;

MPU6050_datas sensor_datas;

typedef enum
{
	SLEEP_MODE_ON,
	SLEEP_MODE_OFF
}sleep_mode_e;


// DEFINES




// FUNCTION PROTOTYPES
sensor_status_enum MPU6050_init(MPU6050_datas *pSensor, fs_enum gyro_cfg, afs_enum acc_cfg);
sensor_status_enum MPU6050_TestSensor(I2C_HandleTypeDef i2c);
uint8_t MPU6050_ReadID(I2C_HandleTypeDef i2c, uint8_t devAdress, uint8_t memAdress);
sensor_status_enum MPU6050_set_sleep_mode(sleep_mode_e sleep_mode);
sensor_status_enum MPU6050_read_data(MPU6050_datas *sensor_data);
uint8_t sensor_read_reg_u8(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress);
uint8_t sensor_read_reg_u16(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress);
sensor_status_enum sensor_write_reg_u8(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress, uint8_t value);
sensor_status_enum sensor_write_reg_u16(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress, uint16_t value);


#endif /* INC_MPU6050_H_ */
