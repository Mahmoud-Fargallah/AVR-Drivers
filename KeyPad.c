#include "STD_Types.h"
#include "BIT_MATH.h"
#include "int.h"
#include "REG.h"
#include <util/delay.h>

u8 arr[4][4] = {
		{ 1,  2,  3,  4 },
		{ 5,  6,  7,  8 },
		{ 9, 10, 11, 12 },
		{ 13, 14,15, 16 }
};



u8 keypad() {

	u8 Local_u8Num = 0;

	for (u8 Col = 0; Col < 4; Col++) {

		DIO_enuSetPinValue(PORTD, Col, LOW);

		for (u8 Row = 4; Row < 8; Row++) {

			if (!(DIO_enuGetPinValue(PORTD, Row))) {
				Local_u8Num = arr[Row - 4][Col];

				while (!(DIO_enuGetPinValue(PORTD, Row)));


				_delay_ms(10);
			}

		}
		DIO_enuSetPinValue(PORTD, Col, HIGH);

	}

	return Local_u8Num;

}

u8 Keypad_Return(u8 Num) {
	switch (Num) {
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
	case 13:
		return '%';
	case 14:
		return '=';
	case 15:
		return '+';
	case 16:
		return '-';
	default:
		return Num;
	}
}
