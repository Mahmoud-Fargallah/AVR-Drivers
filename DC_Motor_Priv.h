
#ifndef DC_MOTOR_PRIV_H_
#define DC_MOTOR_PRIV_H_

typedef struct {
	u8 DCmotor_u8RightPort;
	u8 DCmotor_u8RightPin;
	u8 DCmotor_u8LeftPort;
	u8 DCmotor_u8LeftPin;

}DCmotor;

 extern DCmotor Array[Number_Of_Motors];

#endif /* DC_MOTOR_PRIV_H_ */
