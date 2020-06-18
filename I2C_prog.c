/*
 * I2C_prog.c
 *
 *  Created on: Apr 25, 2020
 *      Author: hp
 */
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorStates.h"

#include "I2C_config.h"
#include "I2C_priv.h"


ERROR_STATES I2C_enuInit (void)
{
	ERROR_STATES error = ES_NOT_OK;

	TWBR=TWBR_VALUE;
	TWSR&=~(1<<0)&(~(1<<1)); // pres 1
	TWCR|=(1<<2);			//Enable i2c
	TWAR= ECU_ADDRESS;

	return error;
}


ERROR_STATES I2C_enuStartCondition (void)
{
	ERROR_STATES error = ES_NOT_OK;

	TWCR|=(1<<5);//start condition
	TWCR|=(1<<7);//clear flag
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x08)
		error = ES_OK;

	return error;
}



ERROR_STATES I2C_enuRepeatStartCondition (void)
{
	ERROR_STATES error = ES_NOT_OK;

	TWCR|=(1<<5);//start condition
	TWCR|=(1<<7);//clear flag
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x10)
		error = ES_OK;

	return error;
}



ERROR_STATES I2C_enuStopCondition (void)
{
	ERROR_STATES error = ES_NOT_OK;

	TWCR|=(1<<4);//stop condition
	TWCR|=(1<<7);//clear flag
	error = ES_OK;

	return error;
}



ERROR_STATES I2C_enuSendSlaveAddress (u8 address , u8 action)
{
	ERROR_STATES error = ES_NOT_OK;

	if (address < 128 ) TWDR = (address<<1);
	if (action <=1 )    TWDR|= (action);
	TWCR&=~(1<<5);
	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x18)
		error = ES_OK;
	else if ((TWSR & 0xf8) == 0x40)
		error = ES_OK;

	return error;
}



ERROR_STATES I2C_enuSlaveCheckHisAddress (void)
{
	ERROR_STATES error = ES_NOT_OK;

	TWCR|=(1<<6);
	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x60)
		error = ES_OK;
	else if ((TWSR & 0xf8) == 0xA8)
		error = ES_OK;

	return error;
}



ERROR_STATES I2C_enuMasterSendData (u8 data)
{
	ERROR_STATES error = ES_NOT_OK;

	TWDR=data;
	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x28)
		error = ES_OK;

	return error;
}


ERROR_STATES I2C_enuSlaveRecieveData (u8 * data)
{
	ERROR_STATES error = ES_NOT_OK;

	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x80)
	{
		* data = TWDR;
		error = ES_OK;
	}

	return error;
}


ERROR_STATES I2C_enuSlaveSendDataNACKI (u8 data)
{
	ERROR_STATES error = ES_NOT_OK;
	TWDR=data;
	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0xC0)
		error = ES_OK;
	return error;
}
ERROR_STATES I2C_enuMasterRecieveDataNACK (u8 * data)
{
	ERROR_STATES error = ES_NOT_OK;
	TWCR|=(1<<7);
	while (!((TWCR>>7)&1));
	if ((TWSR & 0xf8) == 0x58)
	{
		* data = TWDR;
		error = ES_OK;
	}
	return error;

}

