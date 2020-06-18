/*
 * I2C_int.h
 *
 *  Created on: Apr 25, 2020
 *      Author: hp
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

ERROR_STATES I2C_enuInit (void);

ERROR_STATES I2C_enuStartCondition (void);

ERROR_STATES I2C_enuRepeatStartCondition (void);

ERROR_STATES I2C_enuStopCondition (void);

ERROR_STATES I2C_enuSendSlaveAddress (u8 address , u8 action);

ERROR_STATES I2C_enuSlaveCheckHisAddress (void);

ERROR_STATES I2C_enuMasterSendData (u8 data);

ERROR_STATES I2C_enuSlaveRecieveData (u8 * data);


#endif /* MCAL_I2C_I2C_INT_H_ */
