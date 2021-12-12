/*
 * I2C.h
 *
 * Created: 11/19/2021 2:08:38 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "STD_Types.h"
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8 u8Write);
void I2C_Read(uint8 * URead);





#endif /* I2C_H_ */