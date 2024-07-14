#include "fsm_atom.h"

void delay(long t)
{
    while(t --);
}

#define TEST_BIN (0x01011012L & 0x02)

volatile static Event vs_sEvent;
void main(void)
{
    long L;
    L = TEST_BIN;

    FsmAtomInit();
    for(;;) {
        delay(10000000);
        vs_sEvent.eType = (vs_sEvent.eType + 1) % 11;
        vs_sEvent.ucValue = (vs_sEvent.ucValue + 1) % 37;
        FsmLite_Execute((PFsmLite)&vg_sFsmAtom, (PEvent)&vs_sEvent);
    }
}