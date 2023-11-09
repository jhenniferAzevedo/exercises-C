#include <stdio.h>
#include "header.h"

/* Sem usar variável global. */

/* Variaveis que precisam ser inicializadas:
 * Todas as contadoras;
 * 
 */

int main(void)
{
    const int MAX_CADASTROS = 25;
    const int MAX_VEICULOS = 150;
    int n_veiculo = 0, total_registro, resp;

    int cadastro_veiculo[MAX_CADASTROS][3],
        cor = 0, codigo = 1, qntd = 2;

    int contador[4],
        total_cadastros = 0,
        total_veiculos = 1,
        total_veiculos_por_cor = 2,
        total_veiculos_por_codigo = 3;
    init_array(contador, 4);
    read_data(cadastro_veiculo, contador, &total_registro);

    do
    {
        printf("\nRELATORIOS\n"
               "(0) Finalizar \n"
               "(1) Relatorio geral \n"
               "(2) Relatorio por cor \n"
               "(3) Relatorio por codigo \n");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            /*
                mostre todos os veículos e seus dados;
                mostre a quantidade total de veículos;
                mostre a percentagem de ocupação das garagens;
            */
            for (n_veiculo = 0; n_veiculo < total_registro; n_veiculo++)
            {
                printf("\nCadastro %d\n"
                       "Codigo do veiculo: %d\n"
                       "Codigo da cor do veiculo: %d\n"
                       "Quantidade do veiculo: %d\n",
                       n_veiculo + 1,
                       cadastro_veiculo[n_veiculo][codigo],
                       cadastro_veiculo[n_veiculo][cor],
                       cadastro_veiculo[n_veiculo][qntd]);
            }
            /* printf("\nTotal de veiculos: %d");
            printf("\nPorcentagem de ocupacao da garagem: "); */
            break;

        case 2:
            /*
                mostre a quantidade total e todos os veículos desta cor
            */
            printf("Qual a cor que deseja conferir? ");
            scanf("%d", &resp);
            printf("Quantidade total de veiculos: ");
            break;

        case 3:
            printf("Qual o codigo que deseja conferir? ");
            scanf("%d", &resp);
            /*
                mostre a quantidade total e todos os veículos com o código e seus dados),
                busca por veículo (Dados o código do veículo e sua cor, mostre a quantidade.
                Se o veículo for encontrado, a busca deve ser interrompida).
            */
            break;

        case 0:
            printf("\nFinalizando programa...\n");
            break;
        default:
            printf("\nValor invalido! \nDigite um numero valo.\n");
            break;
        }
    } while (resp != 0);
}

/*  Ideia: 
 *  para conferir se já existe um código de veículo com a mesma cor, 
 *  criar um novo código que será a junção entre o código do veículo
 *  e o código da cor. 
 *  
 *  Exemplo:
 *  codigo do veiculo 1342 
 *  codigo da cor 4
 *  codigo do cadastro 13424
 *  
 *  Se houver outro 13424, ele conta como sendo o mesmo cadastro e soma
 *  a quantidade pra esse código específico.
 */
