/* Ler um valor N e imprimir todos os valores inteiros entre 1 (inclusive) e N (inclusive). 
Considere que o N deve ser sempre maior que ZERO. Caso o valor informado não seja maior que 
0, deverá ser lido um novo valor para N. */

#include <stdio.h>

int main(void)
{
    int N, i;

    printf("\tDigite um numero maior que zero: ");
    scanf("%d", &N);

    while (N < 1)
    {
        printf("\n\tDigite um numero valido!! \n\tNumero: ");
        scanf("%d", &N);
    }

    printf("\t>>> Os valores inteiros de 1 a %d sao: ", N);

    for (i = 1; i <= N; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}