/* Faça um programa que armazene em um vetor a sequência de Fibonacci. */

#include <stdio.h>
#include <stdlib.h>

#define QNT_MAX 20

int main(void)
{
    int i, seqFibonacci[QNT_MAX];
    seqFibonacci[0] = 1;
    seqFibonacci[1] = 1;

    printf("sequencia fibonacci: { %d %d ", seqFibonacci[0], seqFibonacci[1]);
    for (i = 2; i < QNT_MAX; i++)
    {
        seqFibonacci[i] = seqFibonacci[i - 1] + seqFibonacci[i - 2];
        printf("%d ", seqFibonacci[i]);
    }
    printf("}\n");

    system("pause");
    return 0;
}