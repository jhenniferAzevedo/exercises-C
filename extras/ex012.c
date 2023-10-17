/* Leia uma matriz de 2 x 2 elementos. Calcule e imprima a sua transposta. */

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 2

int main(void)
{
    int i, j, m[TAM_MAX][TAM_MAX];

    printf("elementos da matriz\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("\tnum: ");
            scanf("%d", &m[i][j]);
        }
    }

    system("cls");

    printf("\nMATRIZ NORMAL\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("[%d] ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ TRANSPOSTA\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("[%d] ", m[j][i]);
        }
        printf("\n");
    }
    return 0;
}