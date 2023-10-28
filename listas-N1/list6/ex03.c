/* Acrescente no exercício anterior a informação da média das idades. */

#include <stdio.h>

int main(void)
{
    char op;
    int i = 0, idade;
    float mediaIdades = 0;

    do
    {
        printf("\n\tPessoa %d\n", i + 1);
        printf("\tDigite a idade: ");
        scanf("%d", &idade);
        mediaIdades += idade;

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

    mediaIdades /= i;
    printf("\n\n>>> Total de pessoas: %d.", i);
    printf("\n>>> Media das idades: %.1f\n", mediaIdades);
    return 0;
}

// responda com while ou do-while