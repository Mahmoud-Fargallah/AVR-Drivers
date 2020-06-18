

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "REG.h"
#include "ErrorStatus.h"
#include "LED.h"



Error_enuStatus    LED_enuSetLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID)
{
	Error_enuStatus error = ES_NOK;

	 DIO_enuSetPinDirection( Copy_u8PORTID, Copy_u8PINID, OUTPUT);
           error = ES_OK ;
           return error;
}
Error_enuStatus    LED_enuOnLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID)
{
	Error_enuStatus error = ES_NOK;
	if( ( Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
	{
		switch(Copy_u8PORTID)
		{
		case PORTA: SET_BIT(DIO_PU8_PORTA, Copy_u8PINID); break;   /* <      *       *       *        > */
		case PORTB: SET_BIT(DIO_PU8_PORTB, Copy_u8PINID); break;   /*         Set Bin As HIGH           */
		case PORTC: SET_BIT(DIO_PU8_PORTC, Copy_u8PINID); break;   /*                                   */
		case PORTD: SET_BIT(DIO_PU8_PORTD, Copy_u8PINID); break;   /* <      *       *       *        > */
		}
        error = ES_OK ;

	}

	           return error;
}


Error_enuStatus    LED_enuOffLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID)
{
	Error_enuStatus error = ES_NOK;

	if( ( Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
	{

		switch(Copy_u8PORTID)
		{
		case PORTA: CLEAR_BIT(DIO_PU8_PORTA, Copy_u8PINID); break;  /* <      *       *       *        > */
		case PORTB: CLEAR_BIT(DIO_PU8_PORTB, Copy_u8PINID); break;  /*         Set Bin As LOW            */
		case PORTC: CLEAR_BIT(DIO_PU8_PORTC, Copy_u8PINID); break;  /*                                   */
		case PORTD: CLEAR_BIT(DIO_PU8_PORTD, Copy_u8PINID); break;  /* <      *       *       *        > */
		}
		 error = ES_OK ;
	}
       return error;

}
Error_enuStatus    LED_enuTogLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID)
{
	Error_enuStatus error = ES_NOK;

		if( ( Copy_u8PORTID < 4 )&&( Copy_u8PINID < 8 ) )
		{

			switch(Copy_u8PORTID)
		   {
			case PORTA: TOG_BIT(DIO_PU8_PORTA, Copy_u8PINID); break;  /* <      *       *       *        > */
			case PORTB: TOG_BIT(DIO_PU8_PORTB, Copy_u8PINID); break;  /*        Change Led Status          */
			case PORTC: TOG_BIT(DIO_PU8_PORTC, Copy_u8PINID); break;  /*                                   */
			case PORTD: TOG_BIT(DIO_PU8_PORTD, Copy_u8PINID); break;  /* <      *       *       *        > */
			}
			 error = ES_OK ;
		}
	       return error;
}
