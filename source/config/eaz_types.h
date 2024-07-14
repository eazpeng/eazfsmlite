/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        eaz_types.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       各平台常见的宏、类型别名综合整理。
 */
#ifndef _EAZ_TYPES_H_
#define _EAZ_TYPES_H_

// #define EAZ_BIG_ENDIAN

// #define offsetof(struct_type, member_name) ((size_t)&((struct_type *)0)->member_name)
// // #define container_of(member_addr, struct_type, member_name) ({const typeof( ((struct_type *)0)->member_name ) *__mptr = (member_addr); (struct_type *)( (char *)__mptr - offsetof(struct_type,member_name) );})
// #define container_of(member_addr, struct_type, member_name) ((struct_type *)((char *)member_addr - offsetof(struct_type, member_name)))

#define C51_DEFINE_REGION
#ifdef  C51_DEFINE_REGION
#ifdef _C51_KEYWORDS_

#else
#define data
#define EI()
#define DI()
#define bit             BOOL
#endif // _C51_KEYWORDS_
#endif // C51_DEFINE_REGION

#define NORMAL_VALUES_DEFINE_REGION
#ifdef  NORMAL_VALUES_DEFINE_REGION
#ifndef TRUE
#define TURE            (1)
#define FALSE           (0)
#endif // !TRUE

#ifndef true
#define true            (1)
#define false           (0)
#endif // !TRUE

#ifndef ENABLE
#define ENABLE          (1)
#define DISABLE         (0)
#endif // !ENABLE

#ifndef ENABLED
#define ENABLED         (1)
#define DISABLED        (0)
#endif // !ENABLED

#ifndef ON
#define ON              (1)
#define OFF             (0)
#endif // !ON

#ifndef Y
#define Y               (1)
#define N               (0)
#endif // !Y

#ifndef YES
#define YES             (1)
#define NO              (0)
#endif // !YES

#ifndef NULL
#define NULL            ((void *)0)
#endif // !NULL

#ifndef null
#define null            ((void *)0)
#endif // !NULL
#endif // NORMAL_VALUES_DEFINE_REGION

#define NORMAL_TYPES_DEFINE_REGION
#ifdef  NORMAL_TYPES_DEFINE_REGION

typedef char            BOOL;

typedef char            s8;
typedef char            S8;
typedef char            schar;
typedef char            SCHAR;
typedef char            CHAR;
typedef char            int8;
typedef char            INT8;
typedef char            sint8;
typedef char            SINT8;
typedef char            s8_t;
typedef char            schar_t;
typedef char            int8_t;
typedef char            sint8_t;

typedef unsigned char   u8;
typedef unsigned char   U8;
typedef unsigned char   uchar;
typedef unsigned char   UCHAR;
typedef unsigned char   uint8;
typedef unsigned char   UINT8;
typedef unsigned char   u8_t;
typedef unsigned char   uchar_t;
typedef unsigned char   uint8_t;

typedef short           s16;
typedef short           S16;
typedef short           int16;
typedef short           INT16;
typedef short           SHORT;
typedef short           sint16;
typedef short           SINT16;
typedef short           s16_t;
typedef short           int_t;
typedef short           sint_t;
typedef short           int16_t;
typedef short           sint16_t;

typedef unsigned short  u16;
typedef unsigned short  U16;
typedef unsigned short  ushort;
typedef unsigned short  USHORT;
typedef unsigned short  uint16;
typedef unsigned short  UINT16;
typedef unsigned short  u16_t;
typedef unsigned short  uint_t;
typedef unsigned short  ushort_t;
typedef unsigned short  uint16_t;

typedef long            s32;
typedef long            S32;
typedef long            LONG;
typedef long            slong;
typedef long            SLONG;
typedef long            int32;
typedef long            INT32;
typedef long            sint32;
typedef long            SINT32;
typedef long            s32_t;
typedef long            long_t;
typedef long            int32_t;
typedef long            slong_t;
typedef long            sint32_t;

typedef unsigned long   u32;
typedef unsigned long   U32;
typedef unsigned long   ulong;
typedef unsigned long   ULONG;
typedef unsigned long   uint32;
typedef unsigned long   UINT32;
typedef unsigned long   u32_t;
typedef unsigned long   ulong_t;
typedef unsigned long   uint32_t;
#endif // NORMAL_TYPES_DEFINE_REGION

#define EAZ_TYPES_DEFINE_REGION
#ifdef EAZ_TYPES_DEFINE_REGION
typedef union tagEazChar{
    uint8       value;

    struct {
        uint8   bit0  : 1;
        uint8   bit1  : 1;
        uint8   bit2  : 1;
        uint8   bit3  : 1;
        uint8   bit4  : 1;
        uint8   bit5  : 1;
        uint8   bit6  : 1;
        uint8   bit7  : 1;
    }sFlags;
}EazChar, *PEazChar, EazInt8, *PEazInt8;

#ifdef EAZ_BIG_ENDIAN
typedef union tagEazInt{
    uint16      value;

    struct {
        uint8   byte1;
        uint8   byte0;
    }sBytes;

    struct {
        uint8   bit8  : 1;
        uint8   bit9  : 1;
        uint8   bit10 : 1;
        uint8   bit11 : 1;
        uint8   bit12 : 1;
        uint8   bit13 : 1;
        uint8   bit14 : 1;
        uint8   bit15 : 1;

        uint8   bit0  : 1;
        uint8   bit1  : 1;
        uint8   bit2  : 1;
        uint8   bit3  : 1;
        uint8   bit4  : 1;
        uint8   bit5  : 1;
        uint8   bit6  : 1;
        uint8   bit7  : 1;
    }sFlags;
}EazInt, *PEazInt, EazInt16, *PEazInt16;

typedef union tagEazLong{
    uint32      value;

    struct {
        uint8   byte3;
        uint8   byte2;
        uint8   byte1;
        uint8   byte0;
    }sBytes;

    struct {
        uint8   bit24 : 1;
        uint8   bit25 : 1;
        uint8   bit26 : 1;
        uint8   bit27 : 1;
        uint8   bit28 : 1;
        uint8   bit29 : 1;
        uint8   bit30 : 1;
        uint8   bit31 : 1;

        uint8   bit16 : 1;
        uint8   bit17 : 1;
        uint8   bit18 : 1;
        uint8   bit19 : 1;
        uint8   bit20 : 1;
        uint8   bit21 : 1;
        uint8   bit22 : 1;
        uint8   bit23 : 1;

        uint8   bit8  : 1;
        uint8   bit9  : 1;
        uint8   bit10 : 1;
        uint8   bit11 : 1;
        uint8   bit12 : 1;
        uint8   bit13 : 1;
        uint8   bit14 : 1;
        uint8   bit15 : 1;

        uint8   bit0  : 1;
        uint8   bit1  : 1;
        uint8   bit2  : 1;
        uint8   bit3  : 1;
        uint8   bit4  : 1;
        uint8   bit5  : 1;
        uint8   bit6  : 1;
        uint8   bit7  : 1;
    }sFlags;
}EazLong, *PEazLong, EazInt32, *PEazInt32;
#else
typedef union tagEazInt{
    uint16      value;

    struct {
        uint8   byte0;
        uint8   byte1;
    }sBytes;

    struct {
        uint8   bit0  : 1;
        uint8   bit1  : 1;
        uint8   bit2  : 1;
        uint8   bit3  : 1;
        uint8   bit4  : 1;
        uint8   bit5  : 1;
        uint8   bit6  : 1;
        uint8   bit7  : 1;

        uint8   bit8  : 1;
        uint8   bit9  : 1;
        uint8   bit10 : 1;
        uint8   bit11 : 1;
        uint8   bit12 : 1;
        uint8   bit13 : 1;
        uint8   bit14 : 1;
        uint8   bit15 : 1;
    }sFlags;
}EazInt, *PEazInt, EazInt16, *PEazInt16;

typedef union tagEazLong{
    uint32      value;

    struct {
        uint8   byte0;
        uint8   byte1;
        uint8   byte2;
        uint8   byte3;
    }sBytes;

    struct {
        uint8   bit0  : 1;
        uint8   bit1  : 1;
        uint8   bit2  : 1;
        uint8   bit3  : 1;
        uint8   bit4  : 1;
        uint8   bit5  : 1;
        uint8   bit6  : 1;
        uint8   bit7  : 1;
        
        uint8   bit8  : 1;
        uint8   bit9  : 1;
        uint8   bit10 : 1;
        uint8   bit11 : 1;
        uint8   bit12 : 1;
        uint8   bit13 : 1;
        uint8   bit14 : 1;
        uint8   bit15 : 1;

        uint8   bit16 : 1;
        uint8   bit17 : 1;
        uint8   bit18 : 1;
        uint8   bit19 : 1;
        uint8   bit20 : 1;
        uint8   bit21 : 1;
        uint8   bit22 : 1;
        uint8   bit23 : 1;

        uint8   bit24 : 1;
        uint8   bit25 : 1;
        uint8   bit26 : 1;
        uint8   bit27 : 1;
        uint8   bit28 : 1;
        uint8   bit29 : 1;
        uint8   bit30 : 1;
        uint8   bit31 : 1;
    }sFlags;
}EazLong, *PEazLong, EazInt32, *PEazInt32;
#endif // EAZ_BIG_ENDIAN
#endif // EAZ_TYPES_DEFINE_REGION

#define FUNCTION_POINTER_TYPES_DEFINE_REGION
#ifdef  FUNCTION_POINTER_TYPES_DEFINE_REGION
typedef void            (*FP_VVP)(void *);
typedef void *          (*FP_VPVP)(void *);
typedef void            (*FP_VV)(void);
typedef void            (*FP_VU8)(unsigned char);
typedef void            (*FP_VU16)(unsigned short);
typedef void            (*FP_VU32)(unsigned long);
typedef void *          (*FP_VPU8)(unsigned char);
typedef void *          (*FP_VPU16)(unsigned short);
typedef void *          (*FP_VPU32)(unsigned long);
typedef void            (*FP_VS8)(char);
typedef void            (*FP_VS16)(short);
typedef void            (*FP_VS32)(long);
typedef void *          (*FP_VPS8)(char);
typedef void *          (*FP_VPS16)(short);
typedef void *          (*FP_VPS32)(long);
typedef char            (*FP_S8V)(void);
typedef short           (*FP_S16V)(void);
typedef long            (*FP_S32V)(void);
typedef unsigned char   (*FP_U8V)(void);
typedef unsigned short  (*FP_U16V)(void);
typedef unsigned long   (*FP_U32V)(void);

typedef void            (*FP_V_VP)(void *);
typedef void *          (*FP_VP_VP)(void *);
typedef void            (*FP_V_V)(void);
typedef void            (*FP_V_U8)(unsigned char);
typedef void            (*FP_V_U16)(unsigned short);
typedef void            (*FP_V_U32)(unsigned long);
typedef void *          (*FP_VP_U8)(unsigned char);
typedef void *          (*FP_VP_U16)(unsigned short);
typedef void *          (*FP_VP_U32)(unsigned long);
typedef void            (*FP_V_S8)(char);
typedef void            (*FP_V_S16)(short);
typedef void            (*FP_V_S32)(long);
typedef void *          (*FP_VP_S8)(char);
typedef void *          (*FP_VP_S16)(short);
typedef void *          (*FP_VP_S32)(long);

typedef void            (*FunPtr_VVP)(void *);
typedef void *          (*FunPtr_VPVP)(void *);
typedef void            (*FunPtr_VV)(void);
typedef void            (*FunPtr_VU8)(unsigned char);
typedef void            (*FunPtr_VU16)(unsigned short);
typedef void            (*FunPtr_VU32)(unsigned long);
typedef void *          (*FunPtr_VPU8)(unsigned char);
typedef void *          (*FunPtr_VPU16)(unsigned short);
typedef void *          (*FunPtr_VPU32)(unsigned long);
typedef void            (*FunPtr_VS8)(char);
typedef void            (*FunPtr_VS16)(short);
typedef void            (*FunPtr_VS32)(long);
typedef void *          (*FunPtr_VPS8)(char);
typedef void *          (*FunPtr_VPS16)(short);
typedef void *          (*FunPtr_VPS32)(long);

typedef void            (*FunPtr_VVptr)(void *);
typedef void *          (*FunPtr_VptrVptr)(void *);
typedef void            (*FunPtr_VV)(void);
typedef void            (*FunPtr_VU8)(unsigned char);
typedef void            (*FunPtr_VU16)(unsigned short);
typedef void            (*FunPtr_VU32)(unsigned long);
typedef void            (*FunPtr_VUint8)(unsigned char);
typedef void            (*FunPtr_VUint16)(unsigned short);
typedef void            (*FunPtr_VUint32)(unsigned long);
typedef void            (*FunPtr_VUchar)(unsigned char);
typedef void            (*FunPtr_VUint)(unsigned short);
typedef void            (*FunPtr_VUlong)(unsigned long);
typedef void *          (*FunPtr_VptrU8)(unsigned char);
typedef void *          (*FunPtr_VptrU16)(unsigned short);
typedef void *          (*FunPtr_VptrU32)(unsigned long);
typedef void *          (*FunPtr_VptrUchar)(unsigned char);
typedef void *          (*FunPtr_VptrUint)(unsigned short);
typedef void *          (*FunPtr_VptrUlong)(unsigned long);
typedef void            (*FunPtr_VS8)(char);
typedef void            (*FunPtr_VS16)(short);
typedef void            (*FunPtr_VS32)(long);
typedef void            (*FunPtr_VChar)(char);
typedef void            (*FunPtr_VInt)(short);
typedef void            (*FunPtr_VLong)(long);
typedef void *          (*FunPtr_VptrS8)(char);
typedef void *          (*FunPtr_VptrS16)(short);
typedef void *          (*FunPtr_VptrS32)(long);
typedef void *          (*FunPtr_VptrChar)(char);
typedef void *          (*FunPtr_VptrInt)(short);
typedef void *          (*FunPtr_VptrLong)(long);

typedef void            (*FunPtrVoidVoidPtr)(void *);
typedef void *          (*FunPtrVoidPtrVoidPtr)(void *);
typedef void            (*FunPtrVoidVoid)(void);
typedef void            (*FunPtrVoidUint8)(unsigned char);
typedef void            (*FunPtrVoidUint16)(unsigned short);
typedef void            (*FunPtrVoidUint32)(unsigned long);
typedef void            (*FunPtrVoidInt8)(char);
typedef void            (*FunPtrVoidInt16)(short);
typedef void            (*FunPtrVoidInt32)(long);

typedef void            (*FunPtr_VoidVoidPtr)(void *);
typedef void *          (*FunPtr_VoidPtrVoidPtr)(void *);
typedef void            (*FunPtr_VoidVoid)(void);
typedef void            (*FunPtr_VoidUint8)(unsigned char);
typedef void            (*FunPtr_VoidUint16)(unsigned short);
typedef void            (*FunPtr_VoidUint32)(unsigned long);
typedef void            (*FunPtr_VoidInt8)(char);
typedef void            (*FunPtr_VoidInt16)(short);
typedef void            (*FunPtr_VoidInt32)(long);
#endif // FUNCTION_POINTER_TYPES_DEFINE_REGION

#endif // !_EAZ_TYPES_H_