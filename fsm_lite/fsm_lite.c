/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_lite.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       ��״̬��
 *              
 *              ���˼·����
 *              1. ͨ��void*�����ڲ����ݣ���ͨ���������ݽṹָ��ǿת�ﵽ�ڲ����ʵ�Ŀ�ġ�
 *              2. �������о���ʹ�þ�̬/ȫ�ֱ�������ȫʹ��ջ����/�ѱ�����������̵߳������⡣(���������ӳ�����)
 *              3. ��ʼ��������������StatesList����ӳ�䡣
 *              4. ����������ƣ���ģ��֧��ͬʱ������״̬�������״̬���п��໥�������/�趨��
 */
#include "fsm_lite.h"

typedef enum {
    FSM_STAGE_INIT,
    FSM_STAGE_EXECUTE
}FSM_STAGE;

// ˽�нṹ
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
    vs_psState = psFsmLite->pvData;//˽�����ݷ���
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return -1;

    return vs_psState->eState;
}

int8 FsmLite_GetPrevState(PFsmLite psFsmLite)
{
    vs_psState = psFsmLite->pvData;//˽�����ݷ���
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return -1;

    return vs_psState->ePrevState;
}

void FsmLite_SetState(PFsmLite psFsmLite, int8 cState)
{
    vs_psState = psFsmLite->pvData;//˽�����ݷ���
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
    vs_psState = psFsmLite->pvData;//˽�����ݷ���

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
    vs_psState = psFsmLite->pvData;//˽�����ݷ���
    if(vs_psState->ppsFsmStatesPtrList == NULL || psFsmLite->pvData == NULL) return;

    switch((unsigned char)vs_psState->eStage) {
        case FSM_STAGE_INIT: {
            vs_psState->eStage = FSM_STAGE_EXECUTE;
            vs_psState->ppsFsmStatesPtrList[vs_psState->eState]->Init();
        }break;// �˴�����Ҫ break

        case FSM_STAGE_EXECUTE: {
            vs_psState->ppsFsmStatesPtrList[vs_psState->eState]->Execute(psEvent);
        }break;
    }
}
