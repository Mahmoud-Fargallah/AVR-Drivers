/*
 * Key_Pad.h
 *
 *  Created on: Mar 31, 2020
 *      Author: Orayne
 */

#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#define Keypad_Port_Dir  DIO_PU8_DDRD
#define Keypad_Port_Out  DIO_PU8_PORTD
#define Keypad_Port_In   DIO_PU8_PIND
#define N_Col 4
#define N_Row 4
u8  Keypad_Return(u8 Num);
u8 keypad(void);


#endif /* KEY_PAD_H_ */
