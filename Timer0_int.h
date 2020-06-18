/*
 * Timer0_int.h
 *
 *  Created on: Apr 10, 2020
 *      Author: Khalid
 */

#ifndef HAL_TIMER0_INT_H_
#define HAL_TIMER0_INT_H_

typedef enum  Timer0_Mode {
    Timer0_NormalState =0,
    Timer0_OperationMode,
    Timer0_CompareOutputMode,
    Timer0_InvalidRegisterInput
}Timer0_Mode;

#define  TCNT  0
#define  OCR   1

void  Timer0_Init(void);

u8 Timer0_SetRegister(u8 RegName, u8 RegVal);

#endif /* HAL_TIMER0_INT_H_ */
