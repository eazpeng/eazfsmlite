/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_state_standby.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#ifndef _FSM_ATOM_STATE_STANDBY_H_

#include "event.h"

extern void FsmAtomStateStandby_Init(void);
extern void FsmAtomStateStandby_Execute(PEvent psEvent);

#endif // !_FSM_ATOM_STATE_STANDBY_H_