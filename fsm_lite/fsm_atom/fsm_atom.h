/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_states_list.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       状态机 FSM_ATOM 的状态列表
 */
#ifndef _FSM_ATOM_STATES_LIST_H_

#include "fsm_lite.h"

typedef enum {
    FSM_ATOM_STATE_POWER_ON,
    // FSM_ATOM_STATE_SELFTEST,
    // FSM_ATOM_STATE_ERROR,
    // FSM_ATOM_STATE_LOW_POWER,
    FSM_ATOM_STATE_STANDBY,
    // FSM_ATOM_STATE_SETTINGS,
    // FSM_ATOM_STATE_RUN,
    // FSM_ATOM_STATE_CHARGING,
    // FSM_ATOM_STATE_CALIBRATE,
    
    FSM_ATOM_STATE_SUM
}FSM_ATOM_STATE;

extern volatile FsmLite vg_sFsmAtom;

extern void FsmAtomInit(void);

#endif // !_FSM_ATOM_STATES_LIST_H_