#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    int opcao;
    int opniao_do_cliente[MAX_PERGUNTAS][MAX_DIAS][MAX_CLIENTES];
    form_data relatorio;
    relatorio.total_clientes = 0;

    ler_dados_diarios(opniao_do_cliente, relatorio);

    do
    {
        switch (opcao)
        {
        case 1:
            /* code */
            break;
        
        case 2:
            /* code */
            break;
        
        case 3:
            /* code */
            break;
        
        case 4:
            /* code */
            break;
        
        case 5:
            /* code */
            break;
        
        case 0:
            /* code */
            break;
        
        default:
            break;
        }
    } while (opcao != 0);
    printf("\nQual relatorio deseja consultar? \n");
    scanf("%d", &opcao);
    return 0;
}

/*  Uma loja fará uma consulta de opinião com seus clientes por 5 dias. A cada dia no máximo
 *  20 clientes serão questionados (não receber o número de clientes como entrada):
 * 
 *  1. Encontrou o que procurava?
 *  2. Ficou satisfeito?
 * 
 *  Faça um programa em linguagem C que leia as respostas dos clientes e, após as leituras,
 *  mostre um destes relatórios:
 * 
 *  - Relatório por dia: dado o dia, mostrar todas as respostas deste dia. ✓
 *  - Relatório por pergunta: dada a pergunta, mostre a percentagem de respostas “sim” e a
 *    percentagem de respostas “não”. ✓
 *  - Relatório por cliente: dados o número do cliente e o dia, mostre as respostas; ✓
 *  - Relatório geral:
 *      + mostre quantos clientes foram consultados ✓
 *      + quantos responderam “não” para a duas questões ✓
 *      + quantos estão satisfeitos ✓
 *      + a percentagem de clientes que encontraram o que procuravam no 5° dia de pesquisa ✓
 *  Após imprimir um relatório, oferecer a opção para o usurário imprimir outro relatório se
 *  desejar.
 */
