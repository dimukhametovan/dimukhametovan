#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#include "fsm.h"
int32_t hash = 0, p = 1, k = 31, MOD = 10000001;

// 15 Подсчитать контрольные суммы всех слов исходного текста.
// Declare your global variables and state functions below

// Start state example:
// Prints every input character until EOF and puts '!' at the end of each line

// state start(char c)
// {
//     state next;

//     if (c == '\n')
//     {
//         putchar('!');
//         putchar(c);
//         next = (state)start;
//     }
//     else if (c == EOF)
//     {
//         next = NULL;
//     }
//     else
//     {
//         putchar(c);
//         next = (state)start;
//     }

//     return next;
// }

state start(char c)
{
    state next;
    if ((c == ' ') || (c == '\n'))
    {
        printf("%d ", hash);
        hash = 0;
        p = 1;
        k = 31;
        MOD = 10000001;
        next = (state)start;
    }
    else if (c == EOF)
    {
        next = NULL;
    }
    else if ((c != ' ') && (c != '\n'))
    {
        hash = (hash + c * p) % MOD;
        p = (p * k) % MOD;
        next = (state)start;
    }
    return next;
}
