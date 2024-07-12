/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        event.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       ��ѭ������ʵ�ֵ��¼���
 *              ͨ�������жϽ�����߳����⡣
 *              ע�⣺���ڶ��г������ޣ�ʹ��ʱ��Ҫ��ע��֧ƽ�⣬�ر��Ǹ����ȼ��߳��д����¼���Ҫ̫Ƶ����
 * 
 *              ��һ��˼·����
 *              1. ���ڲ�����̬/ȫ�ֱ���ʱ������
 *              2. �÷�����Ȼ���Ը��ƶ��߳����⣬����������ʱ���з�������Ϣ�ķ��գ�
 *              3. ����������Event��ɵ���ʱ������У��ö���Ϊ˳�����飬ÿ��Event��Ԫ�������������Ƕ��ײ��ʱ��Ҳ��˳�����д�롣
 *              4. ��ѭ������GetEventʱ˳��ת�Ƶ������У�ת��ǰ�������ж�(��ȵ�ǰ���������������жϵĴ�������д���¼�ʱ������)��
 * 
 *              ���⣬����������ȶ�̬���䡢����peEventָ���б�ķ�ʽ�ɿ���Ч�ʸߡ�
 */
#include "config.h"
#include "event.h"

#pragma pack(push,1)
typedef struct tagEventQueue {
    uint8       ucSum;
    uint8       ucHead;
    uint8       ucTail;
    Event       psEvent[EVENT_QUEUE_SIZE];
    struct {
        uint8   bLock   : 1;
        uint8   bRevs   : 7;
    }sFlags;
}EventQueue, *PEventQueue;
#pragma pack(pop)
static EventQueue data s_sEventQueue;

/**
 * @brief       �����¼��������¼����뵽�¼�����
 * 
 * @param       eType �¼�����
 * @param       ucValue �¼�ID
 * @return      EVENT_QUEUE_STATE ����״̬
 */
EVENT_QUEUE_STATE TriggerEvent(EVENT_TYPE eType, uint8 ucValue)
{
    EVENT_QUEUE_STATE data eResultState = EQ_STATE_NORMAL;

    EVENT_DI();
    if(0 == s_sEventQueue.sFlags.bLock) {
        s_sEventQueue.sFlags.bLock = 1;

        if(s_sEventQueue.ucSum >= EVENT_QUEUE_SIZE) {
            s_sEventQueue.sFlags.bLock = 0;
            eResultState = EQ_STATE_FULL;
        } else {
            s_sEventQueue.psEvent[s_sEventQueue.ucTail].eType = eType;
            s_sEventQueue.psEvent[s_sEventQueue.ucTail].ucValue = ucValue;
            s_sEventQueue.ucTail = (s_sEventQueue.ucTail + 1) % EVENT_QUEUE_SIZE;
            s_sEventQueue.ucSum ++;

            s_sEventQueue.sFlags.bLock = 0;
            eResultState = EQ_STATE_NORMAL;
        }
    } else {
        eResultState = EQ_STATE_BUSY;
    }
    EVENT_EI();

    return eResultState;
}

/**
 * @brief       Get the Event object��
 *              ��������ײ��
 * @param       psEvent ͨ��ָ��ȡ������
 * @return      EVENT_QUEUE_STATE ����״̬
 */
EVENT_QUEUE_STATE GetEvent(PEvent psEvent)
{
    EVENT_QUEUE_STATE data eResultState = EQ_STATE_NORMAL;
    
    EVENT_DI();
    if(0 == s_sEventQueue.sFlags.bLock) {
        s_sEventQueue.sFlags.bLock = 1;

        if(0 == s_sEventQueue.ucSum) {
            psEvent->eType = E_TYPE_VOID;
            psEvent->ucValue = 0;
            
            s_sEventQueue.sFlags.bLock = 0;
            eResultState = EQ_STATE_EMPTY;
        } else {
            psEvent->eType = s_sEventQueue.psEvent[s_sEventQueue.ucHead].eType;
            psEvent->ucValue = s_sEventQueue.psEvent[s_sEventQueue.ucHead].ucValue;
            s_sEventQueue.ucHead = (s_sEventQueue.ucHead + 1) % EVENT_QUEUE_SIZE;
            s_sEventQueue.ucSum --;

            s_sEventQueue.sFlags.bLock = 0;
            eResultState = EQ_STATE_NORMAL;
        }
    } else {
        eResultState = EQ_STATE_BUSY;
    }
    EVENT_EI();
    
    return eResultState;
}

void EventInit(void)
{
    memset((uint8 *)&s_sEventQueue, 0, sizeof(s_sEventQueue));
}
