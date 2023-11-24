#include <stdio.h>
#include "header.h"

#define RED_TEXT   "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"

// GUARDANDO NO ARQUIVO EM DISCO --> INCOMPLETE

void read_file(counters_data counter)
{
    FILE *file = fopen("file-on-disk.out", "rb");

    if (file != NULL)
    {
        fread(&counter, sizeof(counters_data), 1, file);
    }
    
    fclose(file);
}

void write_file(counters_data counter)
{
    FILE *fptr = fopen("file-on-disk.out", "wb");
}

// LEITURA DOS DADOS

void read_data(counters_data *counter)
{
    ask_how_many_producers(counter);
    read_data_by_week(counter);
}

void ask_how_many_producers(counters_data *counter)
{
    printf("\nSao quantos produtores? ");
    scanf("%d", &counter->producers);
    check_how_many_producers(counter);
}

void check_how_many_producers(counters_data *counter)
{
    while (counter->producers < 1 || counter->producers > MAX_PRODUC)
    {
        printf(RED_TEXT "\nValor invalido!" RESET_TEXT
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
    scanf("%d", &counter->deliveries[0][n_week][n_producer]);
}

void ask_how_many_cabbage(counters_data *counter,
    int n_week,
    int n_producer)
{
    printf("\t> quantidade de repolhos: ");
    scanf("%d", &counter->deliveries[1][n_week][n_producer]);
}


// RELATÓRIOS

void show_reports(counters_data counter)
{
    int answer;
    do {
        menu_report();
        printf("\nO que voce deseja fazer? ");
        scanf("%d", &answer);
        check_answer(&answer);
        switch (answer)
        {
        case 1:
            report_per_week(counter);
            break;

        case 2:
            report_per_producer(counter);
            break;

        case 3:
            report_per_supply_analysis(counter);
            break;

        case 0:
            printf("\nEncerrando o programa... \n");
            break;
        default:
            printf("\nvalor invalido! Digite um valor valido. \n");
        }
    } while (answer);
}

int menu_report()
{
    printf("\n(0) Finalizar"
           "\n(1) Ver relatorio por semana"
           "\n(2) Ver relatorio por produtor"
           "\n(3) Ver relatorio de analise de abastecimento \n");
}

void check_answer(int *answer)
{
    while (*answer < 0 || *answer > 3)
    {
        printf(RED_TEXT "\nValor invalido!" RESET_TEXT
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
    printf("\tTotal de alfaces: %d\n", counter.lettuce);
    printf("\tTotal de repolhos: %d\n", counter.cabbage);
}

int ask_which_week()
{
    int n_week;
    printf("De qual semana? ");
    scanf("%d", &n_week);
    check_weeks(&n_week);
    return n_week;
}

void check_weeks(int *n_week)
{
    while (*n_week < 1 || *n_week > MAX_WEEK)
    {
        printf(RED_TEXT "\nValor invalido!" RESET_TEXT
               "\nPor favor, digite um valor entre 1 e %d."
               "\n--> ", MAX_WEEK);
        scanf("%d", n_week);
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
    printf("\tTotal de alfaces: %d\n", counter.lettuce);
    printf("\tTotal de repolhos: %d\n", counter.cabbage);
}

int ask_which_producer(counters_data counter)
{
    int n_producer;
    printf("De qual produtor? ");
    scanf("%d", &n_producer);
    check_producer(counter, &n_producer);
    return n_producer;
}

void check_producer(counters_data counter,
     int *n_producer)
{
    while (*n_producer < 1 || *n_producer > counter.producers)
    {
        printf(RED_TEXT "\nValor invalido!" RESET_TEXT
               "\nPor favor, digite um valor entre 1 e %d."
               "\n--> ", counter.producers);
        scanf("%d", n_producer);
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
    printf("A quantidade total de alface e de repolho entregues neste \n"
           "periodo foi de %d alfaces e %d repolhos.",
           counter.lettuce, counter.cabbage);
}

void show_message_by_suply(counters_data counter)
{
    count_total_deliveries(&counter);
    if (counter.total < 500)
    {
        printf(RED_TEXT "\n>>> Risco de desabastecimento!" RESET_TEXT);
    }
    else
    {
        if (counter.lettuce > 1300 || counter.cabbage > 1200)
        {
            printf(RED_TEXT "\n>>> Super producao!" RESET_TEXT);
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
               "%d semana(s)\n", without_delivery);
        return;
    }

    printf(GREEN_TEXT "\nNao houve nenhuma semana sem entrega.\n" RESET_TEXT);
}

int count_weeks_without_delivery(counters_data counter)
{
    int without_delivery = 0;

    for (int i = 0; i < MAX_WEEK; i++)
    {
        for (int j = 0; j < counter.producers; j++)
        {
            if (counter.deliveries[0][i][j] == 0 && 
                counter.deliveries[1][i][j] == 0)
            {
                without_delivery++;
            }
        }
    }

    return without_delivery;
}
