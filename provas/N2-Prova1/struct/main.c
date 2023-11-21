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
        system("cls");
        menu_report();
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            show_general_report(cadastro_veiculo, &contador);
            system("pause");
            break;

        case 2:
            show_report_by_color(cadastro_veiculo, &contador);
            system("pause");
            break;

        case 3:
            show_report_by_code(cadastro_veiculo, &contador);
            system("pause");
            break;
        
        case 4:
            show_report_by_color_and_code(cadastro_veiculo, &contador);
            system("pause");
            break;
        
        case 5:
            add_new_vehicle(cadastro_veiculo, &contador);
            system("pause");
            break;

        case 0:
            printf("\nFinalizando...\n");
            break;
        default:
            printf("\nValor invalido! \nDigite um numero valo.\n");
            system("pause");
            break;
        }
    } while (resp != 0);
}
