/* Nome do mais velho (feito pela prof) */

#include <stdio.h>
#include <string.h>

void main()
{
    int i, idade[13], maior = 0;
    char nome[10][13], maisVelho[10];

    for (i = 0; i < 13; i++)
    {
        printf("\nNome %d:", i + 1);
        scanf("%s", &nome[i]);
        printf("Idade %d:", i + 1);
        scanf("%d", &idade[i]);
        if (idade[i] > maior)
        {
            maior = idade[i];
            strcpy(maisVelho, nome[i]);
        }
    }
    printf("O mais velho eh %s", maisVelho);
}