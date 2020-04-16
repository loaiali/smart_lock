
#include"DIO.h"
#include"DIO_REG.h"

#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy){
	switch(u8PortIdCopy){
	case PORTA:
		return GET_BIT(PINA_Register,u8PinIdCopy);
		break;
	case PORTB:
		return GET_BIT(PINB_Register,u8PinIdCopy);
		break;
	case PORTC:
		return GET_BIT(PINC_Register,u8PinIdCopy);
		break;
	case PORTD:
		return GET_BIT(PIND_Register,u8PinIdCopy);
		break;
	default:
		return 0;
		break;

	}
}

void DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy){
	if(u8PinValCopy==HIGH){
		switch(u8PortIdCopy){
			case PORTA:
				SET_BIT(PORTA_Register,u8PinIdCopy);
				break;
			case PORTB:
				SET_BIT(PORTB_Register,u8PinIdCopy);
				break;
			case PORTC:
				SET_BIT(PORTC_Register,u8PinIdCopy);
				break;
			case PORTD:
				SET_BIT(PORTD_Register,u8PinIdCopy);
				break;
			default:
				break;
		}
	}
	else if (u8PinValCopy==LOW){
		switch(u8PortIdCopy){
					case PORTA:
						CLR_BIT(PORTA_Register,u8PinIdCopy);
						break;
					case PORTB:
						CLR_BIT(PORTB_Register,u8PinIdCopy);
						break;
					case PORTC:
						CLR_BIT(PORTC_Register,u8PinIdCopy);
						break;
					case PORTD:
						CLR_BIT(PORTD_Register,u8PinIdCopy);
						break;
					default:
							break;
				}
	}
}
void DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy){
	if(u8PinDirCopy==HIGH){
			switch(u8PortIdCopy){
				case PORTA:
					SET_BIT(DDRA_Register,u8PinIdCopy);
					break;
				case PORTB:
					SET_BIT(DDRB_Register,u8PinIdCopy);
					break;
				case PORTC:
					SET_BIT(DDRC_Register,u8PinIdCopy);
					break;
				case PORTD:
					SET_BIT(DDRD_Register,u8PinIdCopy);
					break;
				default:
					break;
			}
		}
		else if (u8PinDirCopy==LOW){
			switch(u8PortIdCopy){
						case PORTA:
							CLR_BIT(DDRA_Register,u8PinIdCopy);
							break;
						case PORTB:
							CLR_BIT(DDRB_Register,u8PinIdCopy);
							break;
						case PORTC:
							CLR_BIT(DDRC_Register,u8PinIdCopy);
							break;
						case PORTD:
							CLR_BIT(DDRD_Register,u8PinIdCopy);
							break;
						default:
								break;
					}
		}

}
void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir){
	switch (u8PortId){
		case PORTA:
			DDRA_Register=u8PortDir;
			break;
		case PORTB:
            DDRB_Register=u8PortDir;
            break;
		case PORTC:
            DDRC_Register=u8PortDir;
            break;
		case PORTD:
            DDRD_Register=u8PortDir;
            break;

	}
}
u8 DIO_GetPortValue(u8 u8PortId){
	switch(u8PortId){
	case PORTA:
		return PORTA_Register;
		break;
	case PORTB:
		return PORTB_Register;
		break;
	case PORTC:
		return PORTC_Register;
		break;
	case PORTD:
		return PORTD_Register;
		break;
	default:
		return 0;
		break;
	}
}
void DIO_SetPortValue(u8 u8PortId, u8 u8PortVal){
	switch(u8PortId){
	case PORTA:
		PORTA_Register=u8PortVal;
		break;
	case PORTB:
        PORTB_Register=u8PortVal;
        break;
	case PORTC:
        PORTC_Register=u8PortVal;
        break;
	case PORTD:
        PORTD_Register=u8PortVal;
        break;
	}
}

