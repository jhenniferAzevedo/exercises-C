// Faça um programa que leia cinco números inteiros e armazene-os em um vetor.
// Imprima o vetor na ordem crescente.

#include <stdio.h>

int main(void)
{
    const int MAX = 10;
    int i, j, num[MAX], change;

    for (i = 0; i < MAX; i++)
    {
        printf("numero %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    /* Reorganizando o vetor */
    for (j = 0; j < MAX; j++)
    {
        for (i = 0; i < (MAX - 1); i++)
        {
            if (num[i + 1] < num[i])
            {
                change = num[i + 1];
                num[i + 1] = num[i];
                num[i] = change;
            }
        }
    }

    printf("vetor reorganizado: { ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", num[i]);
    }
    printf("}\n");
    return 0;
}