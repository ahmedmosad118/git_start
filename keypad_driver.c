/*
 * keypad_driver.c

 *
 *  Created on: Mar 3, 2018
 *      Author: Ahmed
 */
#include "Datatype.h"
#include "DIO_int.h"
#include "keypad_config.h"

#include "Bit_modification.h"
#include <avr/io.h>
#include "DIO_int.h"
u8 KEYPAD_Array[4][4]={ {1,2,3,'/'},{4,5,6,'-'},{7,8,9,'c'},{'+',0,'*','='} };

u8 KEYPAD_vRead(void){
	u8  counter_R = 0;
	u8  counter_C = 0;
	u8 value;
	 DIO_vSetPinValue(KEYPAD_PORT_R,KEYPAD_R0,DIO_HIGH);
	 DIO_vSetPinValue(KEYPAD_PORT_R,KEYPAD_R1,DIO_HIGH);
	 DIO_vSetPinValue(KEYPAD_PORT_R,KEYPAD_R2,DIO_HIGH);
	 DIO_vSetPinValue(KEYPAD_PORT_R,KEYPAD_R3,DIO_HIGH);
	for( counter_R = 0 ; counter_R < 4; counter_R++){
		DIO_vSetPinValue(KEYPAD_PORT_R,counter_R,DIO_LOW);
		for( counter_C = 0 ; counter_C < 4; counter_C++){

			value=Get_bit_number(PIND,counter_C);
			if( value == 0){
				return KEYPAD_Array[counter_R][counter_C];
			}
		}
		DIO_vSetPinValue(KEYPAD_PORT_R,counter_R,DIO_HIGH);

	}
	return 100;


}

