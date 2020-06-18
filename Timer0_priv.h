/*
 * Timer0_priv.h
 *
 *  Created on: Apr 10, 2020
 *      Author: Mahmoud Fargallah
 */

#ifndef HAL_TIMER0_PRIV_H_
#define HAL_TIMER0_PRIV_H_



/*************** Registers Bits Definition *****************/
/* Timer/Counter0 Control Register – TCCR0 */
#define  FOC0   7
#define  WGM00  6
#define  COM01  5
#define  COM00  4
#define  WGM01  3
#define  CS02   2
#define  CS01   1
#define  CS00   0

/* Timer/Counter Interrupt Mask Register – TIMSK */
#define  OCIE0  1
#define  TOIE0  0

/* Timer/Counter Interrupt Flag Register – TIFR */
#define  OCF0  1
#define  TOV0  0

/*************** Registers Initial Values *****************/
#define TCCR0_INITVAL  ConcByte(1,WGM00_Val,COM01_Val,COM00_Val,WGM01_Val,CS02_Val,CS01_Val,CS00_Val)

#endif /* HAL_TIMER0_PRIV_H_ */
