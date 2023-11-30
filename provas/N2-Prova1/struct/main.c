#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int resp;
    register_data cadastro_veiculo[25];
    counter_data contador = {0};
    read_data(cadastro_veiculo, &contador);

    do
    {
        menu_report();
        scanf("%d", &resp);
        system("clear");

        switch (resp)
        {
        case 1:
            show_general_report(cadastro_veiculo, &contador);
            pause_and_clear();
            break;

        case 2:
            show_report_by_color(cadastro_veiculo, &contador);
            pause_and_clear();
            break;

        case 3:
            show_report_by_code(cadastro_veiculo, &contador);
            pause_and_clear();
            break;
        
        case 4:
            show_report_by_color_and_code(cadastro_veiculo, &contador);
            pause_and_clear();
            break;
        
        case 5:
            add_new_vehicle(cadastro_veiculo, &contador);
            pause_and_clear();
            break;

        case 0:
            printf("\nFinalizando...\n");
            break;
        default:
            printf("\nValor invalido! \nDigite um numero valo.\n");
            pause_and_clear();
            break;
        }
    } while (resp != 0);
}
