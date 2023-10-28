/* Elabore um algoritmo que leia a idade de 13 pessoas e mostre, para cada entrada, a mensagem 
"Maior de idade" ou "Menor de idade". No final informe quantos são maiores e quantos são menores. */

#include <stdio.h>

int main(void)
{
    int i, idade, contMaior = 0, contMenor = 0;

    for (i = 0; i < 13; i++)
    {
        printf("\n\n\tPessoa %d\n", i + 1);
        printf("\tDigite a idade: ");
        scanf("%d", &idade);

        if (idade < 18)
        {
            printf("\t>>> Menor de idade.");
            contMenor++;
        }
        else
        {
            printf("\t>>> Maior de idade.");
            contMaior++;
        }
    }

    printf("\n\n>>> Numero de maiores de idade: %d.", contMaior);
    printf("\n>>> Numero de menores de idade: %d.", contMenor);
    return 0;
}