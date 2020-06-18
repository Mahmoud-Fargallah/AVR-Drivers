
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ErrorStatus.h"
#include "DIO_int.h"
#include "REG.h"
#include "EXTINT0_init.h"
#include "EXTINT0_REG.h"
#include "EXTINT0_Config.h"
#include <util/delay.h>


#define   NULL     (void*)0

volatile  void (*pf  )(void) = NULL;


void               EXTINT0_voidInit(void)
{
#if  SENSE_MODE     ==    FALLING

	    CLEAR_BIT(MCUCR,0);

		SET_BIT(MCUCR,1);


#elif  SENSE_MODE   ==    IOC

	    SET_BIT(MCUCR,0);

		CLEAR_BIT(MCUCR,1);

#elif  SENSE_MODE   ==    LOW

		CLEAR_BIT(MCUCR,0);

	    CLEAR_BIT(MCUCR,1);


#elif  SENSE_MODE   ==    RISING

		SET_BIT(MCUCR,0);

	    SET_BIT(MCUCR,1);

#else
#error     "WRONG MODE"

#endif

}

Error_enuStatus EXTINT0_enuEnable(void)
{
	Error_enuStatus error = ES_NOK;

	 SET_BIT(GICR,6);



     error = ES_OK;

	 return error ;
}

Error_enuStatus EXTINT0_enuDisable(void)
{
	Error_enuStatus error = ES_NOK;

	CLEAR_BIT(GICR,6);


     error = ES_OK;
	return error ;
}


void EXTINT0_Call_BackF (volatile  void (*x)(void) )
{

	pf = x ;
}

void __vector_1() __attribute__((signal,used));

void __vector_1()
{

   pf() ;

}
