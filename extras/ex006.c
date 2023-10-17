/* Faça um programa que leia o nome de cinco pessoas e armazene-os em um vetor,
em seguida, a leitura da idade deve ser feita também. Por fim, imprima as pessoas
com suas respectivas idades na ordem do mais novo para o mais velho. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const int QNT_MAX_PESSOAS = 5;
    char nome[QNT_MAX_PESSOAS][30], trocaNome[30];
    int i, pessoa, idade[QNT_MAX_PESSOAS], trocaIdade;

    for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
    {
        printf("\nnome: ");
        scanf("%s", nome[pessoa]);
        printf("idade: ");
        scanf("%d", &idade[pessoa]);
    }

    for (i = 0; i < QNT_MAX_PESSOAS; i++)
    {
        for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
        {
            if (idade[pessoa + 1] < idade[pessoa])
            {
                trocaIdade = idade[pessoa + 1];
                idade[pessoa + 1] = idade[pessoa];
                idade[pessoa] = trocaIdade;

                strcpy(trocaNome, nome[pessoa + 1]);
                strcpy(nome[pessoa + 1], nome[pessoa]);
                strcpy(nome[pessoa], trocaNome);
            }
        }
    }

    printf("\n* pessoas na ordem crescente *\n");
    for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
    {
        printf("\t%da --> %s, %d\n", pessoa + 1, nome[pessoa], idade[pessoa]);
    }

    printf("\n");
    system("pause");
    return 0;
}