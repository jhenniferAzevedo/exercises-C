#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Todas as constantes utilizadas para facilitar o entendimento:

    --> para o array *registration[][3]*
    const int color = 0;
    const int code_vehicle = 1;
    const int amount = 2;
    const int code_register = 3;

    --> para o array *counter[4]*
    const int total_registers = 0;      MAX 25
    const int total_vehicles = 1;       MAX 150
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

/* LEITURA DOS DADOS */

void read_data(int registration[][4], int counter[])
{
    const int total_registers = 0;
    int n_register = 0, result;
    do {
        printf("\n\tCADASTRO (%d)\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        result = ask_how_many_vehicle(registration, counter, &n_register);
        n_register++;
    } while (n_register < 25 && result != 0);
    counter[total_registers] = n_register;
}

void ask_vehicle_code(int registration[][4], int n_register)
{
    const int code_vehicle = 1;
    printf("\tCodigo do veiculo: ");
    scanf("%d", &registration[n_register][code_vehicle]);
}

void ask_color_code(int registration[][4], int n_register)
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

void check_color_code(int registration[][4], int code_register)
{
    const int color = 0;
    int value = registration[code_register][color];
    while (value < 1 || value > 4)
    {
        printf("\n\tEsse valor e invalido! \n"
               "\tPor favor, digite um numero valido. \n\n"
               "\tCodigo da cor do veiculo: ");
        scanf("%d", &registration[code_register][color]);
        value = registration[code_register][color];
    }
}


int ask_how_many_vehicle(int registration[][4], int counter[], int *n_register)
{
    const int amount = 2;
    int result;
    printf("\tQuantidade de veiculos: ");
    scanf("%d", &registration[*n_register][amount]);
    result = error_handling_of_max_amount(registration, counter, n_register);
    return result;
}

/* RELATÓRIO GERAL */

void count_total_vehicle(int registration[][4], int counter[], int *n_register)
{
    const int amount = 2, total_vehicles = 1;
    counter[total_vehicles] += registration[*n_register][amount];
}

int error_handling_of_max_amount(int registration[][4], int counter[], int *n_register)
{
    const int amount = 2, total_vehicles = 1;
    int status = check_status_garage(counter);
    int amount_register = registration[*n_register][amount];
    int max_counter = 150 - counter[total_vehicles];

    if (status == 0)
    {
        if (amount_register >= 1 && amount_register <= max_counter)
        {
            count_total_vehicle(registration, counter, n_register);
            check_existing_registrations(registration, counter, n_register);
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

    if (counter[total_vehicles] < 150)
    {
        return 0;
    }
    
    if (counter[total_vehicles] == 150)
    {
        return 1;
    }

    return 2;
}

int show_message_by_status_garage(int registration[][4], int counter[], int *n_register, int status)
{
    const int total_vehicles = 1;
    int result = 0, value;
    
    switch (status)
    {
    case 0:
        printf("\nAdicionar novo veiculo? \n"
               "(0) nao \n"
               "(1) sim \n");
        scanf("%d", &result);
        break;
    
    case 1:
        printf("\nValor maximo de veiculos na garagem alcancado.\n"
               "Encerrando cadastro dos veiculos...\n");
        system("pause");
        break;
    
    case 2:
        value = 150 - counter[total_vehicles];
        printf("\n\tValor nao permitido!"
               "\n\tPor favor, digite um valor entre 1 e %d\n", value);
        result = ask_how_many_vehicle(registration, counter, n_register);
    }
    return result;
}

void check_existing_registrations(int registration[][4], int counter[], int *n_register)
{
    const int color = 0, code_vehicle = 1;
    int new_code1 = registration[*n_register][code_vehicle];
    int new_code2 = registration[*n_register][color], i;

    for (i = 0; i < *n_register; i++)
    {
        int old_code1 = registration[i][code_vehicle];
        int old_code2 = registration[i][color];
        if (new_code1 == old_code1 && new_code2 == old_code2)
        {
            add_to_existing_registration(registration, n_register, i);
            *n_register = *n_register - 1;
            return;
        }
    }
}

void add_to_existing_registration(int registration[][4], int *new_register, int old_register)
{
    const int color = 0, code_vehicle = 1, amount = 2;
    int new_amount = registration[*new_register][amount];
    registration[old_register][amount] += new_amount;
}

/* void show_all_vehicles(int registration[][4], int counter[])
{} */

float calculate_garage_percentage(int counter[])
{
    const int total_vehicles = 1;
    float value = counter[total_vehicles];
    value = (value * 100) / 150;
    return value;
}

/* RELATÓRIO POR COR */


/* void main(void)
{
    const int how_many = 2, max_allowed = 150;
    if (registration[n_register][how_many] > 150)
    {
        
    }
} */

/*
void count_vehicles_by_color(int registration[][3], int counter[], n_color)
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

void count_vehicles_by_code(int registration[][3], int counter[], int n_code)
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


