/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_states_list.c
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#include "fsm_atom.h"
#include "fsm_atom_state_power_on.h"
#include "fsm_atom_state_standby.h"

static const FsmState cs_psFsmAtomStatesList[FSM_ATOM_STATE_SUM] = {
    [FSM_ATOM_STATE_STANDBY] = {
        .eID = FSM_ATOM_STATE_STANDBY,
        .Init = (FP_VV)FsmAtomStateStandby_Init,
        .Execute = (FP_VVP)FsmAtomStateStandby_Execute,
    },
    [FSM_ATOM_STATE_POWER_ON] = {
        .eID = FSM_ATOM_STATE_POWER_ON,
        .Init = (FP_VV)FsmAtomStatePowerOn_Init,
        .Execute = (FP_VVP)FsmAtomStatePowerOn_Execute,
    },
};

volatile FsmLite vg_sFsmAtom;
void FsmAtomInit(void)
{
    FsmLite_Init((PFsmLite)&vg_sFsmAtom, (PFsmState)cs_psFsmAtomStatesList, FSM_ATOM_STATE_SUM, FSM_ATOM_STATE_POWER_ON);
}