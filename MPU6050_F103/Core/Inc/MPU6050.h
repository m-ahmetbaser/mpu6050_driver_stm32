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
#define MPU6050_ID  0x68




// DEFINES

typedef struct
{
	uint8_t sensor_flag;
}MPU6050_datas;
MPU6050_datas sensor_datas;


// FUNCTION PROTOTYPES
void MPU6050_TestSensor(I2C_HandleTypeDef i2c);


#endif /* INC_MPU6050_H_ */
