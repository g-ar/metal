#include <stdio.h>
#include <smmintrin.h>
/****************************************************************************************************
/* counting set bits using popcnt instruction, without inline assembly
/****************************************************************************************************
/* $ gcc popcnt.c -o popcnt -msse4.2 */
int main(void)
{
    int pop = _mm_popcnt_u64(0xf00ff00ff00ff00f);
    printf("popcnt: %d\n", pop);
    return 0;
}