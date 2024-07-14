/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_state_power_on.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#include "fsm_atom.h"

void FsmAtomStatePowerOn_Execute(PEvent psEvent)
{
    //printf("FsmAtomStatePowerOn_Execute: %d, %d\n", psEvent->eType, psEvent->ucValue);
    if(psEvent->eType == 2 && psEvent->ucValue == 1) {
        FsmLite_SetState((PFsmLite)&vg_sFsmAtom, FSM_ATOM_STATE_STANDBY);
        printf("Switch to STANDBY_STATE\n\n");
    }
}

void FsmAtomStatePowerOn_Init(void)
{
    printf("FsmAtomStatePowerOn_Init\n");
}
