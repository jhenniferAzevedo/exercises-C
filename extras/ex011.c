/* Leia uma matriz 3 x 3. Leia também um valor X. O programa deverá
fazer uma busca desse valor na matriz e, ao final, escrever a localização
(linha e coluna) ou uma mensagem de não encontrado. */

#include <stdio.h>
#define TAM_MAX 3

int main(void)
{
    int matriz[TAM_MAX][TAM_MAX];
    int i, j, x;

    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("num: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMATRIZ\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\ndigite um numero para conferir se ele esta na matriz: ");
    scanf("%d", &x);

    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            if (x == matriz[i][j])
            {
                printf("o numero esta presente na linha %d e coluna %d.\n", i + 1, j + 1);
                return 0;
            }
        }
    }

    printf("nao ha nenhum numero igual a esse nessa matriz.\n");
    return 0;
}