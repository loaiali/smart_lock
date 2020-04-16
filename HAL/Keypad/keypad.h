#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include"STD_TYPES.h"

typedef struct {
	u8 PORTId;
	u8 N_COLS;
	u8 N_ROW;

}keypad_config_T;



/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/


u8 KEYPAD_getButton(keypad_config_T keypad_config );


#endif /* HAL_KEYPAD_KEYPAD_H_ */