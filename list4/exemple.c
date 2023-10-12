/* FLUXO DE CAIXA (prof que fez) */

/*
   O código abaixo descreve o funcionamento de um comércio online.
   Primeiramente, o programa solicita um valor de depósito. Em seguida,
   descreve as opções de produtos disponíveis e seus valores. Após a
   seleção do produto, você poderá digitar a quantidade que deseja
   comprar. Feito isso, a compra será efetuada, custo total e saldo
   restante seram informados.
*/

/* Condições
   - Se você tentar realizar a compra e seu saldo inicial for **menor ou igual** a zero,
     o programa retornará a seguinte mensagem: 'Voce nao tem saldo suficiente para realizar a compra'

   - Se o produto selecionado for **diferente** dos produtos listados,
     o programa retornará a seguinte mensagem: 'Desculpe, o produto nao esta disponivel no momento'

   - Se a quantidade informada for **menor ou igual** a zero,
     o programa retornará a seguinte mensagem: 'Por favor, insira um valor maior que zero'

   - Se o custo total da compra (custo = valor do produto * quantidade), for **maior** que o saldo inicial informado,
     o programa retornará a seguinte mensagem: 'Voce nao tem saldo suficiente para realizar a compra'.
*/

#include <stdio.h>

int main(void)
{
    int carteira, quantidade, produto, saldo, custo;

    printf("Conveniencia Online\n");
    printf("\nDigite o valor do deposito.\n");
    scanf("%i", &carteira);
    printf("Seu saldo eh: %i\n", carteira);
    printf("Qual produto deseja adicionar ao carrinho? Selecione apenas um numero por vez.\n");
    printf("Temos:\n 1- Refrigerante = R$ 8,00 \n 2- Energetico  = R$ 10,00\n 3- Cerveja = R$ 5,00\n 4- Agua = R$ 1,00\n");
    scanf("%i", &produto);

    if (produto == 1 || produto == 2 || produto == 3 || produto == 4)
    {
        printf("Escolha a quantidade:\n");
        scanf("%i", &quantidade);
    }
    else
    {
        printf("Desculpe, o produto nao esta disponivel no momento.\n");
        return 0;
    }

    if (produto == 1)
    {
        custo = 8 * quantidade;
    }
    else
    {
        if (produto == 2)
        {
            custo = 10 * quantidade;
        }
        else
        {
            if (produto == 3)
            {
                custo = 5 * quantidade;
            }

            if (produto == 4)
            {
                custo = 1 * quantidade;
            }
        }
    }

    if (custo > carteira)
    {
        printf("\nVoce nao tem saldo suficiente para realizar a compra.");
        return 0;
    }

    if (quantidade <= 0)
    {
        printf("\nPor favor, insira um valor maior que zero.");
        return 0;
    }

    printf("\nCompra realizada com sucesso!");
    printf("\nCusto total:%i", custo);
    saldo = carteira - custo;
    printf("\nSaldo restante:%i", saldo);
    return 0;
}