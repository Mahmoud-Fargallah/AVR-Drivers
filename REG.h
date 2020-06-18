/********************************************************************************************/
/*************************    AUTHOR: Mahmoud Fargallah       *******************************/
/*************************    VERSION: 1ST                    *******************************/
/*************************    DATE:26/3/2020                  *******************************/
/*************************    DISCRIPTION:   DIO_INTERFACES_H *******************************/
/********************************************************************************************/




/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                                   GUARD                                                  */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
#ifndef     _DIO_REG_H_
#define     _DIO_REG_H_

/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                              PORTA REGISTERS                                             */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#define  DIO_PU8_PORTA      (*((volatile u8*) 0x3B))
#define  DIO_PU8_PINA       (*((volatile u8*) 0x39))
#define  DIO_PU8_DDRA       (*((volatile u8*) 0x3A))

/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                              PORTB REGISTERS                                             */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#define  DIO_PU8_PINB       (*((volatile u8*) 0x36))
#define  DIO_PU8_DDRB       (*((volatile u8*) 0x37))
#define  DIO_PU8_PORTB      (*((volatile u8*) 0x38))

/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                              PORTC REGISTERS                                             */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#define  DIO_PU8_PORTC      (*((volatile u8*) 0x35))
#define  DIO_PU8_PINC       (*((volatile u8*) 0x33))
#define  DIO_PU8_DDRC       (*((volatile u8*) 0x34))

/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/
/*                              PORTD REGISTERS                                             */
/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#define  DIO_PU8_PORTD      (*((volatile u8*) 0x32))
#define  DIO_PU8_PIND       (*((volatile u8*) 0x30))
#define  DIO_PU8_DDRD       (*((volatile u8*) 0x31))

/*<***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***><***>*/

#endif