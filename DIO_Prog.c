/*
 * DIO_Prog.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Ahmed
 */
#include "Datatype.h"
#include "DIO_int.h"
#include "Bit_modification.h"
#include <avr/io.h>

void DIO_vSerPinDirection(u8 PortNumber , u8 PinNumber , u8 Direction)
{
 switch (PortNumber)
 {
 case DIO_PORTA:
	 if(Direction == DIO_OUTPUT){
		 Set_bits(DDRA,PinNumber);
	 }
	 else {
		 Clear_bits(DDRA,PinNumber);
	 }
	 break;
 case DIO_PORTB:
	 if(Direction == DIO_OUTPUT){
		 Set_bits(DDRB,PinNumber);
	 }
	 else {
		 Clear_bits(DDRB,PinNumber);
	 }
	 break;
 case DIO_PORTC:
	 if(Direction == DIO_OUTPUT){
		 Set_bits(DDRC,PinNumber);
	 }
	 else {
		 Clear_bits(DDRC,PinNumber);
	 }
	 break;
 case DIO_PORTD:
	 if(Direction == DIO_OUTPUT){
		 Set_bits(DDRD,PinNumber);
	 }
	 else {
		 Clear_bits(DDRD,PinNumber);
	 }
	 break;
 }
}
void DIO_vSetPinValue(u8 PortNumber , u8 PinNumber , u8 Value){
	 switch (PortNumber)
	 {
	 case DIO_PORTA:
		 if(Value == DIO_HIGH){
			 Set_bits(PORTA,PinNumber);
		 }
		 else {
			 Clear_bits(PORTA,PinNumber);
		 }
		 break;
	 case DIO_PORTB:
		 if(Value == DIO_OUTPUT){
			 Set_bits(PORTB,PinNumber);
		 }
		 else {
			 Clear_bits(PORTB,PinNumber);
		 }
		 break;
	 case DIO_PORTC:
		 if(Value == DIO_OUTPUT){
			 Set_bits(PORTC,PinNumber);
		 }
		 else {
			 Clear_bits(PORTC,PinNumber);
		 }
		 break;
	 case DIO_PORTD:
		 if(Value == DIO_OUTPUT){
			 Set_bits(PORTD,PinNumber);
		 }
		 else {
			 Clear_bits(PORTD,PinNumber);
		 }
		 break;
	 }
}
int DIO_vGetPinValue(u8 PortNumber , u8 PinNumber){
	 switch (PortNumber)
	 {
	 case DIO_PORTA:
		 return  Get_bit_number(PINA,PinNumber);
		 break;
	 case DIO_PORTB:
		 return  Get_bit_number(PINB,PinNumber);
			 break;
	 case DIO_PORTC:
		 return  Get_bit_number(PINC,PinNumber);
			 break;
	 case DIO_PORTD:
		 return  Get_bit_number(PIND,PinNumber);
			 break;
	 }
}
void DIO_vEnsblePullUpResistor(u8 PortNumber , u8 PinNumber){
	 switch (PortNumber)
	 {
	 case DIO_PORTA:

			 Set_bits(PORTA,PinNumber);
		 break;
	 case DIO_PORTB:
			 Set_bits(PORTB,PinNumber);
		 break;
	 case DIO_PORTC:
			 Set_bits(PORTC,PinNumber);
		 break;
	 case DIO_PORTD:
			 Set_bits(PORTD,PinNumber);
		 break;
	 }
}
void DIO_vTogelBit(u8 PortNumber , u8 PinNumber){
	 switch (PortNumber)
	 {
	 case DIO_PORTA:

		 Toggel_bits(PORTA,PinNumber);
		 break;
	 case DIO_PORTB:
		 Toggel_bits(PORTB,PinNumber);
		 break;
	 case DIO_PORTC:
		 Toggel_bits(PORTC,PinNumber);
		 break;
	 case DIO_PORTD:
		 Toggel_bits(PORTD,PinNumber);
		 break;
	 }
}
