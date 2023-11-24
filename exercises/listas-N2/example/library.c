#include <stdio.h>
#include "library.h"

void imprime1(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void imprime2(int v[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
}

void imprime3(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void imprime4(int m[][4], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void imprime5(TipoPessoa pessoa)
{
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
}
