/*  Percurso de Matriz
 -  preencha uma matriz 3x2 com valores inteiros,
 -  imprima os valores das duas colunas,
 -  depois imprima os valores das três linhas.
*/

#include <stdio.h>

int main(void)
{
    int linha, coluna, M[3][2];

    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 2; coluna++)
        {
            printf(">> numero: ");
            scanf("%d", &M[linha][coluna]);
        }
    }

    // Mostrar colunas e linhas, em texto
    for (coluna = 0; coluna < 2; coluna++)
    {
        printf("\n");
        for (linha = 0; linha < 3; linha++)
        {
            printf("coluna %d --> %d \n", coluna + 1, M[linha][coluna]);
        }
    }

    for (linha = 0; linha < 3; linha++)
    {
        printf("\n");
        for (coluna = 0; coluna < 2; coluna++)
        {
            printf("linha %d --> %d \n", linha + 1, M[linha][coluna]);
        }
    }
    printf("\n");

    // Mostrar colunas e linhas, como uma matriz
    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 2; coluna++)
        {
            printf("[%d]  ", M[linha][coluna]);
        }
        printf("\n");
    }
    return 0;
}