#include <stdio.h>
#include "header.h"

/* Sem usar variável global. */

int main(void)
{
    int n_veiculo = 0, resp[2];

    int cadastro_veiculo[25][3],
        cor = 0, codigo_veiculo = 1, qntd = 2;

    int contador[5],
        total_cadastros = 0,
        total_veiculos = 1,
        total_veiculos_por_cor = 2,
        total_veiculos_por_codigo = 3,
        total_veiculos_por_codigo_e_cor = 4;
    init_array(contador, 4);
    read_data(cadastro_veiculo, contador);

    float valor;

    do
    {
        resp[0] = 0;
        menu_report();
        scanf("%d", &resp[0]);

        switch (resp[0])
        {
        case 1:
            show_general_report(cadastro_veiculo, contador);
            break;

        case 2:
            show_report_by_color(cadastro_veiculo, contador);
            break;

        case 3:
            show_report_by_code(cadastro_veiculo, contador);
            break;
        
        case 4:
            show_report_by_color_and_code(cadastro_veiculo, contador);
            break;
        
        case 5:
            show_report_by_color_and_code(cadastro_veiculo, contador);
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
