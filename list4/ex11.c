/* Calcule o preço a ser pago por uma compra pela internet com as seguintes condições.
    1. Dada a soma dos preços dos itens da compra, 
    o frete será 10% deste valor para a região sul e sudeste 
    e 20% para as demais regiões, 
    mas se a compra for feita em dia de promoção, o frete será grátis. 

    2. Se o cliente for um cliente vip, receberá R$ 100,00 de desconto no valor da compra. 
*/

#include <stdio.h>

int main(void)
{
    char op;
    int cont = 0;
    float compra, compraTotal = 0, frete;
    
    printf("> Digite o valor do produto: R$");
    scanf("%f", &compra);
    
    compraTotal += compra;
    cont++;
    
    printf("Deseja acrescentar mais itens? (s) ou (n): ");
    scanf(" %c", &op); 

    while(op!='n')
    {
        printf("\n> Digite o valor do produto: R$");
        scanf("%f", &compra);
        compraTotal += compra;
        cont++;
        
        printf("Deseja acrescentar mais itens? (s) ou (n): ");
        scanf(" %c", &op);
    }
    
    printf("\n> Hoje e dia de promocao? (s) ou (n): ");
    scanf(" %c", &op);
    
    if(op == 's')
    {
        frete = 0;
    }
    else
    {
        printf("\n> Qual e sua regiao? \n(1) sul \n(2) sudeste \n(3) outra regiao\n");
        scanf(" %c", &op);
        
        if(op == '1' || op == '2')
        {
            frete = compraTotal*0.1;
        }
        else 
        {
            frete = compraTotal*0.2;
        }
    }
    compraTotal += frete;
    
    printf("\n> Voce e cliente vip? (s) ou (n): ");
    scanf(" %c", &op);
    
    /* essa segunda condição está aqui apenas para não resultar em valores negativos */
    if(op == 's' && compraTotal > 100)
    {
        compraTotal -= 100;
    }
    
    printf("\n --> Quantidade de produtos: %d", cont);
    printf("\n --> Valor da compra: R$%.2f\n\n", compraTotal);
    return 0;
}