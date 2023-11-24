/* Ler 2 valores inteiros, calcular e escrever a soma dos inteiros existentes entre
os 2 valores lidos(incluindo os valores lidos na soma). Considere que o segundo valor
deve ser sempre maior que o primeiro. Se não for, uma nova leitura deve ser feita. */

#include <stdio.h>

int main(void)
{
    int n1, n2, i, soma = 0;

    printf("\tDigite dois numeros, em que o segundo seja maior que o primeiro.\n");
    printf("\t> Primeiro numero: ");
    scanf("%d", &n1);
    printf("\t> Segundo numero: ");
    scanf("%d", &n2);

    while (n1 > n2)
    {
        printf("\n\tEsqueceu que o primeiro deve ser maior?! \n\tDigite novamente o primeiro e segundo numero.\n");
        printf("\t> Primeiro numero: ");
        scanf("%d", &n1);
        printf("\t> Segundo numero: ");
        scanf("%d", &n2);
    }

    printf("\n>>> Os valores inteiros de %d a %d sao: ", n1, n2);

    for (i = n1; i <= n2; i++)
    {
        soma += i;
        printf("%d ", i);
    }

    printf("\n>>> A soma dos inteiros de %d a %d e %d.\n", n1, n2, soma);
    return 0;
}