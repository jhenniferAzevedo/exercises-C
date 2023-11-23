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
            printf("\nFinalizando... \n");
            break;
        default:
            printf("\nvalor invalido! Digite um valor valido. \n");
        }
    } while (op);

    printf("\nEncerrando o programa...\n");
    return 0;
}

/* RELATORIOS
- Relatório por semana: dado a semana, mostrar a quantidade de alface e de
repolho entregues nesta semana.

- Relatório por produtor: dado o produtor, mostrar a quantidade de alface e de
repolho entregues no período por este produtor.

- Relatório de análise de abastecimento:
  * Mostre a quantidade total de alface e de repolho entregues no período.
  * Se a quantidade total de hortaliças for inferior a 500, emita um sinal
de “Risco de desabastecimento” Se a quantidade de alface for superior a 1300 ou
a quantidade de repolho for superior a 1200, emita um sinal de “Super produção”
  * Diga também se houve alguma semana no período que não houve entregas.

Após imprimir um relatório, oferecer a opção para o usurário imprimir outro
relatório se desejar.
*/
