/*
 * EEPROM.c
 *
 * Created: 11/26/2021 9:14:24 AM
 *  Author: rabeh
 */ 

#include "STD_Types.h"
#include "Bitwise.h"
#include "EEPROM.h"
#include <avr/io.h>

ReturnValueType Write_Data(uint16 Address,uint8 Data){
	while(GetBit(EECR,EEWE)); // CHECK IF ITS DONE WRITING
	EEAR=Address;
	EEDR=Data;
	SetBit(EECR,EEMWE);// ENABLE MASTER
	SetBit(EECR,EEWE);// ENABLE WRITE BIT
}

ReturnValueType Read_Data(uint16 Address,uint8 *Read){
	while(GetBit(EECR,EEWE));
	EEAR=Address;
	SetBit(EECR,EERE);// ENABLE READ BIT
	*Read=EEDR;
}
