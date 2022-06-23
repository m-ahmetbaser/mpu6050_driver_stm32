/*
 * MPU6050.c
 *
 *  Created on: May 24, 2022
 *      Author: baser
 */
#include "MPU6050.h"

extern I2C_HandleTypeDef hi2c1;

sensor_status_enum MPU6050_TestSensor(I2C_HandleTypeDef i2c)
{
	HAL_StatusTypeDef sensorStatus;
	sensorStatus  = HAL_I2C_IsDeviceReady(&i2c, (MPU6050_I2C_ADRESS_AD0 << 1), 4, 100);
	if(sensorStatus == HAL_OK)
	{
		return SENSOR_OK;
	}
	else
	{
		return SENSOR_ERROR;
	}


}

uint8_t MPU6050_ReadID(I2C_HandleTypeDef i2c, uint8_t devAdress, uint8_t memAdress)
{
	uint8_t id_val;

	HAL_I2C_Mem_Read(&i2c, (devAdress << 1), memAdress, 1, &id_val, 1, 100);

	if(id_val == devAdress)
	{
		return id_val;
	}
	else {
		return SENSOR_ERROR;
	}
}


uint8_t sensor_read_reg_u8(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress) // chipadress : ad0 or ad1
{
	uint8_t data;
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Read(&i2c, (chipAdress << 1), regAddress, 1, &data, 1, 100);

	if(HAL_OK != status)
	{
		return SENSOR_ERROR;
	}
	else
	{
		return data;
	}

}
uint8_t sensor_read_reg_u16(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress)
{
	uint8_t data[2];
	HAL_StatusTypeDef status;
	uint16_t returnVal;

	status = HAL_I2C_Mem_Read(&i2c, (chipAdress << 1), regAddress, 1, data, 2, 100);

	if(HAL_OK != status)
	{
		return SENSOR_ERROR;
	}
	else
	{
		returnVal = data[0] | (data[1]<<8);
		return returnVal;
	}
}
sensor_status_enum sensor_write_reg_u8(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress, uint8_t value)
{
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Write(&i2c, chipAdress << 1, regAddress, 1, &value , 1, 100);

	if(HAL_OK != status)
	{
		return SENSOR_ERROR;
	}
	else
	{
		return SENSOR_OK;
	}
}
sensor_status_enum sensor_write_reg_u16(I2C_HandleTypeDef i2c, uint8_t chipAdress, uint8_t regAddress, uint16_t value)
{
	HAL_StatusTypeDef status;
	uint8_t data[2];

	data[0] = value & 0xFF ;
	data[1] = (value >> 8) & 0xFF;

	status = HAL_I2C_Mem_Write(&i2c, chipAdress << 1, regAddress, 1, data , 1, 100);

	if(HAL_OK != status)
	{
		return SENSOR_ERROR;
	}
	else
	{
		return SENSOR_OK;
	}
}

