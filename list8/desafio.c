/* Ler nome e idade de 13 pessoas, após as leituras mostrar todos os nomes, suas idades e quem é o mais velho. */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[13][20], nome_mais_velho[20];
    int i, idade[13], idade_mais_velho = 0;

    for (i = 0; i < 13; i++)
    {
        printf("\nPessoa %d\n", i + 1);
        printf("nome: ");
        scanf("%s", nome[i]);

        printf("idade: ");
        scanf("%d", &idade[i]);

        if (idade[i] > idade_mais_velho)
        {
            idade_mais_velho = idade[i];
            strcpy(nome_mais_velho, nome[i]);
        }
    }

    for (i = 0; i < 13; i++)
    {
        printf("%s tem %d anos.\n", nome[i], idade[i]);
    }
    printf("\nA pessoa mais velha foi %s, com idade de %d anos.", nome_mais_velho, idade_mais_velho);
    return 0;
}