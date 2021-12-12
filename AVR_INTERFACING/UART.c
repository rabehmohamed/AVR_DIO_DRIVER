/*
 * UART.c
 *
 * Created: 11/11/2021 3:52:38 PM
 *  Author: Mohamed Magdi
 */ 
#include "Dio.h"
#include "UART.h"
#include <avr/io.h>
ReturnValueType UART_Init(void)
{
	
	UBRRL = CalculatedBaudRate;
	SetBit(UCSRB,RXEN); // RECIEVER ENABLE	
	SetBit(UCSRB,TXEN); // TRANSMITTER ENABLE
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); // 1:REGISTER SELECT(UCSRC) * 2+3: SET NUMBER OF BITS RECIEVED AND TRANSMITTED *9-bits*
	return OK;
}
ReturnValueType UART_SendChar(uint8 U8Data)
{	ReturnValueType ReturnValue = NOK;
	if (GetBit(UCSRA,UDRE)) // UDRE=1 THEN BUFFER IS EMPTY AND READY TO RECIEVE 
	{
		UDR = U8Data;
		ReturnValue = OK;
	}
	else
	{
		ReturnValue = NOK;
	}
	return ReturnValue;
}
ReturnValueType UART_SendString(uint8* U8Data)
{
	ReturnValueType ReturnValue = OK;
	while(*U8Data)
	{
		ReturnValue = UART_SendChar(*U8Data++);
		if (ReturnValue == NOK) break;
	}
	return ReturnValue;
}
ReturnValueType UART_Receive(uint8* U8Data)
{
	ReturnValueType ReturnValue = NOK;
	if (GetBit(UCSRA,RXC))
	{
		*U8Data = UDR ;
		ReturnValue = OK;
	}
	else
	{
		ReturnValue = NOK;
	}
	return ReturnValue;
}