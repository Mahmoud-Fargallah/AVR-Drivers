/*
 * DC_MOTOR_init.h
 *
 *  Created on: Apr 1, 2020
 *      Author: Orayne
 */

#ifndef DC_MOTOR_INIT_H_
#define DC_MOTOR_INIT_H_
#define Stop   1
#define Right  3
#define Left   5
void DC_Motor_int(void);
void DC_MotorMove(u8 Copy_u8MotorID,u8 Copy_u8MotorDirection);

#endif /* DC_MOTOR_INIT_H_ */
