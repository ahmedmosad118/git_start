
#include <avr/io.h>
#include <avr/delay.h>
#include "Datatype.h"
#include "keypad_config.h"
#include "DIO_int.h"
#include "keybad_init.h"
#include "LCD_int.h"
#include "Bit_modification.h"

void main(void){

	DIO_vSerPinDirection(KEYPAD_PORT_R , DIO_PIN0 , DIO_OUTPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_R , DIO_PIN1 , DIO_OUTPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_R , DIO_PIN2 , DIO_OUTPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_R , DIO_PIN3 , DIO_OUTPUT);

	DIO_vSerPinDirection(KEYPAD_PORT_C , DIO_PIN0 , DIO_INPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_C , DIO_PIN1 , DIO_INPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_C , DIO_PIN2 , DIO_INPUT);
	DIO_vSerPinDirection(KEYPAD_PORT_C , DIO_PIN3 , DIO_INPUT);


	DIO_vSetPinValue(KEYPAD_PORT_C , DIO_PIN0,DIO_HIGH );
	DIO_vSetPinValue(KEYPAD_PORT_C , DIO_PIN1,DIO_HIGH );
	DIO_vSetPinValue(KEYPAD_PORT_C , DIO_PIN2,DIO_HIGH );
	DIO_vSetPinValue(KEYPAD_PORT_C , DIO_PIN3,DIO_HIGH );


	DIO_vSerPinDirection(DIO_PORTB , DIO_PIN7 , DIO_OUTPUT);
		DDRA=0b11111111;
		DDRB=0b0000111;
			Lcd_vInitialization();
			u8 i ;
			u8 calc[4];
		 		while (1){
		 			i=0;
		 			if(KEYPAD_vRead() && KEYPAD_vRead() !=100){
		 					while(i<4){
			 				if(KEYPAD_vRead() != 100 && KEYPAD_vRead()) {
					 			if(KEYPAD_vRead() == 'c'){
					 				 LCD_vWriteCommand(0b00000001);
					 				break;
					 			}
			 					if(KEYPAD_vRead() == '+' || KEYPAD_vRead() == '=' ||KEYPAD_vRead() == 'c' || KEYPAD_vRead() == '*'){
				 			LCD_vWriteData(KEYPAD_vRead());}
			 					else{
			 						LCD_vWriteData(KEYPAD_vRead() +48);
			 					}
				 			calc[i]=KEYPAD_vRead();
				 			if(KEYPAD_vRead() == '='){
					 			break;
				 			}
				 			_delay_ms(1000);
				 			i++;
		 				 }

		 			}
				 			if(KEYPAD_vRead() == '=' && calc[1] == '+'){
					 			LCD_vWriteData((int)(calc[0]+calc[2])+48);
					 			_delay_ms(1000);
				 			}
				 			if(KEYPAD_vRead() == '=' && calc[1] == '*'){
					 			LCD_vWriteData(((calc[0]+48)*(calc[2])+48)+48);
					 			_delay_ms(1000);
				 			}

		 			}
		 		}



}

