/*
 * ADC_int.h
 *
 *  Created on: Apr 6, 2020
 *      Author: omar
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

Error_enuStatus ADC_enuInit(void);

Error_enuStatus ADC_enuEnable(void);

Error_enuStatus ADC_enuDisable(void);

Error_enuStatus ADC_enuSelectChannel(u8 Copy_u8Channel_No);

Error_enuStatus ADC_enuStartConversion(void);

u8 ADC_u8GetInterrupt(void);

#endif /* ADC_INT_H_ */
