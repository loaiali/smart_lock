#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include"STD_TYPES.h"



typedef struct{
	u8 portControl;
	u8 RS_pin;
	u8 E_pin;
}LCD_control_T;
typedef struct{
	u8 data_port;
	LCD_control_T LCD_control;

}LCD_CFG_T;


/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(LCD_CFG_T LCD_CFG);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(LCD_CFG_T LCD_CFG,u8 u8CmdCpy);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(LCD_CFG_T LCD_CFG,u8 u8DataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (LCD_CFG_T LCD_CFG,u8* pu8StringCpy);


void Gotoxy (LCD_CFG_T LCD_CFG,u8 Y,u8 X);
void LCD_vidWriteExtraChar (u8 Y,u8 X);
void LCD_ShiftDisplayRight(LCD_CFG_T LCD_CFG);
void LCD_ShiftDisplayLeft(LCD_CFG_T LCD_CFG);
void LCD_ClearDisplay(LCD_CFG_T LCD_CFG);
#endif /* HAL_LCD_LCD_H_ */