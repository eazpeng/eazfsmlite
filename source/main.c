#include "fsm_atom.h"
#include "eaz_math_lib.h"

void main(void)
{
    uint32 a = 0x12345678;
    printf("%d, %X\n", IsBigEndian(&a), a);
    SwitchEndian(&a, sizeof(a));
    printf("%d, %X\n", IsBigEndian(&a), a);
    SwitchToLittleEndian(&a, sizeof(a));
    printf("%d, %X\n", IsBigEndian(&a), a);
    SwitchToBigEndian(&a, sizeof(a));
    printf("%d, %X\n", IsBigEndian(&a), a);
}