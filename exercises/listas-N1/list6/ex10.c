/* Mostre o valor de uma compra, dados os preços de cada produto.
Após, reinicie a execução para uma nova compra. */

#include <stdio.h>

int main(void)
{
    char op;
    float pay, addPay;

    printf("Vamos calcular o valor da sua compra? \nPara finalizar, digite -1.\n");

    do
    {
        printf("\n\t> Valor do produto: R$");
        scanf("%f", &pay);
        addPay = 0;

        do
        {
            addPay += pay;
            printf("\t> Valor do produto: R$");
            scanf("%f", &pay);
        } while (pay != -1);
        
        printf("\n>>> O valor da compra foi de R$%.2f.\n\n", addPay);
        printf("Deseja realizar uma nova compra? \n(s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("\nObrigado por utilizar nossos servicos!\n");
    return 0;
}