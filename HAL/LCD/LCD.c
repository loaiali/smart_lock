#include"LCD.h"
#include"DIO.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define lcd_shiftDisplayLeft 0x04       //shift the display one step to the left
#define lcd_shiftDisplayRight 0x1C       //shift the display one step to the right


void LCD_vidInit(LCD_CFG_T LCD_CFG){


		/* Delay 30ms to ensure the initialization of the LCD driver */
		_delay_ms(30);



		DIO_SetPortDirection(LCD_CFG.data_port, 0xFF);
		DIO_SetPinDirection(LCD_CFG.LCD_control.portControl,
				LCD_CFG.LCD_control.RS_pin, OUTPUT);
			DIO_SetPinDirection(LCD_CFG.LCD_control.portControl,
					LCD_CFG.LCD_control.E_pin, OUTPUT);

		/* Return Home  */
		LCD_vidSendCommand(LCD_CFG,lcd_Home);
		_delay_ms(15);

		/* Function Set  */
		LCD_vidSendCommand(LCD_CFG,lcd_FunctionSet8bit);
		_delay_ms(1);

		/* Display ON OFF Control */
		LCD_vidSendCommand(LCD_CFG,lcd_DisplayOn);
		_delay_ms(1);

		/* Clear Display */
		LCD_vidSendCommand(LCD_CFG,lcd_Clear);
		_delay_ms(15);

		/* Entry Mode Set  */
		LCD_vidSendCommand(LCD_CFG,	lcd_EntryMode);
		_delay_ms(2);

}
void LCD_vidSendCommand(LCD_CFG_T LCD_CFG,u8 u8CmdCpy){
	/* Set RS to LOW */
		DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.RS_pin, LOW);

		/* Set R/W to LOW */
		//DIO_SetPinValue(PORTA, 1, LOW);

		/* Set E to HIGH  */
		DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, HIGH);

		/* Load Command on Data bus */
		DIO_SetPortValue(LCD_CFG.data_port, u8CmdCpy);

		/* Set E to LOW */
		DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, LOW);

		/* Wait for E to settle */
		_delay_ms(5);

		/* Set E to HIGH */
		DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, HIGH);

		/* Delay for 10ms to let the LCD execute command */
		_delay_ms(10);

}
void LCD_vidWriteCharctr(LCD_CFG_T LCD_CFG,u8 u8DataCpy){
			/* Set RS to HIGH */
			DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.RS_pin, HIGH);

			/* Set R/W to LOW */
			//DIO_SetPinValue(PORTA, 1, LOW);

			/* Set E to HIGH  */
			DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, HIGH);

			/* Load Command on Data bus */
			DIO_SetPortValue(LCD_CFG.data_port, u8DataCpy);

			/* Set E to LOW */
			DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, LOW);

			/* Wait for E to settle */
			_delay_ms(5);

			/* Set E to HIGH */
			DIO_SetPinValue(LCD_CFG.LCD_control.portControl, LCD_CFG.LCD_control.E_pin, HIGH);

			/* Delay for 10ms to let the LCD execute command */
			_delay_ms(10);
}
void LCD_vidWriteString (LCD_CFG_T LCD_CFG,u8* pu8StringCpy){
	int loopIndex=0;
	while(pu8StringCpy[loopIndex]!='\0'){
		LCD_vidWriteCharctr(LCD_CFG,pu8StringCpy[loopIndex]);
		loopIndex++;
		_delay_ms(2);
	}
}
void Gotoxy (LCD_CFG_T LCD_CFG,u8 Y,u8 X){
	if (X>=0 && X<16)
		{
		    switch(Y)
		    {
			    case 0:
			    	LCD_vidSendCommand(LCD_CFG,X|0x80);
			    	break;
			    case 1:
			    	LCD_vidSendCommand(LCD_CFG,(X+0x40)|0x80);
			    	break;
			    default:
			    	break;
		    }
		}
}
void LCD_ShiftDisplayRight(LCD_CFG_T LCD_CFG)
{
	LCD_vidSendCommand(LCD_CFG,lcd_shiftDisplayRight);
}
void LCD_ShiftDisplayLeft(LCD_CFG_T LCD_CFG)
{
	LCD_vidSendCommand(LCD_CFG,lcd_shiftDisplayLeft);
}
void LCD_ClearDisplay(LCD_CFG_T LCD_CFG){
	LCD_vidSendCommand(LCD_CFG,lcd_Clear);
}
