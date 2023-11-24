/* Ler a idade de 13 pessoas, mostrar a média das idades, o número
de pessoas com idade abaixo da média e o número de menores de idade. */

#include <stdio.h>

int main(void)
{
    int i, idade[13], menor_idade = 0, idades_abaixo_da_media = 0;
    float media_idade = 0;

    for (i = 0; i < 13; i++)
    {
        printf("idade: ");
        scanf("%d", &idade[i]);
        media_idade += idade[i];

        if (idade[i] < 18)
        {
            menor_idade++;
        }
    }
    media_idade /= i;

    for (i = 0; i < 13; i++)
    {
        if (idade[i] < media_idade)
        {
            idades_abaixo_da_media++;
        }
    }
    printf("\nmedia das idades: %.2f", media_idade);
    printf("\nnumero de pessoas com idade abaixo da media: %d", idades_abaixo_da_media);
    printf("\nnumero de menores de idade: %d", menor_idade);
    return 0;
}