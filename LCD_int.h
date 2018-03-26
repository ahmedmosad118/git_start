/*
 * LCD_int.h
 *
 *  Created on: Mar 2, 2018
 *      Author: Ahmed
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "Datatype.h"
#define  LCD_PORT DIO_PORTA
#define  LCD_PORT_command DIO_PORTA
#define RS_PIN DIO_PIN0
#define RW_PIN DIO_PIN1
#define E_PIN DIO_PIN2


void LCD_vWriteData(u8 Data);
void LCD_vWriteDataSting(u8 Data,u8 * ptr);
void Lcd_vInitialization(void);
void LCD_vWriteCommand(u8 Command);
void LCD_vPosition(u8 position);


#endif /* LCD_INT_H_ */


//change in your file
