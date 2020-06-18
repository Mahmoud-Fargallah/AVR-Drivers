/*
 * Timer0_reg.h
 *
 *  Created on: Apr 11, 2020
 *      Author: Khalid
 */

#ifndef HAL_TIMER0_REG_H_
#define HAL_TIMER0_REG_H_

/*************** Registers Addresses Definition *****************/

#define  TCCR0 	*((volatile u8*) 0x53 )
#define  TCNT0 	*((volatile u8*) 0x52 )
#define  OCR0	*((volatile u8*) 0x5C )
#define  TIMSK	*((volatile u8*) 0x59 )
#define  TIFR	*((volatile u8*) 0x58 )
#define  SREG   *((volatile u8*) 0x5F )

#endif /* HAL_TIMER0_REG_H_ */
