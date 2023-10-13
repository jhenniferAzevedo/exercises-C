/* Exemplo de soma (prof que fez) */

#include <stdio.h>

void main(void)
{
    int N, soma;
    char op;

    soma = 0;
    printf("\nCalculadora de somas: ");
    do
    {
        scanf("%d", &N);
        soma = soma + N;
        scanf(" %c", &op);
    }
    while (op == '+');
    printf("%d",soma);
}