/*
 * I2C_priv.h
 *
 *  Created on: Apr 25, 2020
 *      Author: hp
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_

#define TWBR *((volatile u8 *)0x20)
#define TWCR *((volatile u8 *)0x56)
#define TWSR *((volatile u8 *)0x21)
#define TWDR *((volatile u8 *)0x23)
#define TWAR *((volatile u8 *)0x22)

#define TWBR_VALUE 		( (F_CPU - 16 * SCL_FREQ) / (2*SCL_FREQ * I2C_PRES ))


#endif /* MCAL_I2C_I2C_PRIV_H_ */
