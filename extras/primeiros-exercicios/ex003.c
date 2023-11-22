/* Faça um programa em linguagem C que preencha uma matriz 3x2 com valores inteiros.
Então imprima os valores das duas colunas, depois imprima os valores das três linhas. */

#include <stdio.h>

int main(void)
{
    int linha, coluna, M[3][2];

    for (linha = 0; linha < 3; linha++)
    {
        for (coluna = 0; coluna < 2; coluna++)
        {
            printf("numero: ");
            scanf("%d", &M[linha][coluna]);
        }
    }

    // Mostrar colunas e linhas, em texto
    for (coluna = 0; coluna < 2; coluna++)
    {
        printf("\ncoluna %d --> ", coluna + 1);
        for (linha = 0; linha < 3; linha++)
        {
            printf("%d ", M[linha][coluna]);
        }
    }

    for (linha = 0; linha < 3; linha++)
    {
        printf("\nlinha %d --> ", linha + 1);
        for (coluna = 0; coluna < 2; coluna++)
        {
            printf("%d ", M[linha][coluna]);
        }
    }

    printf("\n\n");
    // Mostrar colunas e linhas, como matriz
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