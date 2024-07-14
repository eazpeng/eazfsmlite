/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        eaz_math_lib.c
 * @version     3.0.1
 * @date        2024-07-14
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#include "eaz_math_lib.h"

BOOL IsLittleEndian(void * pValue)
{
    PEazInt16_LE p = pValue;
    return (p->sBytes.byte0 == ((uint8 *)pValue)[0]);
}

BOOL IsBigEndian(void * pValue)
{
    PEazInt16_LE p = pValue;
    return (p->sBytes.byte0 != ((uint8 *)pValue)[0]);
}

void SwitchEndian(void * pValue, uint8 size)
{
    if(size == 2) {
        PEazInt16 p = pValue;
        p->sBytes.byte1 ^= p->sBytes.byte0;
        p->sBytes.byte0 ^= p->sBytes.byte1;
        p->sBytes.byte1 ^= p->sBytes.byte0;
    } else if(size == 4) {
        PEazInt32 p = pValue;
        p->sBytes.byte3 ^= p->sBytes.byte0;
        p->sBytes.byte0 ^= p->sBytes.byte3;
        p->sBytes.byte3 ^= p->sBytes.byte0;

        p->sBytes.byte1 ^= p->sBytes.byte2;
        p->sBytes.byte2 ^= p->sBytes.byte1;
        p->sBytes.byte1 ^= p->sBytes.byte2;
    } else {
        return;
    }
}

void SwitchToBigEndian(void * pValue, uint8 size)
{
    if(size == 2) {
        PEazInt16_BE p = pValue;
        if(p->sBytes.byte0 == ((uint8 *)pValue)[0]) {
            return;
        } else {
            p->sBytes.byte1 ^= p->sBytes.byte0;
            p->sBytes.byte0 ^= p->sBytes.byte1;
            p->sBytes.byte1 ^= p->sBytes.byte0;
        }
    } else if(size == 4) {
        PEazInt32_BE p = pValue;
        if(p->sBytes.byte0 == ((uint8 *)pValue)[0]) {
            return;
        } else {
            p->sBytes.byte3 ^= p->sBytes.byte0;
            p->sBytes.byte0 ^= p->sBytes.byte3;
            p->sBytes.byte3 ^= p->sBytes.byte0;

            p->sBytes.byte1 ^= p->sBytes.byte2;
            p->sBytes.byte2 ^= p->sBytes.byte1;
            p->sBytes.byte1 ^= p->sBytes.byte2;
        }
    } else {
        return;
    }
}

void SwitchToLittleEndian(void * pValue, uint8 size)
{
    if(size == 2) {
        PEazInt16_LE p = pValue;
        if(p->sBytes.byte0 == ((uint8 *)pValue)[0]) {
            return;
        } else {
            p->sBytes.byte1 ^= p->sBytes.byte0;
            p->sBytes.byte0 ^= p->sBytes.byte1;
            p->sBytes.byte1 ^= p->sBytes.byte0;
        }
    } else if(size == 4) {
        PEazInt32_LE p = pValue;
        if(p->sBytes.byte0 == ((uint8 *)pValue)[0]) {
            return;
        } else {
            p->sBytes.byte3 ^= p->sBytes.byte0;
            p->sBytes.byte0 ^= p->sBytes.byte3;
            p->sBytes.byte3 ^= p->sBytes.byte0;

            p->sBytes.byte1 ^= p->sBytes.byte2;
            p->sBytes.byte2 ^= p->sBytes.byte1;
            p->sBytes.byte1 ^= p->sBytes.byte2;
        }
    } else {
        return;
    }
}

