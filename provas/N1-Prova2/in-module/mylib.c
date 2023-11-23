/* alface = 0; repolho = 1 */

#include <stdio.h>
#include "header.h"

// LEITURA DOS DADOS

void read_data(counters_data *counter)
{
    ask_how_many_producers(counter);
    read_data_by_week(counter);
}

void ask_how_many_producers(counters_data *counter)
{
    printf("\nSao quantos produtores? ");
    scanf("%d", counter->producers);
    check_how_many_producers(counter);
}

void check_how_many_producers(counters_data *counter)
{
    while (counter->producers < 1 || counter->producers > MAX_PRODUTORES)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d.",
               MAX_PRODUTORES);
        ask_how_many_producers(counter);
    }
}

void read_data_by_week(counters_data *counter)
{
    for (int n_week = 0; n_week < MAX_SEMANAS; n_week++)
    {
        printf("\n* SEMANA %d *\n", n_week + 1);
        read_data_by_producer(counter, n_week);
    }
}

void read_data_by_producer(counters_data *counter,
    int n_week)
{
    for (int n_producer = 0; n_producer < counter->producers; n_producer++)
    {
        printf("\n\t* PRODUTOR %d *\n", n_producer + 1);
        ask_how_many_lettuce(counter, n_week, n_producer);
        ask_how_many_cabbage(counter, n_week, n_producer);
    }
}

void ask_how_many_lettuce(counters_data *counter,
    int n_week,
    int n_producer)
{
    printf("\t> quantidade de alfaces: ");
    scanf("%d", counter->deliveries[0][n_week][n_producer]);
}

void ask_how_many_cabbage(counters_data *counter,
    int n_week,
    int n_producer)
{
    printf("\t> quantidade de repolhos: ");
    scanf("%d", counter->deliveries[1][n_week][n_producer]);
}


// RELATÓRIO POR SEMANA 

void report_per_week(counters_data *counter)
{
    int n_week = ask_which_week(counter) - 1;
    count_vegetables_per_week(counter, n_week);
    printf("Total de alfaces: %d", 
        counter->vegetables_per_week[0][n_week]);
    printf("Total de repolhos: %d", 
        counter->vegetables_per_week[1][n_week]);
}

int ask_which_week(counters_data *counter)
{
    int n_week;
    printf("\nDe qual semana? ");
    scanf("%d", &n_week);
    check_weeks(&n_week);
    return n_week;
}

void check_weeks(int *n_week)
{
    while (*n_week < 1 || *n_week > MAX_SEMANAS)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d."
               "\nDe qual semana? ",
               MAX_SEMANAS);
        scanf("%d", n_week);
    }
}

void count_vegetables_per_week(counters_data *counter,
    int n_week)
{
    for (int n_producer = 0; n_producer < counter->producers; n_producer++)
    {
        counter->vegetables_per_week[0][n_week] += 
            counter->deliveries[0][n_week][n_producer];
        counter->vegetables_per_week[1][n_week] += 
            counter->deliveries[1][n_week][n_producer];
    }
}


// RELATÓRIO POR PRODUTOR 

void report_per_producer(counters_data *counter)
{
    int n_producer = ask_which_producer(counter) - 1;
    count_vegetables_per_producer(counter, n_producer);
    printf("Total de alfaces: %d", 
        counter->vegetables_per_week[0][n_producer]);
    printf("Total de repolhos: %d", 
        counter->vegetables_per_week[1][n_producer]);
}

int ask_which_week(counters_data *counter)
{
    int n_producer;
    printf("\nDe qual semana? ");
    scanf("%d", &n_producer);
    check_weeks(&n_producer);
    return n_producer;
}

void check_producer(counters_data *counter,
     int *n_producer)
{
    while (*n_producer < 1 || *n_producer > counter->producers)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d."
               "\nDe qual semana? ",
               counter->producers);
        scanf("%d", n_producer);
    }
}

void count_vegetables_per_producer(counters_data *counter,
    int n_producer)
{
    for (int n_week = 0; n_week < MAX_SEMANAS; n_week++)
    {
        counter->vegetables_per_producer[0][n_producer] += 
            counter->deliveries[0][n_week][n_producer];
        counter->vegetables_per_producer[1][n_producer] += 
            counter->deliveries[1][n_week][n_producer];
    }
}


// RELATÓRIO DE ANÁLIDE DE ABASTECIMENTO

void supply_analysis_report(counters_data *counter)
{
}

void show_total_delivery(counters_data *counter)
{
}

show_total_vegetables(counters_data *counter)
{
}





void check_weeks_without_delivery(counters_data *counter)
{
    if (hortalicas_por_semana[alface][semana] == 0 &&
        hortalicas_por_semana[repolho][semana] == 0)
    {
        semanas_sem_entrega++;
    }
}

/* Mostre a quantidade total de alface e de repolho entregues no período;
 * Se a quantidade total de hortaliças for inferior a 500, emita um sinal
 * de “Risco de desabastecimento”;
 * Se a quantidade de alface for superior a 1300 ou a quantidade de repolho
 * for superior a 1200, emita um sinal de “Super produção”;
 * Diga também se houve alguma semana no período que não houve entregas.
 */

/*
    for (hortalica = 0; hortalica < QNT_MAX_HORTALICAS; hortalica++)
    {
        hortalicas_por_produtor[hortalica][produtor] +=
            numero_de_entregas[hortalica][produtor][semana];
        total[hortalica] += numero_de_entregas[hortalica][produtor][semana];
        cont_total_hortalicas += total[hortalica];
    }
*/