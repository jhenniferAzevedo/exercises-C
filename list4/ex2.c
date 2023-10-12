/* Elabore um algoritmo que mostre o tipo de eleitor (obrigatório, opcional ou não eleitor) de acordo com sua idade. */

#include <stdio.h>

int main(void)
{
    int idade;
    
    printf("Qual e sua idade? ");
    scanf("%d", &idade);

    if (idade < 16)
    {
        printf("\nVoce ainda nao pode votar...\n");
    }
    else
    {
        if (idade < 18)
        {
            printf("\nVotar e opcional.\n");
        }
        else
        {
            printf("\nObrigatorio votar!\n");
        }
    }

    return 0;
}