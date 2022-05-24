/*
 * MPU6050.c
 *
 *  Created on: May 24, 2022
 *      Author: baser
 */
#include "MPU6050.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t MPU6050_TestSensor(I2C_HandleTypeDef i2c)
{
	HAL_StatusTypeDef sensorStatus;
	sensorStatus  = HAL_I2C_IsDeviceReady(&i2c, (MPU6050_ID << 1), 4, 100);
	if(sensorStatus == HAL_OK)
	{
		sensor_flags.flags.sensor_flag = 1;
		return HAL_OK;
	}
	else
	{
		sensor_flags.flags.sensor_flag = 0;
		return HAL_ERROR;
	}


}

uint8_t MPU6050_ReadID(I2C_HandleTypeDef i2c, uint8_t devAdress, uint8_t memAdress)
{
	uint8_t id_val;

	HAL_I2C_Mem_Read(&i2c, (devAdress << 1), memAdress, 1, &id_val, 1, 100);

	if(id_val == devAdress)
	{
		sensor_flags.flags.who_am_I_flag = 1;
		return HAL_OK;
	}
	else {
		sensor_flags.flags.who_am_I_flag = 0;
		return HAL_ERROR;
	}
}
