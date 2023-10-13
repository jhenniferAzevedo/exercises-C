/* Mostre o valor de uma compra, dados os preços de cada produto */

#include <stdio.h>

int main(void)
{
    float pay, addPay;

    printf("Vamos calcular o valor da sua compra? \nPara finalizar, digite -1.\n\n");

    printf("\t> Valor do produto: R$");
    scanf("%f", &pay);
    addPay = 0;

    do
    {
        addPay += pay;
        printf("\t> Valor do produto: R$");
        scanf("%f", &pay);
    } while (pay != -1);
    
    printf("\n>>> O valor da compra foi de R$%.2f.\n", addPay);   
    printf("Obrigado por utilizar nossos servicos!\n");
    return 0;
}