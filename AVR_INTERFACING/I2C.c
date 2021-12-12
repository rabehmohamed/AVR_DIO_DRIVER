/*
 * I2C.c
 *
 * Created: 11/19/2021 2:08:21 PM
 *  Author: Mohamed Magdi
 */ 
#include <avr/io.h>
#include "STD_Types.h"
#include "Bitwise.h"
void I2C_Init(void)
{
	TWSR = 0x00 ;
	TWBR = 12;
	TWCR = (1<<TWEN) ;
}
void I2C_Start(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTA) ;
	while(!GetBit(TWCR,TWINT)) ;
}

void I2C_Stop(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWSTO) ;
}
void I2C_Write(uint8 u8Write)
{
	TWDR = u8Write ; 
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!GetBit(TWCR,TWINT)) ;
}
void I2C_Read(uint8 * U8Read)
{
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(!GetBit(TWCR,TWINT)) ;
	*U8Read = TWDR ;
}
