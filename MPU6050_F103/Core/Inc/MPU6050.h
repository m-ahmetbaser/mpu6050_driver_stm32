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




// DEFINES
typedef union{
	struct
	{
		uint8_t sensor_flag   :1;
		uint8_t who_am_I_flag :1;
		uint8_t reserved      :6;
	}flags;
	uint8_t sensor_flags;

}MPU6050_Flags;
MPU6050_Flags sensor_flags;

typedef struct
{

}MPU6050_datas;
MPU6050_datas sensor_datas;


// FUNCTION PROTOTYPES
uint8_t MPU6050_TestSensor(I2C_HandleTypeDef i2c);
uint8_t MPU6050_ReadID(I2C_HandleTypeDef i2c, uint8_t devAdress, uint8_t memAdress);


#endif /* INC_MPU6050_H_ */
