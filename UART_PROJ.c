/*
 * UART_PROJ.c
 *
 *  Created on: Apr 21, 2020
 *      Author: FARAG
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ErrorStatus.h"
#include "UART_PRIV.h"
#include "UART_INIT.h"
#include "UART_CONFIG.h"


Error_enuStatus UART_enuInitializeUART(void)
{
	Error_enuStatus error = ES_NOK;

		/*Baud rate 9600   */
		  UBRRH = 0;
		  UBRRL = 51;

		  UCSRB =(1<<RXEN)|(1<<TXEN) ;
		  UCSRC =(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0) ;


	return error;

}


Error_enuStatus UART_Transmit( u8 Copy_u8Data )
{
	Error_enuStatus error = ES_NOK;

	while( GET_BIT(UCSRA,5) == 0 );

	UDR = Copy_u8Data;

	return error = ES_OK;
}

u8  UART_Receive()
{
	while( GET_BIT( UCSRA , 7 ) == 0 );

	return UDR;
}


void UART_TransmitString ( u8 *copy_Pu8Data )
{
    while( *copy_Pu8Data )
    {
        UART_Transmit( *copy_Pu8Data );
        copy_Pu8Data++;
    }
    //UART_Transmit( '\0' );
}

u8* UART_ReceiveString ( void )
{
    static u8 Local_Au8ReceivedData[30];

    for( u8 j = 0; j < 30; j++ )
    {
        Local_Au8ReceivedData[j] = '\0';
    }

    for( u8 i = 0; i < 30; i++ )
    {
        Local_Au8ReceivedData[i] = UART_Receive();

        if( Local_Au8ReceivedData[i] == '\r' )
        {
            break;
        }
    }
    return Local_Au8ReceivedData;
}
