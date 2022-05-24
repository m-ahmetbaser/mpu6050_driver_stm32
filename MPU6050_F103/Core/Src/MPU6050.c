/*
 * MPU6050.c
 *
 *  Created on: May 24, 2022
 *      Author: baser
 */
#include "MPU6050.h"

extern I2C_HandleTypeDef hi2c1;

void MPU6050_TestSensor(I2C_HandleTypeDef i2c)
{
	HAL_StatusTypeDef sensorStatus;
	sensorStatus  = HAL_I2C_IsDeviceReady(&i2c, (MPU6050_ID << 1), 4, 100);
	if(sensorStatus == HAL_OK)
	{
		sensor_datas.sensor_flag = 1;
	}
	else
	{
		sensor_datas.sensor_flag = 0;
	}


}


