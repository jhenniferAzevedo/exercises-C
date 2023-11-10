#include <stdio.h>
#include "header.h"

/* Sem usar variável global. */

int main(void)
{
    int n_veiculo = 0, resp[2];

    int cadastro_veiculo[25][4],
        cor = 0, codigo_veiculo = 1, qntd = 2, codigo_cadastro = 3;

    int contador[4],
        total_cadastros = 0,
        total_veiculos = 1,
        total_veiculos_por_cor = 2,
        total_veiculos_por_codigo = 3;
    init_array(contador, 4);
    read_data(cadastro_veiculo, contador);

    float valor;

    do
    {
        resp[0] = 0;
        printf("\n\nOPCOES\n"
               "(0) Finalizar programa \n"
               "(1) Relatorio geral \n"
               "(2) Relatorio por cor \n"
               "(3) Relatorio por codigo \n"
               "(4) Relatorio por veiculo \n"
               "(5) Adicionar um veiculo \n");
        scanf("%d", &resp[0]);

        switch (resp[0])
        {
        case 1:
            /*
                mostre todos os veículos e seus dados;
                mostre a quantidade total de veículos;
                mostre a percentagem de ocupação das garagens;
            */
            for (n_veiculo = 0; n_veiculo < contador[total_cadastros]; n_veiculo++)
            {
                printf("\n\n>>> Cadastro %d\n"
                       "Codigo do veiculo: %d\n"
                       "Codigo da cor do veiculo: %d\n"
                       "Quantidade do veiculo: %d\n",
                       n_veiculo + 1,
                       cadastro_veiculo[n_veiculo][codigo_veiculo],
                       cadastro_veiculo[n_veiculo][cor],
                       cadastro_veiculo[n_veiculo][qntd]);
            }
            printf("\n>>> Total de veiculos: %d", contador[total_veiculos]);

            valor = calculate_garage_percentage(contador);
            printf("\n>>> Porcentagem de ocupacao: %.2f%%\n", valor);
            /* printf("\nTotal de veiculos: %d");
            printf("\nPorcentagem de ocupacao da garagem: "); */
            break;

        case 2:
            /*
                mostre a quantidade total e todos os veículos desta cor
            */
            printf("Qual a cor que voce deseja conferir? ");
            scanf("%d", &resp[0]);
            printf("Quantidade total de veiculos: %d\n", contador[total_veiculos_por_cor]);
            printf("\nTodos os veículos da cor X\n");
            for (n_veiculo = 0; n_veiculo < contador[total_cadastros]; n_veiculo++)
            {
                printf("\nCadastro %d\n"
                       "Codigo do veiculo: %d\n"
                       "Quantidade do veiculo: %d\n",
                       n_veiculo + 1,
                       cadastro_veiculo[n_veiculo][codigo_veiculo],
                       cadastro_veiculo[n_veiculo][qntd]);
            }
            break;

        case 3:
            printf("Qual o codigo que voce deseja conferir? ");
            scanf("%d", &resp[0]);
            /*
                mostre a quantidade total e todos os veículos com o código e seus dados),
            */
            break;
        
        case 4:
            printf("Qual o codigo que voce deseja conferir? ");
            scanf("%d", &resp[codigo_veiculo]);
            printf("E qual cor? ");
            scanf("%d", &resp[cor]);
            /*
                busca por veículo (Dados o código do veículo e sua cor, mostre a quantidade.
                Se o veículo for encontrado, a busca deve ser interrompida).
            */
            /* printf("total: %d\n", cadastro_veiculo[resp[]][--resp]); */
            break;

        case 0:
            printf("\nFinalizando...\n");
            break;
        default:
            printf("\nValor invalido! \nDigite um numero valo.\n");
            break;
        }
    } while (resp[0] != 0);
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
