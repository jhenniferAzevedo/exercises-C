/* Modifique o programa do item anterior de forma que no final informe 
quantos são maiores, quantos são menores, quantos tem idade entre 20 e 
25, quantos tem mais de 60 anos, a média das idades, se esta média é 
menor que 21 e (DESAFIO) a idade do mais velho. */

#include <stdio.h>

int main(void)
{
    int i, idade, contMaior = 0, contMenor = 0, contEntre20e25 = 0, 
        contMaior60 = 0, idadeMaisVelho = 0;
    float mediaIdades = 0;

    for (i = 0; i < 13; i++)
    {
        printf("\n\n\tPessoa %d\n", i + 1);
        printf("\tDigite a idade: ");
        scanf("%d", &idade);

        mediaIdades += idade;

        if (idade < 18)
        {
            printf("\t>>> Menor de idade.");
            contMenor++;
        }
        else 
        {
            printf("\t>>> Maior de idade.");
            contMaior++;

            if (idade >= 20 && idade <= 25) { contEntre20e25++; } 
            else { if(idade > 60) { contMaior60++; } }
        }

        if (idade > idadeMaisVelho)
        {
            idadeMaisVelho = idade;
        }
        
    }

    mediaIdades /= i;
    
    printf("\n\n>>> Numero de pessoas maiores de idade: %d.", contMaior);
    printf("\n>>> Numero de pessoas menores de idade: %d.", contMenor);
    printf("\n>>> Numero de pessoas com idade entre 20 e 25 anos: %d.", contEntre20e25);
    printf("\n>>> Numero de pessoas com mais de 60 anos: %d.", contEntre20e25);
    printf("\n>>> Idade da pessoa mais velha: %d.", idadeMaisVelho);
    printf("\n>>> Media das idades: %.1f", mediaIdades);

    if (mediaIdades > 21)
    {
        printf(" (a media e maior que 21).\n\n");
    }
    return 0;
}

// mostre quantos tem idade entre 20 e 25;
// diga quantos tem mais de 60 anos;
// mostre a média das idades;
// diga se esta média é menor que 21;
// (DESAFIO) a idade do mais velho.

