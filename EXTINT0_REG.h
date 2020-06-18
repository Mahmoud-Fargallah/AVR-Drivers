/*
 * GIE_REG.h
 *
 *  Created on: Apr 5, 2020
 *      Author: mfarg
 */

#ifndef EXTINT0_REG_H_
#define EXTINT0_REG_H_



#define GICR     (*((volatile u8*) 0x5B))
#define GIFR     (*((volatile u8*) 0x5A))
#define MCUCR    (*((volatile u8*) 0x55))
#define MCUCSR   (*((volatile u8*) 0x54))




#endif /* EXTINT0_REG_H_ */
