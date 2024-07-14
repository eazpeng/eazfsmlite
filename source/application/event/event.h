/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        event.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       以循环队列实现的事件泵
 *              注意：由于队列长度有限，使用时需要关注收支平衡，特别是高优先级线程中触发事件不要太频繁。
 */
#ifndef _EVENT_H_
#define _EVENT_H_

#include "config.h"
#include "key_event.h"

#define EVENT_QUEUE_SIZE            (0x20)          // 事件队列长度

#define EVENT_EI()                  EI()            // 添加全局是能中断函数
#define EVENT_DI()                  DI()            // 添加全局屏蔽中断函数

typedef enum
{
    E_TYPE_VOID     = 0,
    E_TYPE_KEY      = 1,

    E_TYPE_LIMIT,
}EVENT_TYPE;

typedef enum
{
    EQ_STATE_NORMAL = 0,
    EQ_STATE_BUSY   = 1,
    EQ_STATE_FULL   = 2,
    EQ_STATE_EMPTY  = 3,

    EQ_STATE_LIMIT,
}EVENT_QUEUE_STATE;

#pragma pack(push,1)
typedef struct tagEvent
{
    long      eType;//EVENT_TYPE
    long   ucValue;//unsigned char
}Event, *PEvent;
#pragma pack(pop)

extern void EventInit(void);
extern EVENT_QUEUE_STATE GetEvent(PEvent psEvent);
extern EVENT_QUEUE_STATE TriggerEvent(EVENT_TYPE eType, uint8 ucValue);

#endif  //_EVENT_H_
