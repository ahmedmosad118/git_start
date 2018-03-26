/*
 * DIO_int.h
 *
 *  Created on: Feb 24, 2018
 *      Author: Ahmed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3


#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

#define DIO_INPUT   0
#define DIO_OUTPUT  1

#define DIO_HIGH   1
#define DIO_LOW    0

void DIO_vSerPinDirection(u8 PortNumber , u8 PinNumber , u8 Direction);
void DIO_vSetPinValue(u8 PortNumber , u8 PinNumber , u8 Value);
int  DIO_vGetPinValue(u8 PortNumber , u8 PinNumber);
void DIO_vEnsblePullUpResistor(u8 PortNumber , u8 PinNumber);
void DIO_vTogelBit(u8 PortNumber , u8 PinNumber);

#endif /* DIO_INT_H_ */
