/* Elabore um algoritmo que receba como entrada nome, peso e idade de três pessoas e
mostre os três nomes, a média das idades e diga se a média dos pesos ultrapassa 55 kg. */

#include <stdio.h>

int main(void)
{
    char pessoa1[20], pessoa2[20], pessoa3[20];
    int idade1, idade2, idade3;
    float media_idades, peso1, peso2, peso3, media_pesos;
    
    /* Leitura dos dados */
    printf("Como voce se chama? ");
    scanf("%s", pessoa1);
    printf("Qual e a sua idade? ");
    scanf("%d", &idade1);
    printf("Qual e o seu peso? ");
    scanf("%f", &peso1);
    
    printf("\nComo voce se chama? ");
    scanf("%s", pessoa2);
    printf("Qual e a sua idade? ");
    scanf("%d", &idade2);
    printf("Qual e o seu peso? ");
    scanf("%f", &peso2);
    
    printf("\nComo voce se chama? ");
    scanf("%s", pessoa3);
    printf("Qual e a sua idade? ");
    scanf("%d", &idade3);
    printf("Qual e o seu peso? ");
    scanf("%f", &peso3);
    
    media_idades = (idade1 + idade2 + idade3) / 3;
    media_pesos = (peso1 + peso2 + peso3) / 3;

    /* Relatório final */
    printf("\nAs pessoas se chamam %s, %s e %s.\n", pessoa1, pessoa2, pessoa3);
    printf("A media das idades e %.1f anos.\n", media_idades);


    if (media_pesos > 55)
    {
        printf("A media dos pesos ultrapassa dos 55kg.\n");
    }
    else
    {
        printf("A media dos pesos esta abaixo dos 55kg.\n");
    }

    return 0;
}