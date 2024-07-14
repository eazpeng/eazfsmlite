/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        simu_timer.h
 * @version     3.0.1
 * @date        2024-07-13
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#ifndef _SIMU_TIEMR_H_
#define _SIMU_TIEMR_H_

#include "config.h"

typedef enum {
    SIMU_TIMER_BASE,
    SIMU_TIMER_DELAY,
    SIMU_TIMER_DISPLAY,
    SIMU_TIMER_EVENT,

    SIMU_TIMER_SUM,
}SIMU_TIMER;

extern void SimuTimerHandler(void);
extern BOOL TimeOut(SIMU_TIMER eTimerID);
extern void StartTimer(SIMU_TIMER eTimerID, uint16 uiTimeIn1ms);

#endif // !_SIMU_TIEMR_H_