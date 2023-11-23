/* testing */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEEK 2

typedef struct counters_data
{
    int deliveries[2][MAX_WEEK];
} counters_data;

void check_weeks(int *n_week)
{
    while (*n_week < 1 || *n_week > MAX_WEEK)
    {
        printf("\nValor invalido!"
               "\nPor favor, digite um valor entre 1 e %d."
               "\nDe qual semana? ", MAX_WEEK);
        scanf("%d", n_week);
    }
}

int ask_which_week()
{
    int n_week;
    printf("\nDe qual semana? ");
    scanf("%d", &n_week);
    check_weeks(&n_week);
    return n_week;
}

int count_vegetables_per_week(counters_data counter,
    int n_week)
{
    int total_lettuce = counter.deliveries[0][n_week];
    int total_cabbage = counter.deliveries[1][n_week];
    return total_lettuce, total_cabbage;
}

void report_per_week(counters_data counter)
{
    int lettuce, cabbage;
    int n_week = ask_which_week() - 1;
    lettuce, cabbage = count_vegetables_per_week(counter, n_week);
    printf("\nTotal de alfaces: %d", lettuce);
    printf("\nTotal de repolhos: %d \n", cabbage);
}

void preencher(counters_data *counter)
{
    srand(time(NULL));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            counter->deliveries[j][i] = 1 + rand() % 4;
            printf("\n> test.deliveries[%d][%d] = %d", 
                j, i, counter->deliveries[j][i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    counters_data test;
    preencher(&test);
    report_per_week(test);

    return 0;
}

