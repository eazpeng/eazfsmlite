/**
 * @copyright   Copyright (c) 2024 EAZ-LAB All rights reserved.
 * @file        simu_timer.c
 * @version     3.0.1
 * @date        2024-07-13
 * @author      eaz.dx.peng <eazpeng@hotmail.com>
 * 
 * @brief       
 */
#include "simu_timer.h"

/// @brief local data structure
typedef struct tagSimuTimer
{
    uint16  uiValue;
    uint16  uiValueBak;
    uint8   bTimeUpFlag     : 1;
    uint8   bTimeActiveFlag : 1;
    uint8   bRevs           : 6;
}SimuTimer, *PSimuTimer;
static volatile uint8 data vs_ucSimuTimerIndex = 0;
static volatile SimuTimer data vs_sSimuTimers[SIMU_TIMER_SUM];

/**
 * @brief       start a simu-timer, unit: 1ms
 * 
 * @param       eTimerID 
 * @param       uiTimeIn1ms 
 */
void StartTimer(SIMU_TIMER eTimerID, uint16 uiTimeIn1ms)
{
    vs_sSimuTimers[eTimerID].uiValueBak = uiTimeIn1ms;
    vs_sSimuTimers[eTimerID].uiValue = 0;
    vs_sSimuTimers[eTimerID].bTimeUpFlag = FALSE;
    vs_sSimuTimers[eTimerID].bTimeActiveFlag = TURE;
}

/**
 * @brief       judge if some-simu-timer time up,
 *              if time up, return 1 only once, and
 *              whill clear the bit and restart counting.
 * 
 * @param       eTimerID 
 * @return      bit 0-still counting, 1-time out
 */
BOOL TimeOut(SIMU_TIMER eTimerID)
{
    if(vs_sSimuTimers[eTimerID].bTimeActiveFlag
        && vs_sSimuTimers[eTimerID].bTimeUpFlag) {
        vs_sSimuTimers[eTimerID].uiValue = 0;
        vs_sSimuTimers[eTimerID].bTimeUpFlag = FALSE;

        return TURE;
    }

    return FALSE;
}

/**
 * @brief       drop this func to a 1ms timer-base code block,
 *              much better in a high-prio ISR.
 * 
 */
void SimuTimerHandler(void)
{
    vs_ucSimuTimerIndex < SIMU_TIMER_SUM ? (vs_ucSimuTimerIndex ++) : (vs_ucSimuTimerIndex = 0);

    if(vs_sSimuTimers[vs_ucSimuTimerIndex].bTimeActiveFlag) {
        if(!vs_sSimuTimers[vs_ucSimuTimerIndex].bTimeUpFlag) {
            vs_sSimuTimers[vs_ucSimuTimerIndex].uiValue++;

            if(vs_sSimuTimers[vs_ucSimuTimerIndex].uiValue >= vs_sSimuTimers[vs_ucSimuTimerIndex].uiValueBak) {
                vs_sSimuTimers[vs_ucSimuTimerIndex].bTimeUpFlag = 1;
            }
        }
    }
}
