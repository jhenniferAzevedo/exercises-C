/* Exemplo de media (prof que fez) */

#include <stdio.h>

void main(void)
{
    int idade, cont = 0;
    float media = 0;
    char op;

    do
    {
        printf("\nDigite a idade: ");
        scanf("%d", &idade);
        media = media +idade;
        cont++;
        
        if (idade>=18)
        {
            printf("Maior de idade.");
        }
        else
        {
            printf("Menor de idade.");
        }

        printf("\nContinuar? s ou n ");
        scanf(" %c", &op);
    }
    while (op != 'n');
    
	printf("\n\nA media de idades eh %f\n", media/cont);
}