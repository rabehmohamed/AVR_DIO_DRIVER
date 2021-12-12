/*
 * EEPROM.h
 *
 * Created: 11/26/2021 9:08:15 AM
 *  Author: rabeh
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_Types.h"
#include "Bitwise.h"
ReturnValueType Write_Data(uint16 Address,uint8 Data);
ReturnValueType Read_Data(uint16 Address,uint8 *Read);





#endif /* EEPROM_H_ */