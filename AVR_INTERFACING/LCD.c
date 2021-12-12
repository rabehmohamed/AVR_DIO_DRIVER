/*
 * LCD.c
 *
 * Created: 10/16/2021 12:15:29 PM
 *  Author: Mohamed Magdi
 */ 
#include "LCD.h"
void LCD_Init(void)
{
	Dio_GroupSetDirection(LCDC_Port,LCDC_Mask,LCDC_Mask); 
	Dio_GroupSetDirection(LCDD_Port,LCD_Mask,LCD_Mask);
	LCD_Command(LCD_4BitMode1);
	LCD_Command(LCD_4BitMode2);
	LCD_Command(LCD_2Lines5X8_4BitMode);
	LCD_Command(DisplayOnCursorOff); 
	LCD_Command(ShiftCursorRight); 
	LCD_Command(ClearDispaly); 
	}
void LCD_Command(uint8 command)
{
	uint8 PortValue = 0;
	Dio_PinWrite(LCDC_Port,LCD_RS,PinLow);
	//Dio_PortRead(LCDD_Port,&PortValue); // issue read from pin reg
	uint8 SendValue = (command & LCD_Mask) | (PORTA & ~LCD_Mask); 
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable();
	//Dio_PortRead(LCDD_Port,&PortValue);
	SendValue = (command<<LCD_Align ) |  (PORTA & ~LCD_Mask);
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable(); 
}
void LCD_Data(uint8 Data)
{
	uint8 PortValue = 0 ;
	Dio_PinWrite(LCDC_Port,LCD_RS,PinHigh);
	Dio_PortRead(LCDD_Port,&PortValue);
	uint8 SendValue = (Data & LCD_Mask) | (PortValue & ~LCD_Mask);
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable();
	Dio_PortRead(LCDD_Port,&PortValue);
	SendValue = (Data<<LCD_Align ) |  (PortValue & ~LCD_Mask);
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable();
}	
void LCD_Enable(void)
{
	Dio_PinWrite(LCDC_Port,LCD_E,PinHigh);
	_delay_ms(10);
	Dio_PinWrite(LCDC_Port,LCD_E,PinLow);
}
void LCD_DataString(uint8* DataString)
{
	while (*DataString)
	{
		LCD_Data(*DataString++);
	}
}
void LCD_Postion(uint8 Row , uint8 Column )
{
	// Row 1 starts from 0x80 through 0x8f
	// Row 2 starts from 0xC0 through 0xCf
	
	uint8 Position = 0;
	
	switch (Row)
	{
		case 0x01:
		Position = 0x80+ Column-1 ;
		break;
		case 0x02:
		Position = 0xC0+ Column-1 ;
		break;
		default:
		Position = 0x80 ;
		break;
	}
	LCD_Command(Position);

}