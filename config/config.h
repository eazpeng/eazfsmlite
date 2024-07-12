/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        config.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       全局性的宏，标准库文件、官方SDK文件引用。
 */
#ifndef _CONFIG_H_

#include <string.h>
#include <math.h>
#include <malloc.h>
#include "stdio.h"
#include "eaz_types.h"

#ifdef _C51_KEYWORDS_

#else
#define data
#define EI()
#define DI()
#endif // _C51_KEYWORDS_


#endif // _CONFIG_H_