/* Leia um número indeterminado de idades e diga para cada uma se é maior ou menor
de idade. Ao final, informe o número de entradas de dados que foram processadas. */

#include <stdio.h>

int main(void)
{
    char op;
    int i = 0, idade;

    do
    {
        printf("\n\tPessoa %d\n", i + 1);
        printf("\tDigite a idade: ");
        scanf("%d", &idade);

        if (idade < 18)
        {
            printf("\t>>> Menor de idade.");
        }
        else
        {
            printf("\t>>> Maior de idade.");
        }

        i++;
        printf("\n\ndeseja continuar? \n(s) sim \n(n) nao\n");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("\n\n>>> Total de pessoas: %d.\n", i);
    return 0;
}

// responda com while ou do-while