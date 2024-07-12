/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        event.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       以循环队列实现的事件泵
 *              通过屏蔽中断解决多线程问题。
 *              注意：由于队列长度有限，使用时需要关注收支平衡，特别是高优先级线程中触发事件不要太频繁。
 * 
 *              另一种思路——
 *              1. 仅在操作静态/全局变量时上锁。
 *              2. 该方案虽然可以改善多线程问题，但在上锁的时刻有发生丢消息的风险，
 *              3. 可增加少量Event组成的临时缓冲队列，该队列为顺序数组，每个Event单元单独设锁，多层嵌套撞车时，也是顺序遍历写入。
 *              4. 主循环调用GetEvent时顺序转移到主队列，转移前先屏蔽中断(相比当前方案降低了屏蔽中断的次数，即写入事件时不屏蔽)。
 * 
 *              另外，定长数组相比动态分配、增长peEvent指针列表的方式可靠且效率高。
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
 * @brief       触发事件，即将事件插入到事件队列
 * 
 * @param       eType 事件类型
 * @param       ucValue 事件ID
 * @return      EVENT_QUEUE_STATE 队列状态
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
 * @brief       Get the Event object，
 *              包含对于撞车
 * @param       psEvent 通过指针取出内容
 * @return      EVENT_QUEUE_STATE 队列状态
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
