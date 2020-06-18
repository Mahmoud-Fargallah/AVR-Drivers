
/********************************************************************************************/
/*************************    AUTHOR: Mahmoud Fargallah       *******************************/
/*************************    VERSION: 01                     *******************************/
/*************************    DATE:26/3/2020                  *******************************/
/*************************    DISCRIPTION:   DIO_INTERFACES_H *******************************/
/********************************************************************************************/


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "ErrorStatus.h"
#include "int.h"
#include "DC_MOTOR_init.h"
#include "DC_Motor_Config.h"
#include "DC_Motor_Priv.h"


void DC_Motor_int(void){


	for(u8 i=0; i<Number_Of_Motors;i++)
	{
		/* Disable 2 Pins */

		     DIO_enuSetPinValue(Array[i].DCmotor_u8RightPort, Array[i].DCmotor_u8RightPin, LOW);
		     DIO_enuSetPinValue(Array[i].DCmotor_u8LeftPort, Array[i].DCmotor_u8LeftPin, LOW);

	}

}
void DC_MotorMove(u8 Copy_u8MotorID,u8 Copy_u8MotorDirection)
{

	if (Copy_u8MotorID<Number_Of_Motors)
	{
		switch(Copy_u8MotorDirection)
		{

		case  Stop :

			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8RightPort, Array[Copy_u8MotorID].DCmotor_u8RightPin, LOW); /* <      *       *       *        > */
			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8LeftPort, Array[Copy_u8MotorID].DCmotor_u8LeftPin, LOW);   /*        Disable 2 Pins             */
			break;                                                                                                        /* <      *       *       *        > */


		case  Right:


			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8RightPort, Array[Copy_u8MotorID].DCmotor_u8RightPin,HIGH);  /* <      *       *       *        > */
			                                                                                                               /*        Enable Right Pin           */
			                                                                                                               /*        Disable Left Pin           */
			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8LeftPort, Array[Copy_u8MotorID].DCmotor_u8LeftPin, LOW);    /* <      *       *       *        > */
			break;

		case  Left :


			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8RightPort, Array[Copy_u8MotorID].DCmotor_u8RightPin, LOW);  /* <      *       *       *        > */
			                                                                                                               /*        Disable Right Pin          */
			                                                                                                               /*        Enable Left Pin            */
			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8LeftPort, Array[Copy_u8MotorID].DCmotor_u8LeftPin, HIGH);   /* <      *       *       *        > */
			break;

		default :

			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8RightPort, Array[Copy_u8MotorID].DCmotor_u8RightPin, HIGH);  /* <      *       *       *        > */
			DIO_enuSetPinValue(Array[Copy_u8MotorID].DCmotor_u8LeftPort, Array[Copy_u8MotorID].DCmotor_u8LeftPin,   HIGH);  /*        Disable 2 Pins             */
			                                                                                                                /* <      *       *       *        > */
		}

	}
}
