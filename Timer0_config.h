/*
 * Timer0_config.h
 *
 *  Created on: Apr 10, 2020
 *      Author: Mahmoud Fargallah
 */

#ifndef HAL_TIMER0_CONFIG_H_
#define HAL_TIMER0_CONFIG_H_

//RANGE : ( HIGH "1" or LOW "0")

/* Timer/Counter0 Control Register – TCCR0
-------------------------------------------
Bit 6, 3 – WGM01:0: Waveform Generation Mode
--------------------------------------------
WGM01 WGM00 Timer/Counter Mode of Operation
  0     0               Normal
  0     1          PWM, Phase Correct
  1     0                 CTC
  1     1               Fast PWM
--------------------------------------------

*/

#define  WGM01_Val  0
#define  WGM00_Val  0

/*Bit 5:4 – COM01:0: Compare Match Output Mode
---------------------------------------------------
Compare Output Mode, non-PWM Mode
COM01 COM00     Description
  0     0    Normal port operation, OC0 disconnected.
  0     1    Toggle OC0 on compare match
  1     0    Clear OC0 on compare match
  1     1    Set OC0 on compare match
---------------------------------------------------

*/
#define  COM01_Val  0
#define  COM00_Val  0

/*
CS02 CS01 CS00 	Description
0 	  0 	0 	No clock source (Timer/Counter stopped).
0  	  0 	1 	clk/(No prescaling)
0 	  1 	0 	clk/8 (From prescaler)
0     1 	1 	clk/64 (From prescaler)
1 	  0 	0 	clk/256 (From prescaler)
1 	  0 	1   clk/1024 (From prescaler)
1 	  1 	0 	External clock source on T0 pin. Clock on falling edge.
1 	  1 	1 	External clock source on T0 pin. Clock on rising edge.

*/

#define  CS02_Val   1
#define  CS01_Val   0
#define  CS00_Val   1

//Timer/Counter Interrupt Mask Register – TIMSK
//--------------------------------------------------
// Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable

#define  OCIE0_Val  0
// Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable

#define  TOIE0_Val  1

#endif /* HAL_TIMER0_CONFIG_H_ */
