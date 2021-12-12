/*
 * StringHandler.h
 *
 * Created: 10/21/2021 11:29:30 AM
 *  Author: Mohamed Magdi
 */ 


#ifndef STRINGHANDLER_H_
#define STRINGHANDLER_H_
#include "STD_Types.h"

ReturnValueType HEX2String (uint8 HEX,uint8 string[3]);
ReturnValueType Decimal2String (uint8 Decimal,uint8 string[4]);

#endif /* STRINGHANDLER_H_ */