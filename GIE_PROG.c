
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ErrorStatus.h"
#include "DIO_int.h"
#include "REG.h"
#include "GIE_REG.h"
#include "GIE_init.h"
#include <util/delay.h>

Error_enuStatus GIE_enuEnable(void)
{
	Error_enuStatus error = ES_NOK;

	SET_BIT(SRAG , 7);

	return error ;
}

Error_enuStatus GIE_enuDisable(void)
{
	Error_enuStatus error = ES_NOK;

	CLEAR_BIT(SRAG , 7);

	return error ;
}
