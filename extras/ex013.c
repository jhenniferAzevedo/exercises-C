/* Faça um programa que permita ao usuário entrar com uma matriz de 3 x 3
números inteiros. Em seguida, gere um vetor pela soma dos números de cada
coluna da matriz e mostrar na tela esse vetor. Por exemplo, a matriz:

[  5   ][  -8  ][ -10  ]
[  1   ][  2   ][  15  ]
[  25  ][  10  ][  7   ]

Vai gerar um vetor, onde cada posição é a soma das colunas da matriz. A primeira
posição será 5+1+25=31, e assim por diante:

|                | coluna 1 | coluna 2 | coluna 3 |
|----------------|----------|----------|----------|
| soma da coluna |    31    |    4     |    12    |
*/

#include <stdio.h>
#define TAM_MAX 3

int main(void)
{
    int i, j, m[TAM_MAX][TAM_MAX], soma[TAM_MAX] = {0};

    printf("elementos da matriz\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("\tnum: ");
            scanf("%d", &m[i][j]);
        }
    }

    printf("\nMATRIZ\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("[%d]  ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSOMA DAS COLUNAS DA MATRIZ\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            soma[i] += m[j][i];
        }
        printf("[%d]  ", soma[i]);
    }

    printf("\n");
    return 0;
}