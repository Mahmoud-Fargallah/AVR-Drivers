
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/**		ADC ADJ		**/
#define		ADC_ADJ		LEFT_ADJ
//#define		ADC_ADJ		RIGHT_ADJ


/**	  ADC PRE_SCALER 	**/
//#define 	ADC_SCALE4		SCALE16
//#define 	ADC_SCALE5		SCALE32
 #define 	ADC_SCALE6		SCALE64
//#define 	ADC_SCALE7		SCALE128


/**	  ADC SOURCE	**/
//#define    ADC_SOURCE	 EXTERNAL_SOURCE
#define    ADC_SOURCE	   AVCC
//#define    ADC_SOURCE	 INTERNAL_SOURCE


/**   ADC POLLING & INTERRUPT	  **/
#define 	ADC_IE		POLLING
//#define		ADC_IE		INTERRUPT


#endif /* ADC_CONFIG_H_ */
