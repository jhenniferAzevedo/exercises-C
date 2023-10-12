/* Uma agência bancária possui dois tipos de investimentos, conforme o quadro abaixo. 
Faça um algoritmo que receba o tipo do investimento e o valor do investimento e que 
calcule e mostre o valor corrigido de acordo com o tipo de investimento. 
    1. Poupança: rendimento mensal de 4%.
    2. Renda fixa: rendimento mensal de 25%. */

#include <stdio.h>

int main(void)
{
    int resposta;
    float valor, poupanca, renda_fixa;

    printf("OPCOES DE INVESTIMENTO\n");
    printf("(1) poupanca\n");
    printf("(2) renda fixa\n");

    printf("\nPara qual tipo de investimento voce deseja aplicar? ");
    scanf("%d", &resposta);

    printf("Quanto voce ira colocar para investir? R$");
    scanf("%f", &valor);

    if(resposta == 1)
    {
        poupanca = valor * 1.04;
        printf("O valor retornado sera de R$%.2f\n", poupanca);
    }
    else
    {
        renda_fixa = valor * 1.25;
        printf("O valor retornado sera de R$%.2f\n", renda_fixa);
    }
    
    return 0;
}