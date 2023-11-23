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
    while (counter->producers < 1 || counter->producers > MAX_PRODUC)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d.",
               MAX_PRODUC);
        ask_how_many_producers(counter);
    }
}

void read_data_by_week(counters_data *counter)
{
    for (int n_week = 0; n_week < MAX_WEEK; n_week++)
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


// RELATÓRIOS

int menu_report()
{
    int answer;
    printf("\n(0) Finalizar"
           "\n(1) Relatorio por semana"
           "\n(2) Relatorio por produtor"
           "\n(3) Relatorio de analise de abastecimento \n"
           "\nO que voce deseja? ");
    scanf("%d", &answer);
    check_answer(&answer);
    return answer;
}

void check_answer(int *answer)
{
    while (*answer < 0 || *answer > 3)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 0 e 3."
               "\nO que voce deseja? ");
        scanf("%d", answer);
    }
}

// RELATÓRIO POR SEMANA 

void report_per_week(counters_data counter)
{
    int n_week = ask_which_week() - 1;
    count_vegetables_per_week(&counter, n_week);
    printf("\n\t> Relatorio da Semana %d\n", ++n_week);
    printf("\nTotal de alfaces: %d", counter.lettuce);
    printf("\nTotal de repolhos: %d", counter.cabbage);
}

int ask_which_week()
{
    int n_week;
    printf("\nDe qual semana? ");
    scanf("%d", &n_week);
    check_weeks(&n_week);
    return n_week;
}

void check_weeks(int *n_week)
{
    while (*n_week < 1 || *n_week > MAX_WEEK)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d.", 
               MAX_WEEK);
        ask_which_week();
    }
}

void count_vegetables_per_week(counters_data *counter,
    int n_week)
{
    for (int j = 0; j < counter->producers; j++)
    {
        counter->lettuce += counter->deliveries[0][n_week][j];
        counter->cabbage += counter->deliveries[1][n_week][j];
    }
}

// RELATÓRIO POR PRODUTOR 

void report_per_producer(counters_data counter)
{
    int n_producer = ask_which_producer(counter) - 1;
    count_vegetables_per_producer(&counter, n_producer);
    printf("\n\t> Relatorio do Produtor %d\n", ++n_producer);
    printf("\nTotal de alfaces: %d", counter.lettuce);
    printf("\nTotal de repolhos: %d", counter.cabbage);
}

int ask_which_producer(counters_data counter)
{
    int n_producer;
    printf("\nDe qual produtor? ");
    scanf("%d", &n_producer);
    check_producer(counter, &n_producer);
    return n_producer;
}

void check_producer(counters_data counter,
     int *n_producer)
{
    while (*n_producer < 1 || *n_producer > counter.producers)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d.",
               counter.producers);
        ask_which_producer(counter);
    }
}

void count_vegetables_per_producer(counters_data *counter,
    int n_producer)
{
    for (int i = 0; i < MAX_WEEK; i++)
    {
        counter->lettuce += counter->deliveries[0][i][n_producer];
        counter->cabbage += counter->deliveries[1][i][n_producer];
    }
}


// RELATÓRIO DA ANÁLIDE DE ABASTECIMENTO

void report_per_supply_analysis(counters_data counter)
{
    count_total_vegetables(&counter);
    show_total_vegetables(counter);
    show_message_by_suply(counter);
    show_message_by_weeks_without_delivery(counter);
}

void count_total_vegetables(counters_data *counter)
{
    for (int i = 0; i < MAX_WEEK; i++)
    {
        for (int j = 0; j < counter->producers; j++)
        {
            counter->lettuce += counter->deliveries[0][i][j];
            counter->cabbage += counter->deliveries[1][i][j];
        }
    }
}

void show_total_vegetables(counters_data counter)
{
    printf("A quantidade total de alface e de repolho entregues neste "
           "periodo foi de %d alfaces e %d hortalicas.",
           counter.lettuce, counter.lettuce);
}

void show_message_by_suply(counters_data counter)
{
    count_total_deliveries(&counter);
    if (counter.total < 500)
    {
        printf("\nRisco de desabastecimento!");
    }
    else
    {
        if (counter.lettuce > 1300 || counter.cabbage > 1200)
        {
            printf("\nSuper producao!");
        }
    }
}

void count_total_deliveries(counters_data *counter)
{
    counter->total = counter->lettuce + counter->cabbage;
}

void show_message_by_weeks_without_delivery(counters_data counter)
{
    int without_delivery = count_weeks_without_delivery(counter);
    
    if (without_delivery)
    {
        printf("\nA quantidade de semanas sem entrega foi: "
           "%d \n", without_delivery);
        return;
    }

    printf("\nNao houve nenhuma semana sem entrega.\n");
}

int count_weeks_without_delivery(counters_data counter)
{
    int without_delivery = 0;

    for (int i = 0; i < MAX_WEEK; i++)
    {
        count_vegetables_per_week(&counter, i);
        if (counter.lettuce == 0 && counter.cabbage == 0)
        {
            without_delivery++;
        }
    }

    return without_delivery;
}
