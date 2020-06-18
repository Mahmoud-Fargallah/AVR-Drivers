#include "STD_Types.h"
#include "DIO_int.h"
#include "REG.h"
#include "LCD.h"
#include <util/delay.h>


void LCD_enuCommand(u8 Copy_u8Cmnd)
{

	LCD_Data_Port = Copy_u8Cmnd;
	LCD_Command_Port &= ~(1 << RS); /* RS=0 */
	LCD_Command_Port &= ~(1 << RW); /* RW=0 */
	LCD_Command_Port |= (1 << EN);  /* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(3);
}
void LCD_enuChar(u8 Copy_u8Data)
{
	LCD_Data_Port = Copy_u8Data;
	LCD_Command_Port |= (1 << RS);  /* RS=1 Data reg. */
	LCD_Command_Port &= ~(1 << RW); /* RW=0 */
	LCD_Command_Port |= (1 << EN);  /* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(1);

}
void LCD_enuInit(void) {

	LCD_Command_Dir =  0xFF;
	LCD_Data_Dir    =  0xFF;
	_delay_ms(15);

	LCD_enuCommand(0x38);
	LCD_enuCommand(0x0C);
	LCD_enuCommand(0x06);
	LCD_enuCommand(0x01);
	LCD_enuCommand(0x80);

}
void  LCD_enuString(u8 *str)
{

		int i;
		for(i=0;str[i]!='\0';i++)
		{
			LCD_enuChar (str[i]);

		}
	}

void LCD_enuGoto_xy(u8 Copy_u8Row, u8 Copy_u8Pos, u8 Copy_Pu8Cmnd)
{


	if  (Copy_u8Row == 0 && Copy_u8Pos<16)
		LCD_enuCommand((Copy_u8Pos & 0x0F)|0x80);
		else if (Copy_u8Row == 1 && Copy_u8Pos<16)

			LCD_enuCommand((Copy_u8Pos & 0x0F)|0xC0);
	    LCD_enuString(Copy_Pu8Cmnd);
}

   void LCD_enuClear() {
	   LCD_enuCommand(0x01); /* clear display */
	   LCD_enuCommand(0x80); /* cursor first */

}

   void LCD_enuWriteNum( u32 num) {

   	u8 counter = 0, size = 0;
   	u32 cont = num, n[10];


   	/** To Find Length Of Num **/
   	while (num > 0)
   	{
   		n[counter] = num % 10;
   		counter++;
   		num /= 10;
   	}
   	num = cont;
   	while (counter) {
   		LCD_enuChar(n[counter-1 ] + '0');
   		//num/=10;
   		counter--;
   	}



   }
