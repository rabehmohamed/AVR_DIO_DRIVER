/*
 * LCD.h
 *
 * Created: 10/16/2021 12:15:46 PM
 *  Author: Mohamed Magdi
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
#include "Dio.h"
#include <avr/io.h>
#include <util/delay.h>
#define LCDC_Port B
#define LCD_RS 1
#define LCD_RW 2
#define LCD_E 3
#define LCDC_Mask 0x0E

#define LCDD_Port A
#define LCD_Mask 0xF0
#define LCD_Align 4

#define LCD_4BitMode1 0x33
#define LCD_4BitMode2 0x32
#define LCD_2Lines5X8_4BitMode 0x28
#define DisplayOnCursorOff 0x0C
#define ShiftCursorRight 0x06
#define ClearDispaly 0x01

void LCD_Init(void);
void LCD_Command(uint8 command);
void LCD_Data(uint8 Data);
void LCD_Enable(void);
void LCD_DataString(uint8* DataString);
void LCD_Postion(uint8 Row , uint8 Column );
#endif /* LCD_H_ */