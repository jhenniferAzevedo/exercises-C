#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* LEITURA DOS DADOS */

void read_data(register_data registration[], 
    counter_data *counter)
{
    int n_register = 0, result;
    do
    {
        printf("\n\tCADASTRO (%d)\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        result = ask_how_many_vehicle(registration, counter, &n_register);
        n_register++;
    } while (n_register < 25 && result);
    counter->total_registers = n_register;
}

void ask_vehicle_code(register_data registration[], 
    int n_register)
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

void ask_color_code(register_data registration[], 
    int n_register)
{
    menu_colors();
    printf("\n\tCodigo da cor do veiculo: ");
    scanf("%d", &registration[n_register].color);
    check_color_code(&registration[n_register].color);
}

void check_color_code(int *value_color)
{
    while (*value_color < 1 || *value_color > 4)
    {
        printf(RED_TEXT "\n\tEsse valor e invalido! \n" RESET_TEXT
               "\tPor favor, digite um numero valido. \n\n"
               "\tCodigo da cor do veiculo: ");
        scanf("%d", value_color);
    }
}

int ask_how_many_vehicle(register_data registration[], 
    counter_data *counter, 
    int *n_register)
{
    int result;
    printf("\tQuantidade de veiculos: ");
    scanf("%d", &registration[*n_register].amount);
    result = error_handling_of_max_amount(registration, counter, n_register);
    return result;
}

void count_total_vehicle(register_data registration[], 
    counter_data *counter, 
    int *n_register)
{
    counter->total_vehicles += registration[*n_register].amount;
}

int error_handling_of_max_amount(register_data registration[], 
    counter_data *counter, 
    int *n_register)
{
    int status = check_status_garage(counter);
    int amount_register = registration[*n_register].amount;
    int max_counter = 150 - counter->total_vehicles;

    if (!status)
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

int check_status_garage(counter_data *counter)
{
    if (counter->total_vehicles < 150)
    {
        return 0;
    }

    if (counter->total_vehicles == 150)
    {
        return 1;
    }

    return 2;
}

int show_message_by_status_garage(register_data registration[], 
    counter_data *counter, 
    int *n_register, 
    int status)
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
        printf(RED_TEXT 
               "\nValor maximo de veiculos na garagem alcancado.\n"
               RESET_TEXT
               "Encerrando cadastro dos veiculos...\n");
        break;

    case 2:
        value = 150 - counter->total_vehicles;
        printf(RED_TEXT "\n\tValor nao permitido!" RESET_TEXT
               "\n\tPor favor, digite um valor entre 1 e %d\n",
               value);
        result = ask_how_many_vehicle(registration, counter, n_register);
    }
    return result;
}

void check_existing_registrations(register_data registration[], 
    counter_data *counter, 
    int *n_register)
{
    int new_code = registration[*n_register].code;
    int new_color = registration[*n_register].color;
    count_total_vehicle(registration, counter, n_register);

    for (int i = 0; i < *n_register; i++)
    {
        int old_code = registration[i].code;
        int old_color = registration[i].color;
        if (new_code == old_code && new_color == old_color)
        {
            add_to_existing_registration(registration, n_register, i);
            *n_register = *n_register - 1;
            return;
        }
    }
}

void add_to_existing_registration(register_data registration[], 
    int *new_register, 
    int old_register)
{
    int new_amount = registration[*new_register].amount;
    registration[old_register].amount += new_amount;
}

/* RELATÓRIOS */

void menu_report(int *answer)
{
    printf("\n\nOPCOES\n"
           "(0) Finalizar programa \n"
           "(1) Relatorio geral \n"
           "(2) Relatorio por cor \n"
           "(3) Relatorio por codigo \n"
           "(4) Relatorio por veiculo \n"
           "(5) Adicionar um veiculo \n");
    scanf("%d", answer);
}

void menu_register(register_data registration[], int i)
{
    printf(GREEN_TEXT "\n>>> Cadastro %d\n" RESET_TEXT
           "Codigo do veiculo: %d\n"
           "Codigo da cor do veiculo: %d\n"
           "Quantidade do veiculo: %d\n",
           i + 1,
           registration[i].code,
           registration[i].color,
           registration[i].amount);
}

void check_vehicles(int amount)
{
    if (!amount)
    {
        printf(RED_TEXT "\nERROR: Cadastro inexistente!\n" RESET_TEXT);
        return;
    }
    printf("\n>>> Total de veiculos: %d\n", amount);
}

void pause_and_clear(void)
{
    printf("\nDigite qualquer tecla para continuar...");
    getchar();
    getchar();
    system("clear");
}

void show_reports(register_data registration[], 
    counter_data *counter)
{
    int answer;
    do {
        menu_report(&answer);
        system("clear");

        switch (answer)
        {
        case 1:
            show_general_report(registration, counter);
            pause_and_clear();
            break;

        case 2:
            show_report_by_color(registration, counter);
            pause_and_clear();
            break;

        case 3:
            show_report_by_code(registration, counter);
            pause_and_clear();
            break;
        
        case 4:
            show_report_by_color_and_code(registration, counter);
            pause_and_clear();
            break;
        
        case 5:
            add_new_vehicle(registration, counter);
            pause_and_clear();
            break;

        case 0:
            printf(GREEN_TEXT 
                    "\nFinalizando...\n"
                   RESET_TEXT);
            break;
        default:
            printf(RED_TEXT
                    "\nValor invalido! \nDigite um numero valido.\n"
                   RESET_TEXT);
            pause_and_clear();
            break;
        }
    } while (answer);
}

/* RELATÓRIO GERAL */ 

void show_general_report(register_data registration[], 
    counter_data *counter)
{
    show_all_vehicles(registration, counter);
    printf("\n>>> Total de veiculos: %d", counter->total_vehicles);
    float value = calculate_garage_percentage(counter);
    printf("\n>>> Porcentagem de ocupacao: %.2f%%\n", value);
}

void show_all_vehicles(register_data registration[], 
    counter_data *counter)
{
    for (int i = 0; i < counter->total_registers; i++)
    {
        menu_register(registration, i);
    }
}

float calculate_garage_percentage(counter_data *counter)
{
    float value = counter->total_vehicles;
    value = (value * 100) / 150;
    return value;
}

/* RELATÓRIO POR COR */

void show_report_by_color(register_data registration[], 
    counter_data *counter)
{
    int n_color;

    menu_colors();
    printf("\nDe qual cor? ");
    scanf("%d", &n_color);
    check_color_code(&n_color);

    show_vehicles_by_color(registration, counter, n_color);
    count_vehicles_by_color(registration, counter, n_color);
    check_vehicles(counter->vehicles_by_color);
}

void show_vehicles_by_color(register_data registration[], 
    counter_data *counter, 
    int n_color)
{
    for (int i = 0; i < counter->total_registers; i++)
    {
        if (registration[i].color == n_color)
        {
            menu_register(registration, i);
        }
    }
}

void count_vehicles_by_color(register_data registration[], 
    counter_data *counter, 
    int n_color)
{
    counter->vehicles_by_color = 0;
    for (int i = 0; i < counter->total_registers; i++)
    {
        if (registration[i].color == n_color)
        {
            counter->vehicles_by_color += registration[i].amount;
        }
    }
}

/* RELATÓRIO POR CÓDIGO */

void show_report_by_code(register_data registration[], 
    counter_data *counter)
{
    int n_code;
    printf("\nDe qual codigo? ");
    scanf("%d", &n_code);

    show_vehicles_by_code(registration, counter, n_code);
    count_vehicles_by_code(registration, counter, n_code);
    check_vehicles(counter->vehicles_by_code);
}

void show_vehicles_by_code(register_data registration[], 
    counter_data *counter, 
    int n_code)
{
    for (int i = 0; i < counter->total_registers; i++)
    {
        if (registration[i].code == n_code)
        {
            menu_register(registration, i);
        }
    }
}

void count_vehicles_by_code(register_data registration[], 
    counter_data *counter, 
    int n_code)
{
    counter->vehicles_by_code = 0;
    for (int i = 0; i < counter->total_registers; i++)
    {
        if (registration[i].code == n_code)
        {
            counter->vehicles_by_code += registration[i].amount;
        }
    }
}

/* RELATÓRIO POR CÓDIGO E COR */

void show_report_by_color_and_code(register_data registration[], 
    counter_data *counter)
{
    int n_color;
    int n_code;

    menu_colors();
    printf("\nDe qual cor? ");
    scanf("%d", &n_color);
    check_color_code(&n_color);

    printf("\nDe qual codigo? ");
    scanf("%d", &n_code);

    find_register(registration, counter, n_color, n_code);
}

void find_register(register_data registration[], 
    counter_data *counter, 
    int n_color, 
    int n_code)
{
    counter->vehicles_by_code_and_color = 0;
    for (int i = 0; i < counter->total_registers; i++)
    {
        int color_value = registration[i].color;
        int code_value = registration[i].code;
        if (color_value == n_color && code_value == n_code)
        {
            menu_register(registration, i);
            return;
        }
    }
    check_vehicles(0);
}

/* 5. INSERIR NOVO VEÍCULO */

void add_new_vehicle(register_data registration[], 
    counter_data *counter)
{
    int n_register = counter->total_registers;
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
        printf(RED_TEXT
                "\n\tNumero maximo de registros alcancado.\n"
               RESET_TEXT);
    }
    counter->total_registers = n_register;
}
