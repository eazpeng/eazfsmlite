/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        eaz_math_lib.h
 * @version     3.0.1
 * @date        2024-07-13
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       包括字符转数字、数字转字符、大小端转换、提取指定位、端口宏定义（Sinowealth）、等小工具函数
 */
#ifndef _EAZ_MATH_LIB_H_
#define _EAZ_MATH_LIB_H_

#include "config.h"

#define BIN_FORMAT_BYTE_REGION
#ifdef BIN_FORMAT_BYTE_REGION
#define LongToBin(n)  		\
(                    		\
    ((n >> 21) & 0x80) |    \
    ((n >> 18) & 0x40) |    \
    ((n >> 15) & 0x20) |    \
    ((n >> 12) & 0x10) |    \
    ((n >>  9) & 0x08) |    \
    ((n >>  6) & 0x04) |    \
    ((n >>  3) & 0x02) |    \
    ((n      ) & 0x01)    	\
)
#define Bin(n)              LongToBin(0x##n##L)

#define Bin16(a, b)         ((Bin(a) << 8) + Bin(b))
#define Bin32(a, b , c, d)  ((Bin(a) << 24) + (Bin(b) << 16) + (Bin(c) << 8) + Bin(d))

typedef enum {
    _0b00000000,
    _0b00000001,
    _0b00000010,
    _0b00000011,
    _0b00000100,
    _0b00000101,
    _0b00000110,
    _0b00000111,
    _0b00001000,
    _0b00001001,
    _0b00001010,
    _0b00001011,
    _0b00001100,
    _0b00001101,
    _0b00001110,
    _0b00001111,
    _0b00010000,
    _0b00010001,
    _0b00010010,
    _0b00010011,
    _0b00010100,
    _0b00010101,
    _0b00010110,
    _0b00010111,
    _0b00011000,
    _0b00011001,
    _0b00011010,
    _0b00011011,
    _0b00011100,
    _0b00011101,
    _0b00011110,
    _0b00011111,
    _0b00100000,
    _0b00100001,
    _0b00100010,
    _0b00100011,
    _0b00100100,
    _0b00100101,
    _0b00100110,
    _0b00100111,
    _0b00101000,
    _0b00101001,
    _0b00101010,
    _0b00101011,
    _0b00101100,
    _0b00101101,
    _0b00101110,
    _0b00101111,
    _0b00110000,
    _0b00110001,
    _0b00110010,
    _0b00110011,
    _0b00110100,
    _0b00110101,
    _0b00110110,
    _0b00110111,
    _0b00111000,
    _0b00111001,
    _0b00111010,
    _0b00111011,
    _0b00111100,
    _0b00111101,
    _0b00111110,
    _0b00111111,
    _0b01000000,
    _0b01000001,
    _0b01000010,
    _0b01000011,
    _0b01000100,
    _0b01000101,
    _0b01000110,
    _0b01000111,
    _0b01001000,
    _0b01001001,
    _0b01001010,
    _0b01001011,
    _0b01001100,
    _0b01001101,
    _0b01001110,
    _0b01001111,
    _0b01010000,
    _0b01010001,
    _0b01010010,
    _0b01010011,
    _0b01010100,
    _0b01010101,
    _0b01010110,
    _0b01010111,
    _0b01011000,
    _0b01011001,
    _0b01011010,
    _0b01011011,
    _0b01011100,
    _0b01011101,
    _0b01011110,
    _0b01011111,
    _0b01100000,
    _0b01100001,
    _0b01100010,
    _0b01100011,
    _0b01100100,
    _0b01100101,
    _0b01100110,
    _0b01100111,
    _0b01101000,
    _0b01101001,
    _0b01101010,
    _0b01101011,
    _0b01101100,
    _0b01101101,
    _0b01101110,
    _0b01101111,
    _0b01110000,
    _0b01110001,
    _0b01110010,
    _0b01110011,
    _0b01110100,
    _0b01110101,
    _0b01110110,
    _0b01110111,
    _0b01111000,
    _0b01111001,
    _0b01111010,
    _0b01111011,
    _0b01111100,
    _0b01111101,
    _0b01111110,
    _0b01111111,
    
    _0b10000000,
    _0b10000001,
    _0b10000010,
    _0b10000011,
    _0b10000100,
    _0b10000101,
    _0b10000110,
    _0b10000111,
    _0b10001000,
    _0b10001001,
    _0b10001010,
    _0b10001011,
    _0b10001100,
    _0b10001101,
    _0b10001110,
    _0b10001111,
    _0b10010000,
    _0b10010001,
    _0b10010010,
    _0b10010011,
    _0b10010100,
    _0b10010101,
    _0b10010110,
    _0b10010111,
    _0b10011000,
    _0b10011001,
    _0b10011010,
    _0b10011011,
    _0b10011100,
    _0b10011101,
    _0b10011110,
    _0b10011111,
    _0b10100000,
    _0b10100001,
    _0b10100010,
    _0b10100011,
    _0b10100100,
    _0b10100101,
    _0b10100110,
    _0b10100111,
    _0b10101000,
    _0b10101001,
    _0b10101010,
    _0b10101011,
    _0b10101100,
    _0b10101101,
    _0b10101110,
    _0b10101111,
    _0b10110000,
    _0b10110001,
    _0b10110010,
    _0b10110011,
    _0b10110100,
    _0b10110101,
    _0b10110110,
    _0b10110111,
    _0b10111000,
    _0b10111001,
    _0b10111010,
    _0b10111011,
    _0b10111100,
    _0b10111101,
    _0b10111110,
    _0b10111111,
    _0b11000000,
    _0b11000001,
    _0b11000010,
    _0b11000011,
    _0b11000100,
    _0b11000101,
    _0b11000110,
    _0b11000111,
    _0b11001000,
    _0b11001001,
    _0b11001010,
    _0b11001011,
    _0b11001100,
    _0b11001101,
    _0b11001110,
    _0b11001111,
    _0b11010000,
    _0b11010001,
    _0b11010010,
    _0b11010011,
    _0b11010100,
    _0b11010101,
    _0b11010110,
    _0b11010111,
    _0b11011000,
    _0b11011001,
    _0b11011010,
    _0b11011011,
    _0b11011100,
    _0b11011101,
    _0b11011110,
    _0b11011111,
    _0b11100000,
    _0b11100001,
    _0b11100010,
    _0b11100011,
    _0b11100100,
    _0b11100101,
    _0b11100110,
    _0b11100111,
    _0b11101000,
    _0b11101001,
    _0b11101010,
    _0b11101011,
    _0b11101100,
    _0b11101101,
    _0b11101110,
    _0b11101111,
    _0b11110000,
    _0b11110001,
    _0b11110010,
    _0b11110011,
    _0b11110100,
    _0b11110101,
    _0b11110110,
    _0b11110111,
    _0b11111000,
    _0b11111001,
    _0b11111010,
    _0b11111011,
    _0b11111100,
    _0b11111101,
    _0b11111110,
    _0b11111111,
}BIN_FORMAT;
#endif // BIN_FORMAT_BYTE_REGION

#define BIT_OPERATION_DEFINE_REGION
#ifdef BIT_OPERATION_DEFINE_REGION
#define GetBit(x,y)         ((((uint32)x) & (0x00000001L << y)) > 0)
#define SetBit(x,y)         (x |= (0x00000001L << y))
#define ClrBit(x,y)         (x &= ~(0x00000001L << y))

#define GetBit0(x)          GetBit(x,0)
#define GetBit1(x)          GetBit(x,1)
#define GetBit2(x)          GetBit(x,2)
#define GetBit3(x)          GetBit(x,3)
#define GetBit4(x)          GetBit(x,4)
#define GetBit5(x)          GetBit(x,5)
#define GetBit6(x)          GetBit(x,6)
#define GetBit7(x)          GetBit(x,7)
#define GetBit8(x)          GetBit(x,8)
#define GetBit9(x)          GetBit(x,9)
#define GetBit10(x)         GetBit(x,10)
#define GetBit11(x)         GetBit(x,11)
#define GetBit12(x)         GetBit(x,12)
#define GetBit13(x)         GetBit(x,13)
#define GetBit14(x)         GetBit(x,14)
#define GetBit15(x)         GetBit(x,15)
#define GetBit16(x)         GetBit(x,16)
#define GetBit17(x)         GetBit(x,17)
#define GetBit18(x)         GetBit(x,18)
#define GetBit19(x)         GetBit(x,19)
#define GetBit20(x)         GetBit(x,20)
#define GetBit21(x)         GetBit(x,21)
#define GetBit22(x)         GetBit(x,22)
#define GetBit23(x)         GetBit(x,23)
#define GetBit24(x)         GetBit(x,24)
#define GetBit25(x)         GetBit(x,25)
#define GetBit26(x)         GetBit(x,26)
#define GetBit27(x)         GetBit(x,27)
#define GetBit28(x)         GetBit(x,28)
#define GetBit29(x)         GetBit(x,29)
#define GetBit30(x)         GetBit(x,30)
#define GetBit31(x)         GetBit(x,31)

#define SetBit0(x)          SetBit(x,0)
#define SetBit1(x)          SetBit(x,1)
#define SetBit2(x)          SetBit(x,2)
#define SetBit3(x)          SetBit(x,3)
#define SetBit4(x)          SetBit(x,4)
#define SetBit5(x)          SetBit(x,5)
#define SetBit6(x)          SetBit(x,6)
#define SetBit7(x)          SetBit(x,7)
#define SetBit8(x)          SetBit(x,8)
#define SetBit9(x)          SetBit(x,9)
#define SetBit10(x)         SetBit(x,10)
#define SetBit11(x)         SetBit(x,11)
#define SetBit12(x)         SetBit(x,12)
#define SetBit13(x)         SetBit(x,13)
#define SetBit14(x)         SetBit(x,14)
#define SetBit15(x)         SetBit(x,15)
#define SetBit16(x)         SetBit(x,16)
#define SetBit17(x)         SetBit(x,17)
#define SetBit18(x)         SetBit(x,18)
#define SetBit19(x)         SetBit(x,19)
#define SetBit20(x)         SetBit(x,20)
#define SetBit21(x)         SetBit(x,21)
#define SetBit22(x)         SetBit(x,22)
#define SetBit23(x)         SetBit(x,23)
#define SetBit24(x)         SetBit(x,24)
#define SetBit25(x)         SetBit(x,25)
#define SetBit26(x)         SetBit(x,26)
#define SetBit27(x)         SetBit(x,27)
#define SetBit28(x)         SetBit(x,28)
#define SetBit29(x)         SetBit(x,29)
#define SetBit30(x)         SetBit(x,30)
#define SetBit31(x)         SetBit(x,31)

#define ClrBit0(x)          ClrBit(x,0)
#define ClrBit1(x)          ClrBit(x,1)
#define ClrBit2(x)          ClrBit(x,2)
#define ClrBit3(x)          ClrBit(x,3)
#define ClrBit4(x)          ClrBit(x,4)
#define ClrBit5(x)          ClrBit(x,5)
#define ClrBit6(x)          ClrBit(x,6)
#define ClrBit7(x)          ClrBit(x,7)
#define ClrBit8(x)          ClrBit(x,8)
#define ClrBit9(x)          ClrBit(x,9)
#define ClrBit10(x)         ClrBit(x,10)
#define ClrBit11(x)         ClrBit(x,11)
#define ClrBit12(x)         ClrBit(x,12)
#define ClrBit13(x)         ClrBit(x,13)
#define ClrBit14(x)         ClrBit(x,14)
#define ClrBit15(x)         ClrBit(x,15)
#define ClrBit16(x)         ClrBit(x,16)
#define ClrBit17(x)         ClrBit(x,17)
#define ClrBit18(x)         ClrBit(x,18)
#define ClrBit19(x)         ClrBit(x,19)
#define ClrBit20(x)         ClrBit(x,20)
#define ClrBit21(x)         ClrBit(x,21)
#define ClrBit22(x)         ClrBit(x,22)
#define ClrBit23(x)         ClrBit(x,23)
#define ClrBit24(x)         ClrBit(x,24)
#define ClrBit25(x)         ClrBit(x,25)
#define ClrBit26(x)         ClrBit(x,26)
#define ClrBit27(x)         ClrBit(x,27)
#define ClrBit28(x)         ClrBit(x,28)
#define ClrBit29(x)         ClrBit(x,29)
#define ClrBit30(x)         ClrBit(x,30)
#define ClrBit31(x)         ClrBit(x,31)
#endif // BIT_OPERATION_DEFINE_REGION

#endif // !_EAZ_MATH_LIB_H_