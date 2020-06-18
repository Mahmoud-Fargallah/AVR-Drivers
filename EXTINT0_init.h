/*
 * GIE_init.h
 *
 *  Created on: Apr 5, 2020
 *      Author: mfarg
 */

#ifndef EXTINT0_INIT_H_
#define EXTINT0_INIT_H_


void               EXTINT0_voidInit(void);

Error_enuStatus  EXTINT0_enuEnable(void);

Error_enuStatus EXTINT0_enuDisable(void);

void  EXTINT0_Call_BackF(volatile void (*ptr) (void));

#endif /* EXTINT0_INIT_H*/
