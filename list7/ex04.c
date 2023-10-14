/* Elabore um algoritmo que receba como entradas nome, peso e idade de 10 pessoas
e mostre a média dos pesos, a média das idades e o nome da pessoa mais velha. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[20], maisVelha[20];
    int i, idade, maiorIdade = 0;
    float peso, mediaPeso = 0, mediaIdade = 0;

    for (i = 0; i < 3; i++)
    {
        printf("\n* PESSOA %d *\n", i + 1);
        printf("\t>>> nome: ");
        scanf("%s", nome);

        printf("\t>>> idade: ");
        scanf("%d", &idade);
        mediaIdade += idade;

        if (idade > maiorIdade)
        {
            maiorIdade = idade;
            strcpy(maisVelha, nome);
        }

        printf("\t>>> peso: ");
        scanf("%f", &peso);
        mediaPeso += peso;
    }

    mediaIdade /= i;
    mediaPeso /= i;

    printf("\n\n\tRELATORIOS\n");
    printf(">>> Media das idades: %.1f\n", mediaIdade);
    printf(">>> Media dos pesos: %.1fkg\n", mediaPeso);
    printf(">>> Nome da pessoa mais velha: %s.\n", maisVelha);
    return 0;
}