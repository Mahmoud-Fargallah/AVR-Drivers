/*
 * UART_INIT.h
 *
 *  Created on: Apr 21, 2020
 *      Author: FARAG
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_

 Error_enuStatus UART_enuInitializeUART(void);

 Error_enuStatus UART_enuTransmit(u8 Copy_u8Data);

 u8 UART_u8Recieve(void);
 Error_enuStatus UART_TxString(u8* StringPtr);

#endif /* UART_INIT_H_ */
