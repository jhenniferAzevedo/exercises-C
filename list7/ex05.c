/* Uma agência de turismo oferece pacotes com as seguintes condições:
    a. Estadia: R$ 100,00 a cada dia por pessoa.
    b. Cada passagem: R$ 50,00 por milha de distância.
    c. Translado aeroporto-hotel: R$ 60,00 o grupo.
    d. Se o grupo tiver de 4 a 9 pessoas, recebe um desconto de 5% no total do pacote.
    e. Se o grupo tiver 10 ou mais, recebe um desconto de 10% no total do pacote.
    f. Elabore um algoritmo para calcular o preço final do pacote.
    g. No final perguntar se o cliente quer fazer outro orçamento.
*/

#include <stdio.h>

int main(void)
{
    char op;
    int qntDias, qntPessoas, estadia, servicoBusca;
    float distanciaMilhas, valorPassagem, desconto, precoTotal;
    printf("Bem vindo a Agencia de Turismo!! Vamos comecar a fazer seu orcamento.\n ");

    do
    {
        printf("\n\t> Quantidade de dias de estadia: ");
        scanf("%d", &qntDias);

        printf("\t> Quantidade de pessoas: ");
        scanf("%d", &qntPessoas);

        estadia = qntDias * qntPessoas * 100;

        printf("\t> Valor da distancia em milhas: ");
        scanf("%f", &distanciaMilhas);
        valorPassagem = qntPessoas * distanciaMilhas * 50;

        printf("\t> Pretende constratar o servico Traslado Aeroporto-Hotel? (s) ou (n): ");
        scanf(" %c", &op);

        servicoBusca = 0;
        if (op == 's')
        {
            servicoBusca = 60;
        }

        desconto = 1;
        if (qntPessoas >= 4 && qntPessoas <= 9)
        {
            desconto = 0.95;
        }
        else
        {
            if (qntPessoas >= 10)
            {
                desconto = 0.9;
            }
        }

        precoTotal = (estadia + valorPassagem + servicoBusca) * desconto;
        printf("\n>>> Preco final do pacote: R$%.2f\n", precoTotal);

        printf("Deseja realizar outro orcamento? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("\nObrigado por utilizar nossos servicos!!\n");
    return 0;
}