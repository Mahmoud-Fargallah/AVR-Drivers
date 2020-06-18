


#ifndef _LCD_H_
#define _LCD_H_
#define LCD_Data_Dir      DIO_PU8_DDRA
#define LCD_Command_Dir   DIO_PU8_DDRC
#define LCD_Data_Port     DIO_PU8_PORTA
#define LCD_Command_Port  DIO_PU8_PORTC
#define RS PIN0
#define RW PIN1
#define EN PIN2

void LCD_enuCommand(u8 Copy_u8Cmnd);
void LCD_enuChar (u8 Copy_u8Data);
void LCD_enuInit (void)	;
void LCD_enuString (u8 *str);
void LCD_enuGoto_xy (u8 Copy_u8Row, u8 Copy_u8Pos, u8 Copy_Pu8Cmnd);
void LCD_enuWriteNum( u32 num);
void  LCD_enuClear ();
#endif
