/* Some um número indeterminado de inteiros. Se o símbolo digitado entre os
números for ‘+’, continue somando, se for ‘=’ mostre o resultado da soma. */

#include <stdio.h>

int main(void)
{
    char sinal;
    int num, somaNum = 0;
    printf("\t>>> Faca soma e finalize com sinal de igual (x + y =). \n\n\tsoma: ");

    do
    {
        scanf("%d", &num);
        somaNum += num;
        scanf(" %c", &sinal);

    } while (sinal != '=');

    printf("\tresultado: %d\n", somaNum);
    return 0;
}

// responda com while ou do-while