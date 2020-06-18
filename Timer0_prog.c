/*
 * Timer0_prog.c
 *
 *  Created on: Apr 11, 2020
 *      Author: Mahmoud Fargallah
 */

#include "../LIB/STD_types.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_init.h"
#include "../MCAL/DIO_reg.h"
#include "Timer0_reg.h"
#include "Timer0_config.h"
#include "Timer0_int.h"
#include "Timer0_priv.h"




void  Timer0_Init(void){
	TCCR0 = TCCR0_INITVAL;
	ASSIGN_BIT(TIMSK,OCIE0,OCIE0_Val);
	ASSIGN_BIT(TIMSK,TOIE0,TOIE0_Val);
	ASSIGN_BIT(TIFR , TOV0 , 1);
}


u8 Timer0_SetRegister(u8 RegName, u8 RegVal){
	Timer0_Mode Local_TimerState;
	if(RegName == TCNT){
		TCNT0 = RegVal;
		Local_TimerState = Timer0_NormalState;
	}else if (RegName == OCR) {
		OCR0 = RegVal;
		Local_TimerState = Timer0_NormalState;
	}else {
		Local_TimerState = Timer0_InvalidRegisterInput;
	}
	return Local_TimerState;
}
