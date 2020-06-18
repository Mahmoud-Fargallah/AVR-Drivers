/*
 * UART_PRIV.h
 *
 *  Created on: Apr 21, 2020
 *      Author: FARAG
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define    UDR    (*(volatile u8 *)(0x2C))
#define    UCSRA  (*(volatile u8 *)(0x2B))
#define    UCSRB  (*(volatile u8 *)(0x2A))
#define    UCSRC  (*(volatile u8 *)(0x40))
#define    UBRRL  (*(volatile u8 *)(0x29))
#define    UBRRH  (*(volatile u8 *)(0x40))


/*UCSRA Register*/
#define    RXC                 7
#define    TXC                 6
#define    UDRE                5
#define    FE                  4
#define    DOR                 3
#define    PE                  2
#define    U2x                 1
#define    MPCM                0

/*UCSRB Register*/
#define    RXCIE               7
#define    TXCIE               6
#define    UDRIE               5
#define    RXEN                4
#define    TXEN                3
#define    UCSZ2               2
#define    RXB8                1
#define    TXB8                0

/*UCSRC Register*/
#define    URSEL               7
#define    UMSEL               6
#define    UPM1                5
#define    UPM0                4
#define    USBS                3
#define    UCSZ1               2
#define    UCSZ0               1
#define    UCPOL               0


#define    DISABLED            0
#define    ENABLED             1

#define    ASYNCHRONOUS        0
#define    SYNCHRONOUS         1

#define    EVEN_PARITY         2
#define    ODD_PARITY          3

#define    _One_STOP_BIT          0
#define    _Tow_STOP_BIT          1

#define    UART_5_BITS              0
#define    UART_6_BITS              1
#define    UART_7_BITS              2
#define    UART_8_BITS              3
#define    UART_9_BITS              7




#endif /* UART_PRIV_H_ */
