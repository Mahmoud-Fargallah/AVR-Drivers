
#ifndef ADC_REG_H_
#define ADC_REG_H_

#define		 ADMUX		*((volatile u8*)0x27)

#define		 ADCSRA		*((volatile u8*)0x26)

#define		 ADCH		*((volatile u8*)0x25)

#define		 ADCL		*((volatile u8*)0x24)

#define		 ADC		*((volatile u16*)0x24)

/** CHANNELS **/
#define		 CH0		0
#define		 CH1		1
#define		 CH2		2
#define		 CH3		3
#define		 CH4		4
#define		 CH5		5
#define		 CH6		6
#define		 CH7		7

/**	ADC SOURCE 	**/
#define   EXTERNAL_SOURCE    0
#define        AVCC		     1
#define	  INTERNAL_SOURCE    2

#endif /* ADC_REG_H_ */
