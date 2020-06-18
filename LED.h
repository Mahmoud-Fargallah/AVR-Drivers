

#ifndef LED_H_
#define LED_H_

Error_enuStatus    LED_enuSetLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID);
Error_enuStatus    LED_enuOnLed (u8 Copy_u8PORTID ,u8 Copy_u8PINID);
Error_enuStatus    LED_enuOffLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID);
Error_enuStatus    LED_enuTogLed(u8 Copy_u8PORTID ,u8 Copy_u8PINID);


#endif /* LED_H_ */
