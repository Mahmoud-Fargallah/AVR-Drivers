
#include "ErrorStatus.h"
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "ADC_reg.h"
#include "ADC_int.h"
#include "ADC_config.h"
/*********************************************************************/
Error_enuStatus ADC_enuInit(void)
{
	Error_enuStatus error = ES_NOK;
/***********************  ADC_Source  ********************/
#if     ADC_SOURCE	==  EXTERNAL_SOURCE

	Error_enuStatus Error = ES_NOK;
	/**  External Source   **/
	CLEAR_BIT(ADMUX, 6);
	CLEAR_BIT(ADMUX, 7);

	return Error = ES_OK;

#elif    ADC_SOURCE	 ==   AVCC


	/**  VREF = AVCC  **/
	SET_BIT(ADMUX, 6);
	CLEAR_BIT(ADMUX, 7);


#elif    ADC_SOURCE	 == INTERNAL_SOURCE

	Error_enuStatus Error = ES_NOK;

	/**  Internal Source  **/
	SET_BIT(ADMUX, 6);
	SET_BIT(ADMUX, 7);

	return Error = ES_OK;

#endif

/*************************  ADC_ADJ  ********************/
#if		ADC_ADJ	==	LEFT_ADJ

	SET_BIT(ADMUX, 5);

#elif		ADC_ADJ	==	RIGHT_ADJ

	Error_enuStatus Error = ES_NOK;
	CLEAR_BIT(ADMUX, 5);
	return Error = ES_OK;

#else
#error "WRONG DIRECTION"

#endif

	/****************     ADC_PreScal    *************/

#if 	ADC_SCALE6	==	SCALE64


	CLEAR_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);


#elif 	ADC_SCALE6	==	SCALE128

	Error_enuStatus Error = ES_NOK;

	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);

	return Error = ES_OK;
#else
#error "WRONG SCALE"

#endif

/*************	  ADC_Polling_VS_Inturrept   *******/

#if 	ADC_IE	==	POLLING

	/* Enable Polling  */
	CLEAR_BIT(ADCSRA, 3);


#elif	ADC_IE	==  INTERRUPT

	Error_enuStatus Error = ES_NOK;

	/* Enable Interrupt  */
	SET_BIT(ADCSRA, 3);

	return Error = ES_OK;

#endif

	/**	 Auto Trigger OFF	**/
		CLEAR_BIT(ADCSRA, 5);

		return error = ES_OK;
}
/******************  END_OF_INITIALIZATION  *************************/
/********************************************************************/


Error_enuStatus ADC_enuEnable(void) {
	Error_enuStatus Error = ES_NOK;
	SET_BIT(ADCSRA, 7);
	return Error = ES_OK;
}


Error_enuStatus ADC_enuDisable(void) {
	Error_enuStatus Error = ES_NOK;
	CLEAR_BIT(ADCSRA, 7);
	return Error = ES_OK;
}

Error_enuStatus ADC_enuSelectChannel(u8 Copy_u8Channel_No)
{
	Error_enuStatus Error = ES_NOK;

	switch(Copy_u8Channel_No)
	{
	case CH0:
		        CLEAR_BIT(ADMUX, 0);
			    CLEAR_BIT(ADMUX, 1);
			    CLEAR_BIT(ADMUX, 2);
			    CLEAR_BIT(ADMUX, 3);
			    CLEAR_BIT(ADMUX, 4);
	break;

	case CH1:
		        SET_BIT(ADMUX, 0);
				CLEAR_BIT(ADMUX, 1);
				CLEAR_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH2:
			    CLEAR_BIT(ADMUX, 0);
			    SET_BIT(ADMUX, 1);
				CLEAR_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH3:
		        SET_BIT(ADMUX, 0);
		        SET_BIT(ADMUX, 1);
				CLEAR_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH4:
			    CLEAR_BIT(ADMUX, 0);
				CLEAR_BIT(ADMUX, 1);
				SET_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH5:
		        SET_BIT(ADMUX, 0);
				CLEAR_BIT(ADMUX, 1);
				SET_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH6:
			    CLEAR_BIT(ADMUX, 0);
			    SET_BIT(ADMUX, 1);
			    SET_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;

	case CH7:
		        SET_BIT(ADMUX, 0);
		        SET_BIT(ADMUX, 1);
		        SET_BIT(ADMUX, 2);
				CLEAR_BIT(ADMUX, 3);
				CLEAR_BIT(ADMUX, 4);
	break;



	}

	return Error = ES_OK;

}

Error_enuStatus ADC_enuStartConversion(void)
{

	Error_enuStatus Error = ES_NOK;

	SET_BIT(ADCSRA, 6);

	return Error = ES_OK;

}


u8 ADC_u8GetInterrupt(void) {
	u8 Local_u8Val = 0;
	Local_u8Val = GET_BIT(ADCSRA, 4);
	return Local_u8Val;
}






