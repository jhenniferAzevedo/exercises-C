/* Um banco concederá um crédito especial aos seus clientes de acordo com o saldo médio no último ano. 
Faça um algoritmo que receba o saldo médio de um cliente e calcule o valor do crédito, de acordo com a 
tabela a seguir. Mostre o saldo médio e o valor do crédito. 

Saldo Médio                 Crédito
+$500,00                    30% do saldo médio
de $500,00 a 250,00         10% do saldo médio
-$250,00                    5% do saldo médio */

#include <stdio.h>

int main(void)
{
    float saldo_medio, credito;

    printf("Vamos calcular o quanto de credito esta disponivel para voce.\n");
    printf("Qual foi o seu saldo medio do ultimo ano? R$");
    scanf("%f", &saldo_medio);

    if (saldo_medio > 500)
    {
        credito = saldo_medio*1.3;
        
    }
    else if (saldo_medio >= 250)
    {
        credito = saldo_medio * 1.1;
    }
    else
    {
        credito = saldo_medio * 1.05;
    }

    printf("\nO valor do seu credito e de R$%.2f\n", credito);
    return 0;
}