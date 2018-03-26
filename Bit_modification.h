/*
 * Bit_modification.h
 *
 *  Created on: Feb 24, 2018
 *      Author: Ahmed
 */

#ifndef BIT_MODIFICATION_H_
#define BIT_MODIFICATION_H_
#define Toggel_bits(reg,bit) reg^=(1<<bit)
#define Set_bits(reg,bit) reg|=(1<<bit)
#define Clear_bits(reg,bit) reg&=~(1<<bit)
#define Get_bit_number(reg,bit) (reg>>bit)&1



#endif /* BIT_MODIFICATION_H_ */
