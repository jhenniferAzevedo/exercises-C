/* Elabore um algoritmo que mostre se os índices de glicemia e de HDL de um paciente estão normais ou não. 
Considere que a glicemia normal está abaixo de 110mg/dl e os limites normais de HDL são, para homens, de 30 
à 65 mg /dl e para mulheres, de 35 à 80 mg/dl. */

#include <stdio.h>

int main(void)
{
    int glicemia, hdl, genero;

    printf("Vamos consultar seu indice de glicemia e de HDL.\n");
    printf("  Primeiramente, digite se voce eh (1) homem ou (2) mulher: ");
    scanf("%d", &genero);

    printf("  Qual seu nivel de glicemia (em mg/dl)? ");
    scanf("%d", &glicemia);
    printf("  E de HDL (em mg/dl)? ");
    scanf("%d", &hdl);

    /* Teste de glicemia */
    if (glicemia < 110)
    {
        printf("\n>>> Sua glicemia esta normal.\n");
    }
    else
    {
        printf("\n>>> Sua glicemia esta acima da media!!\n");
    }
    
    /* Teste de HDL */
    if (genero == 2)
    {
        if (hdl > 80)
        {
            printf(">>> Seu HDL esta acima da media!!\n");
        }
        else
        {
            if (hdl>34)
            {
                printf(">>> Seu HDL esta normal.\n");
            }
            else
            {
                printf(">>> Seu HDL esta abaixo da media!!\n");
            }
        }
    }
    else
    {
        if (hdl > 65)
        {
            printf(">>> Seu HDL esta acima da media!!\n");
        }
        else
        {
            if (hdl>29)
            {
                printf(">>> Seu HDL esta normal.\n");
            }
            else
            {
                printf(">>> Seu HDL esta abaixo da media.\n");
            }
        }
    }
    
    return 0;
}