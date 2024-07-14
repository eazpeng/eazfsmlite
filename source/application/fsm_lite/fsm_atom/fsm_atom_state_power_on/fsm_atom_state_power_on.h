/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        fsm_atom_state_power_on.h
 * @version     3.0.1
 * @date        2024-06-28
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#ifndef _FSM_ATOM_STATE_POWER_ON_H_

#include "event.h"

extern void FsmAtomStatePowerOn_Init(void);
extern void FsmAtomStatePowerOn_Execute(PEvent psEvent);

#endif // !_FSM_ATOM_STATE_POWER_ON_H_