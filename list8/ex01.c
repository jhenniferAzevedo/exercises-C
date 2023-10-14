/* Leia 10 números inteiros e, após as leituras, mostre todos os valores na tela. */

#include <stdio.h>

int main(void)
{
    int num[9], i;

    for (i = 0; i < 10; i++)
    {
        printf("digite um numero inteiro: ");
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}