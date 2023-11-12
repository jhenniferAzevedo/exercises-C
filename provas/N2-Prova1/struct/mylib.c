#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* Todas as constantes utilizadas para facilitar o entendimento:

    --> para o array *registration[25][3]*
    const int color = 0;
    const int code_vehicle = 1;
    const int amount = 2;

    --> para o array *counter[5]*
    const int total_registers = 0;      MAX 25
    const int total_vehicles = 1;       MAX 150
    const int vehicles_by_color = 2;
    const int vehicles_by_code = 3;
    const int vehicles_by_color_and_code = 4;
*/

void init_array(counter_data name_struct, int size)
{
    
    name_struct.total_registers = 0;
    name_struct.total_vehicles = 0;
    name_struct.vehicles_by_code = 0;
    name_struct.vehicles_by_color = 0;
    name_struct.vehicles_by_code_and_color = 0;
}

/* LEITURA DOS DADOS */

void read_data(register_data registration[], counter_data counter)
{
    int n_register = 0, result;
    do
    {
        printf("\n\tCADASTRO (%d)\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        result = ask_how_many_vehicle(registration, counter, &n_register);
        n_register++;
    } while (n_register < 25 && result != 0);
    counter.total_registers = n_register;
}

void ask_vehicle_code(register_data registration[], int n_register)
{
    printf("\tCodigo do veiculo: ");
    scanf("%d", &registration[n_register].code);
}

void menu_colors(void)
{
    printf("\n\tCores disponiveis \n"
           "\t(1) branco \n"
           "\t(2) preto \n"
           "\t(3) vermelho \n"
           "\t(4) cinza \n");
}

void ask_color_code(register_data registration[], int n_register)
{
    menu_colors();
    printf("\n\tCodigo da cor do veiculo: ");
    scanf("%d", &registration[n_register].code);
    check_color_code(&registration[n_register].color);
}

void check_color_code(int *value_color)
{
    while (*value_color < 1 || *value_color > 4)
    {
        printf("\n\tEsse valor e invalido! \n"
               "\tPor favor, digite um numero valido. \n\n"
               "\tCodigo da cor do veiculo: ");
        scanf("%d", value_color);
    }
}

int ask_how_many_vehicle(register_data registration[], counter_data counter, int *n_register)
{
    int result;
    printf("\tQuantidade de veiculos: ");
    scanf("%d", &registration[*n_register].amount);
    result = error_handling_of_max_amount(registration, counter, n_register);
    return result;
}

void count_total_vehicle(register_data registration[], counter_data counter, int *n_register)
{
    counter.total_vehicles += registration[*n_register].amount;
}

int error_handling_of_max_amount(register_data registration[], counter_data counter, int *n_register)
{
    int status = check_status_garage(counter);
    int amount_register = registration[*n_register].amount;
    int max_counter = 150 - counter.total_vehicles;

    if (status == 0)
    {
        if (amount_register >= 1 && amount_register <= max_counter)
        {
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

int check_status_garage(counter_data counter)
{
    if (counter.total_vehicles < 150)
    {
        return 0;
    }

    if (counter.total_vehicles == 150)
    {
        return 1;
    }

    return 2;
}

int show_message_by_status_garage(register_data registration[], counter_data counter, int *n_register, int status)
{
    int result = 0, value;

    switch (status)
    {
    case 0:
        printf("\nAdicionar mais algum novo veiculo? \n"
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
        value = 150 - counter.total_vehicles;
        printf("\n\tValor nao permitido!"
               "\n\tPor favor, digite um valor entre 1 e %d\n",
               value);
        result = ask_how_many_vehicle(registration, counter, n_register);
    }
    return result;
}

void check_existing_registrations(register_data registration[], counter_data counter, int *n_register)
{
    int new_code1 = registration[*n_register].code;
    int new_code2 = registration[*n_register].color;
    count_total_vehicle(registration, counter, n_register);

    for (int i = 0; i < *n_register; i++)
    {
        int old_code1 = registration[i].code;
        int old_code2 = registration[i].color;
        if (new_code1 == old_code1 && new_code2 == old_code2)
        {
            add_to_existing_registration(registration, n_register, i);
            *n_register = *n_register - 1;
            return;
        }
    }
}

void add_to_existing_registration(register_data registration[], int *new_register, int old_register)
{
    const int amount = 2;
    int new_amount = registration[*new_register].amount;
    registration[old_register].amount += new_amount;
}

/* RELATÓRIOS */

void menu_report(void)
{
    printf("\n\nOPCOES\n"
           "(0) Finalizar programa \n"
           "(1) Relatorio geral \n"
           "(2) Relatorio por cor \n"
           "(3) Relatorio por codigo \n"
           "(4) Relatorio por veiculo \n"
           "(5) Adicionar um veiculo \n");
}

void menu_register(register_data registration[], int i)
{
    printf("\n>>> Cadastro %d\n"
           "Codigo do veiculo: %d\n"
           "Codigo da cor do veiculo: %d\n"
           "Quantidade do veiculo: %d\n",
           i + 1,
           registration[i].code,
           registration[i].color,
           registration[i].amount);
}

/* 1. RELATÓRIO GERAL */

void show_general_report(register_data registration[], counter_data counter)
{
    show_all_vehicles(registration, counter);
    printf("\n>>> Total de veiculos: %d", counter.total_vehicles);
    float value = calculate_garage_percentage(counter);
    printf("\n>>> Porcentagem de ocupacao: %.2f%%\n", value);
}

void show_all_vehicles(register_data registration[], counter_data counter)
{
    for (int i = 0; i < counter.total_registers; i++)
    {
        menu_register(registration, i);
    }
}

float calculate_garage_percentage(counter_data counter)
{
    float value = counter.total_vehicles;
    value = (value * 100) / 150;
    return value;
}

/* 2. RELATÓRIO POR COR */

void show_report_by_color(register_data registration[], counter_data counter)
{
    int n_color;

    menu_colors();
    printf("\nDe qual cor? ");
    scanf("%d", &n_color);
    check_color_code(&n_color);

    show_vehicles_by_color(registration, counter, n_color);
    count_vehicles_by_color(registration, counter, n_color);

    printf("\n>>> Total de veiculos: %d", counter.vehicles_by_color);
}

void show_vehicles_by_color(register_data registration[], counter_data counter, int n_color)
{
    for (int i = 0; i < counter.total_registers; i++)
    {
        if (registration[i].color == n_color)
        {
            menu_register(registration, i);
        }
    }
}

void count_vehicles_by_color(register_data registration[], counter_data counter, int n_color)
{
    counter.vehicles_by_color = 0;
    for (int i = 0; i < counter.total_registers; i++)
    {
        if (registration[i].color == n_color)
        {
            counter.vehicles_by_color += registration[i].amount;
        }
    }
}

/* 3. RELATÓRIO POR CÓDIGO */

void show_report_by_code(register_data registration[], counter_data counter)
{
    int n_code;
    printf("\nDe qual codigo? ");
    scanf("%d", &n_code);

    show_vehicles_by_code(registration, counter, n_code);
    count_vehicles_by_code(registration, counter, n_code);

    printf("\n>>> Total de veiculos: %d\n", counter.vehicles_by_code);
}

void show_vehicles_by_code(register_data registration[], counter_data counter, int n_code)
{
    for (int i = 0; i < counter.total_registers; i++)
    {
        if (registration[i].code == n_code)
        {
            menu_register(registration, i);
        }
    }
}

void count_vehicles_by_code(register_data registration[], counter_data counter, int n_code)
{
    counter.vehicles_by_code = 0;
    for (int i = 0; i < counter.total_registers; i++)
    {
        if (registration[i].code == n_code)
        {
            counter.vehicles_by_code += registration[i].amount;
        }
    }
}

/* 4. RELATÓRIO POR CÓDIGO E COR */

void show_report_by_color_and_code(register_data registration[], counter_data counter)
{
    int n_color;
    int n_code;

    menu_colors();
    printf("\nDe qual cor? ");
    scanf("%d", &n_color);
    check_color_code(&n_color);

    printf("De qual codigo? ");
    scanf("%d", &n_code);

    find_register(registration, counter, n_color, n_code);
}

void find_register(register_data registration[], counter_data counter, int n_color, int n_code)
{
    counter.vehicles_by_code_and_color = 0;
    for (int i = 0; i < counter.total_registers; i++)
    {
        int color_value = registration[i].color;
        int code_value = registration[i].code;
        if (color_value == n_color && code_value == n_code)
        {
            menu_register(registration, i);
            return;
        }
    }
}

/* 5. INSERIR NOVO VEÍCULO */

void add_new_vehicle(register_data registration[], counter_data counter)
{
    int n_register = counter.total_registers;
    int status = check_status_garage(counter);

    if (n_register < 25 && status == 0)
    {
        printf("\n\tCadastro %d\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        registration[n_register].amount = 1;
        check_existing_registrations(registration, counter, &n_register);
        n_register++;
    }
    else
    {
        printf("\n\tNumero maximo de registros alcancado.\n");
    }
    counter.total_registers = n_register;
}
