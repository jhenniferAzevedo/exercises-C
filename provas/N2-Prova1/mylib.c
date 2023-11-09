#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Todas as constantes utilizadas para facilitar o entendimento:

    --> para o array *registration[][3]*
    const int color = 0;
    const int code = 1;
    const int amount = 2;

    --> para o array *counter[4]*
    const int total_registers = 0;
    const int total_vehicles = 1;
    const int vehicles_by_color = 2;
    const int vehicles_by_code = 3;
*/

void init_array(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void read_data(int registration[][3], int counter[], int *total_registrations)
{
    int n_register = 0, result;
    do
    {
        printf("\nCADASTRO (%d)\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        result = ask_how_many_vehicle(registration, counter, n_register);
        n_register++;
    } while (n_register < 25 && result != 0);
    *total_registrations = n_register;
}

/* Lendo as respostas dos usuários. */

void ask_vehicle_code(int registration[][3], int n_register)
{
    const int code = 1;
    printf("\tCodigo do veiculo: ");
    scanf("%d", &registration[n_register][code]);
}

void ask_color_code(int registration[][3], int n_register)
{
    const int color = 0;
    printf("\n\tCores disponiveis \n"
            "\t(1) branco \n"
            "\t(2) preto \n"
            "\t(3) vermelho \n"
            "\t(4) cinza \n");

    printf("\n\tCodigo da cor do veiculo: ");
    scanf("%d", &registration[n_register][color]);
    check_color_code(registration, n_register);
}

void check_color_code(int registration[][3], int n_register)
{
    const int color = 0;
    int value = registration[n_register][color];
    while (value < 1 || value > 4)
    {
        printf("\n\tEsse valor e invalido! \n"
               "\tPor favor, digite um numero valido. \n\n"
               "\tCodigo da cor do veiculo: ");
        scanf("%d", &registration[n_register][color]);
        value = registration[n_register][color];
    }
}

int ask_how_many_vehicle(int registration[][3], int counter[], int n_register)
{
    const int amount = 2;
    int test;
    printf("\tQuantidade de veiculos: ");
    scanf("%d", &registration[n_register][amount]);
    test = error_handling_of_max_amount(registration, counter, n_register);
    return test;
}

void count_total_vehicle(int registration[][3], int counter[], int n_register)
{
    const int amount = 2, total_vehicles = 1;
    counter[total_vehicles] += registration[n_register][amount];
}


int error_handling_of_max_amount(int registration[][3], int counter[], int n_register)
{
    const int amount = 2, total_vehicles = 1;
    int status = check_status_garage(counter);
    int value_register = registration[n_register][amount];
    int max_counter = 150 - counter[total_vehicles];

    if (status == 0)
    {
        if (value_register >= 1 && value_register <= max_counter)
        {
            count_total_vehicle(registration, counter, n_register);
            status = check_status_garage(counter);
        }
        else
        {
            status = 2;
        }
    }
    
    int result = show_message_by_status_garage(registration, counter, n_register, status);
    return result;
}

int check_status_garage(int counter[])
{
    const int total_vehicles = 1;
    int vehicles_so_far = counter[total_vehicles];

    if (vehicles_so_far < 150)
    {
        return 0;
    }
    
    if (vehicles_so_far == 150)
    {
        return 1;
    }

    return 2;
}

int show_message_by_status_garage(int registration[][3], int counter[], int n_register, int status)
{
    const int total_vehicles = 1;
    int answer, value;
    
    switch (status)
    {
    case 0:
        printf("\nAinda ha veiculos? \n"
               "(0) nao \n"
               "(1) sim \n");
        scanf("%d", &answer);
        return answer;
    
    case 1:
        printf("\nValor maximo de veiculos na garagem alcancado.\n"
               "Encerrando cadastro dos veiculos...\n");
        system("pause");
        return 0;
    
    case 2:
        value = 150 - counter[total_vehicles];
        printf("\nVariavel Total: %d", counter[total_vehicles]);
        printf("\n\tGaragem lotada! "
               "\n\tPor favor, digite um valor entre 1 e %d\n", value);
        ask_how_many_vehicle(registration, counter, n_register);
    }
}

/* void main(void)
{
    const int how_many = 2, max_allowed = 150;
    if (registration[n_register][how_many] > 150)
    {
        
    }
} */

/*
void count_vehicle_by_color(int registration[][3], int counter[], n_color)
{
    const int amount = 2, vehicles_by_color = 2;
    counter_max[vehicle_by_color] = 0;
    
    for (i = 0; i < ; i++)
    {
        if (registration[i][color] == n_color)
        {
            counter_max[vehicle_by_color] += registration[i][amount];
        }
    }
}

void count_vehicle_by_code(int registration[][3], int counter[], int n_code)
{
    const int amount = 2, vehicles_by_code = 3;
    counter_max[vehicle_by_code] = 0;

    for (i = 0; i < ; i++)
    {
        if (registration[i][code] == n_code)
        {
            counter_max[vehicle_by_color] += registration[i][amount];
        }
    }
}
*/
