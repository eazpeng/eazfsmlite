/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        event.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       ��ѭ������ʵ�ֵ��¼���
 *              ע�⣺���ڶ��г������ޣ�ʹ��ʱ��Ҫ��ע��֧ƽ�⣬�ر��Ǹ����ȼ��߳��д����¼���Ҫ̫Ƶ����
 */
#ifndef _EVENT_H_
#define _EVENT_H_

#include "config.h"
#include "key_event.h"

#define EVENT_QUEUE_SIZE            (0x20)          // �¼����г���

#define EVENT_EI()                  EI()            // ���ȫ�������жϺ���
#define EVENT_DI()                  DI()            // ���ȫ�������жϺ���

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
