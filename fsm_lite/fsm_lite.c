/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_lite.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       简化状态机
 *              
 *              设计思路——
 *              1. 通过void*隐藏内部数据，再通过本地数据结构指针强转达到内部访问的目的。
 *              2. 各函数中均不使用静态/全局变量，完全使用栈变量/堆变量，避免多线程调用问题。(这样会增加程序开销)
 *              3. 初始化函数包括对于StatesList的重映射。
 *              4. 基于以上设计，本模块支持同时定义多个状态机，多个状态机中可相互交叉调用/设定。
 */
#include "fsm_lite.h"

typedef enum {
    FSM_STAGE_INIT,
    FSM_STAGE_EXECUTE
}FSM_STAGE;

// 私有结构
#pragma pack(push,1)
typedef struct tagFsmLiteParas {
    FSM_STAGE   eStage;
    int8        eState;
    int8        ePrevState;
    int8        cStateLimit;
    PPFsmState  ppsFsmStatesPtrList;
}FsmLiteParas, *PFsmLiteParas;
#pragma pack(pop)

static volatile PFsmLiteParas vs_psState;

int8 FsmLite_GetState(PFsmLite psFsmLite)
{
    vs_psState = psFsmLite->pvData;//私有数据访问
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return -1;

    return vs_psState->eState;
}

int8 FsmLite_GetPrevState(PFsmLite psFsmLite)
{
    vs_psState = psFsmLite->pvData;//私有数据访问
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return -1;

    return vs_psState->ePrevState;
}

void FsmLite_SetState(PFsmLite psFsmLite, int8 cState)
{
    vs_psState = psFsmLite->pvData;//私有数据访问
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return;

    if(cState >= vs_psState->cStateLimit) return;
    vs_psState->ePrevState = vs_psState->eStage;
    vs_psState->eState = cState;
    vs_psState->eStage = FSM_STAGE_INIT;
}

int8 FsmLite_Init(PFsmLite psFsmLite, PFsmState psFsmStatesList, int32 lListSize, int8 cDefaultState)
{
    psFsmLite->pvData = (PFsmLiteParas)malloc(sizeof(FsmLiteParas));
    if(psFsmLite->pvData == NULL) {
        return -1;
    }
    vs_psState = psFsmLite->pvData;//私有数据访问

    vs_psState->ppsFsmStatesPtrList = (PPFsmState)malloc(lListSize * sizeof(PFsmState));
    if(vs_psState->ppsFsmStatesPtrList == NULL) {
        free(psFsmLite->pvData);
        psFsmLite->pvData = NULL;
        return -1;
    }
    
    // REMAP
    for(uint8 i = 0; i < lListSize; i ++) {
        if(psFsmStatesList[i].eID < lListSize) {
            vs_psState->ppsFsmStatesPtrList[psFsmStatesList[i].eID] = &psFsmStatesList[i];
        } else {
            free(vs_psState->ppsFsmStatesPtrList);
            vs_psState->ppsFsmStatesPtrList = NULL;
            free(psFsmLite->pvData);
            psFsmLite->pvData = NULL;
            return -1;
        }
    }

    vs_psState->eState = cDefaultState;
    vs_psState->ePrevState = vs_psState->eState;
    vs_psState->cStateLimit = lListSize;
    vs_psState->eStage = FSM_STAGE_INIT;

    return 0;
}

void FsmLite_Execute(PFsmLite psFsmLite, PEvent psEvent)
{
    vs_psState = psFsmLite->pvData;//私有数据访问
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return;

    switch((unsigned char)vs_psState->eStage) {
        case FSM_STAGE_INIT: {
            vs_psState->eStage = FSM_STAGE_EXECUTE;
            vs_psState->ppsFsmStatesPtrList[vs_psState->eState]->Init();
        }break;// 此处不需要 break

        case FSM_STAGE_EXECUTE: {
            vs_psState->ppsFsmStatesPtrList[vs_psState->eState]->Execute(psEvent);
        }break;
    }
}
