/* Faça um programa com dois vetores de números inteiros de tamanho 10,
lidos pelo usuário, no qual deve ser feito a soma dos elementos dos vetores,
sendo que o primeiro elemento do primeiro vetor deve ser somado com o último
elemento do segundo vetor, o segundo elemento do primeiro vetor deve ser
somado com o último elemento do segundo vetor e assim por diante. Armazene
a soma em um terceiro vetor e imprima-o. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_MAX 10

int main(void)
{
    int i, v1[QNT_MAX], v2[QNT_MAX], soma[QNT_MAX];

    printf("digite os termos do primeiro vetor.\n");
    for (i = 0; i < QNT_MAX; i++)
    {
        printf("termo [%d]: ", i);
        scanf("%d", &v1[i]);
    }

    printf("\ndigite os termos do segundo vetor.\n");
    for (i = 0; i < QNT_MAX; i++)
    {
        printf("termo [%d]: ", i);
        scanf("%d", &v2[i]);
    }

    printf("\no vetor soma ficou assim: { ");
    for (i = 0; i < QNT_MAX; i++)
    {
        soma[i] = v1[i] + v2[(QNT_MAX - 1) - i];
        printf("%d ", soma[i]);
    }
    printf("}\n");

    system("pause");
    return 0;
}