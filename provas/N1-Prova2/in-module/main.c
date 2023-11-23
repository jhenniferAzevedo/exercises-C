#include <stdio.h>
#include "header.h"

int main(void)
{
    counters_data contador = {0};
    read_data(&contador);
    int op;

    do {
        op = menu_report();
        switch (op)
        {
        case 1:
            report_per_week(contador);
            break;

        case 2:
            report_per_producer(contador);
            break;

        case 3:
            report_per_supply_analysis(contador);
            break;

        case 0:
            printf("\nEncerrando o programa... \n");
            break;
        default:
            printf("\nvalor invalido! Digite um valor valido. \n");
        }
    } while (op);
    return 0;
}
