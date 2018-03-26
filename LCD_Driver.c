/*

 * LCD_Driver.c
 *
 *  Created on: Mar 2, 2018
 *      Author: Ahmed
 */

#include "Datatype.h"
#include "LCD_int.h"
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_int.h"
#include "Bit_modification.h"

void LCD_vPosition(u8 position)
{
	if (position > 16)
		LCD_vWriteCommand((175 +position));
	else
		LCD_vWriteCommand((127+position));
	_delay_ms(10);
}



void LCD_vWriteData(u8 Data){

	// RS -> 1
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_HIGH);
    //RW -> 0
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);
    // Write  data
    PORTA = Data;
    //E -> 1
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH);

    // Delay 3 ms to understand data

    _delay_ms(10);

    //E -> 1

    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW);


}

void LCD_vWriteCommand(u8 Command){

	// RS -> 0
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_LOW);
    //RW -> 0
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);
    // Write  data

    PORTA = Command;

    //E -> 1
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH);

    // Delay 3 ms to understand data

    _delay_ms(10);

    //E -> 1

    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW);


}
void Lcd_vInitialization(void){
	//delay for initialized
	 _delay_ms(100);
		// RS -> 0
	    DIO_vSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_LOW);
	    //RW -> 0
	    DIO_vSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);

	 LCD_vWriteCommand(0b00111100);
	 _delay_ms(2);
	 LCD_vWriteCommand(0b00001111);
	 _delay_ms(2);
	 LCD_vWriteCommand(0b00000001);
	 _delay_ms(2);



}
void LCD_vWriteDataSting(u8 Data,u8 * ptr){
	u8 counter;

	// RS -> 1
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN0 , DIO_HIGH);
    //RW -> 0
    DIO_vSetPinValue(DIO_PORTB , DIO_PIN1 , DIO_LOW);
    // Write  data
	for(counter = 0 ; counter < Data ; counter ++){
		if(ptr[counter] == '\0'){break;}
		PORTA = ptr[counter];
		_delay_ms(1000);
	    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_HIGH);

	    // Delay 3 ms to understand data

	    _delay_ms(10);

	    //E -> 1

	    DIO_vSetPinValue(DIO_PORTB , DIO_PIN2 , DIO_LOW);


	}


}

//void DIO_vSetPortValue(u8 Portnum , u8 value){
//switch(Portnum){
//case PORTA :
//	PORTA=value;
//	break;
//case PORTB :
//	PORTB=value;
//	break;
//case PORTC :
//	PORTC=value;
//	break;
//case PORTD :
//	PORTD=value;
//	break;
//
//}
//}
