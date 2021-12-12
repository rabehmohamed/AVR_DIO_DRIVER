/*
 * KeyPad.c
 *
 * Created: 10/19/2021 3:50:02 PM
 *  Author: Mohamed Magdi
 */ 
#include "KeyPad.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"

// keypad on port PB4 -> PB7 , PC3 -> PC6
void KeyPad_Init (void)
{
	Dio_GroupSetDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0xFF); //Rows are output
	Dio_GroupSetDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0x00); // Columns are input 
	Dio_GroupPullupState(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0xF0);
	Dio_GroupWrite(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0x00);
}
ReturnValueType KeyPad_GetNumber (uint8 * Number)
{
	uint8 SegementValue = 0xFF ; 
	uint8 KeyPadValue = 0x00 ;
	Dio_GroupRead(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,&SegementValue);
	if (SegementValue == 0xF0) return NOK ;
	_delay_ms(100);
	KeyPadValue = SegementValue ;
	Dio_GroupFlipDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);
	Dio_GroupFlipDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);
	Dio_GroupPullupStateFlip(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);
	Dio_GroupWrite(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0x00);
	Dio_GroupRead(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,&SegementValue);
		SegementValue = SegementValue >> 3; // PC3 -> PC0
	_delay_ms(100);
	KeyPadValue |= SegementValue ;	
	switch(KeyPadValue)
	{
		case 0xee:*Number = '1' ; break; 
		case 0xde:*Number = '2' ; break;
		case 0xbe:*Number = '3' ; break;
		case 0x7e:*Number = 'A' ; break;
		case 0xed:*Number = '4' ; break;
		case 0xdd:*Number = '5' ; break;
		case 0xbd:*Number = '6' ; break;
		case 0x7d:*Number = 'B' ;break;
		case 0xeb:*Number = '7' ; break;
		case 0xdb:*Number = '8' ; break;
		case 0xbb:*Number = '9' ; break;
		case 0x7b:*Number = 'C' ;break;
		case 0xe7:*Number = 'E' ;break;
		case 0xd7:*Number = '0' ;break;
		case 0xb7:*Number = 'F' ;break;
		case 0x77:*Number = 'D' ;break;
		default:
			 break;
				
	}
	_delay_ms(50);
	Dio_GroupFlipDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);
	Dio_GroupFlipDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);
	Dio_GroupPullupStateFlip(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);
	Dio_GroupWrite(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0x00);
	return OK;
}