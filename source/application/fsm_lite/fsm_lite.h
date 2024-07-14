/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_lite.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       简化状态机
 *              本模块支持同时定义多个状态机，多个状态机中可相互交叉调用/设定。
 */
#ifndef _FSM_LITE_H_
#define _FSM_LITE_H_

#include "event.h"

typedef struct tagFsmLite {
    void *      pvData;
}FsmLite, *PFsmLite;

typedef struct tagFsmState {
    int8        eID;
    FP_VV       Init;
    FP_VVP      Execute;
}FsmState, *PFsmState, **PPFsmState;

int8 FsmLite_GetState(PFsmLite psFsmLite);
int8 FsmLite_GetPrevState(PFsmLite psFsmLite);
void FsmLite_SetState(PFsmLite psFsmLite, int8 cState);

int8 FsmLite_Init(PFsmLite psFsmLite, PFsmState psFsmStatesList, int32 lListSize, int8 cDefaultState);
void FsmLite_Execute(PFsmLite psFsmLite, PEvent psEvent);

#endif // _FSM_LITE_H_
