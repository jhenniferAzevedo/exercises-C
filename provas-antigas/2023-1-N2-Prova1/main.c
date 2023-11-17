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

/*  Ainda falta: 
 *  zerar as variáveis contadoras
 *  conferir se ha algum erro nas funções
 *  adicionar os relatorios finais
 */
