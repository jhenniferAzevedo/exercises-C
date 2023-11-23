// Faça um programa que gere um vetor de tamanho aleatório (50 no máximo),
// com elementos aleatórios e imprima a mediana.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 51

int main(void)
{
    int i, j, vetor[TAM_MAX], troca;
    float mediana = 0;

    /* Definindo o tamanho aleatório do array */
    srand(time(NULL));
    int max = rand() % TAM_MAX;
    printf("tamanho do vetor: %d\n\n", max - 1);

    /* Preenchendo o array com valores aleatorios até 100 */
    printf(">>> vetor: { ");
    for (i = 1; i < max; i++)
    {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }
    printf("}\n");

    /* Organizando o array em ordem crescente */
    for (j = 1; j < max; j++)
    {
        for (i = 1; i < max - 1; i++)
        {
            if (vetor[i + 1] < vetor[i])
            {
                troca = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = troca;
            }
        }
    }

    printf(">>> vetor organizado: { ");
    for (i = 1; i < max; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("}\n");

    --max;
    /* Encontrando a mediana */
    printf(">>> a mediana desse vetor e ");
    if (max % 2 == 0)
    {
        mediana = (float)(vetor[(max / 2) + 1] + vetor[max / 2]) / 2;
    } else mediana = vetor[(max + 1) / 2];
    printf("%.1f\n", mediana);

    return 0;
}