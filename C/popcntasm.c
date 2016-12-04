#include <stdio.h>
/****************************************************************************************************
/* using popcnt instruction using inline assembly  
/****************************************************************************************************
/* $ gcc popcntasm.c -masm=intel -o popcntasm */

int main(int argc, char *argv[])
{
    long no = 0xf00ff00ff00ff00f;
    int val ;
    /* at&t syntax */
    /* asm (
    /*      "popcnt %1, %%rax;" */
    /*      "movl %%eax, %0;" */
    /*      : "=r" ( val )   /\* output *\/ */
    /*      : "r" ( no )     /\* input *\/ */
    /*      : "%rax" /\* clobbered register *\/ */
    /*     ); */

    /* intel syntax */
    asm (
        /* "mov rdx, %1;" */
        /* "popcnt rax, rdx;" */
        "popcnt rax, %1;"
        "mov %0, eax;"
        : "=r" ( val ) /* output */
        : "r" ( no )   /* input */
        : "rdx"        /* clobbered register */
        );

    printf ("popcnt: %d\n", val);
    return 0;
}

