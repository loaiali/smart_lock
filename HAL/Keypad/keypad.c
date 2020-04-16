#include"BIT_MATH.h"
#include "DIO.h"
#include "keypad.h"

#define ROWS 4
#define COLS 4



const u8 KPD_au8SwitchVal[ROWS][COLS] =
{
  {1,2,3,4 },
  {4,5,6,4 },
  {7,8,9,4 },
  {4,0,4,4 }
};

u8 KEYPAD_getButton(keypad_config_T keypad_config){
	u8 col,row;
	while(1){
		for(row=0;row<keypad_config.N_ROW;row++){
			DIO_SetPortDirection(keypad_config.PORTId,0b00010000<<row);
			DIO_SetPortValue(keypad_config.PORTId,~(0b00010000<<row));
			for(col=0;col<keypad_config.N_COLS;col++){
				if(!DIO_GetPinValue(keypad_config.PORTId,col)){
					return KPD_au8SwitchVal[row][col];
				}
			}
		}
	}
}