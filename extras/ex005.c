/* Faça um programa que imprima os elementos de um vetor que representa uma
progressão aritmética e a soma finita dos elementos. Regras:
    a. O primeiro termo deve ser 1;
    b. A razão deve ser 5;
    c. A soma deve ser feita utilizando a fórmula da soma finita de uma PA;
    d. O tamanho do vetor deve ser 20.
*/

#include <stdio.h>

int main(void)
{
    const int MAX = 20;
    int i, PA[MAX], somaPA;

    printf("PA: ( ");
    for (i = 0; i < MAX; i++)
    {
        PA[i] = 1 + (i * 5);
        printf("%d ", PA[i]);
    }
    printf(")\n");

    somaPA = ((PA[0] + PA[MAX - 1]) * i) / 2;
    printf("soma da PA: %d\n", somaPA);
    return 0;
}