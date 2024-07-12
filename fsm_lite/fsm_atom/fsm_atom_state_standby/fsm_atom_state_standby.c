/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_state_standby.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#include "fsm_atom.h"

void FsmAtomStateStandby_Execute(PEvent psEvent)
{
    //printf("FsmAtomStateStandby_Execute: %d, %d\n", psEvent->eType, psEvent->ucValue);
    if(psEvent->eType == 1 && psEvent->ucValue == 2) {
        FsmLite_SetState((PFsmLite)&vg_sFsmAtom, FSM_ATOM_STATE_POWER_ON);
        printf("Switch to POWER_ON_STATE\n\n");
    }
}

void FsmAtomStateStandby_Init(void)
{
    printf("FsmAtomStateStandby_Init\n");
}
