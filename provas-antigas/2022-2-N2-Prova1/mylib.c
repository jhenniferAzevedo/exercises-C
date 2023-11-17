#include <stdio.h>
#include "header.h"

function()
{}

// Leitura dos dados

void read_data(order_data client[])
{
    for (int n_cliente = 0; n_cliente < MAX_CLIENT; n_cliente++)
    {
        printf("\nCLIENTE (%d)\n", n_cliente + 1);
        read_client_data(client, n_cliente);
    }
}

void read_client_data(order_data client[], int n_client)
{
    for (int n_order = 0; n_order < MAX_ORDERS; n_order++)
    {
        printf("\n\tPEDIDO (%d)\n", n_order + 1);
        read_product_data(client, n_client, n_order);
    }
}

void read_product_data(order_data client[], int n_client, int n_order)
{
    int n_product, total_products;
    total_products = ask_what_products_user_wants();
    /* check(); */
}

void show_product_available(void)
{
    printf("\tTemos essas opcoes de produtos disponíveis: \n"
           "\t(1) AC3 20kg \n"
           "\t(2) AC2 20kg \n"
           "\t(3) Rejunte 5kg \n\n");
}

int ask_what_products_user_wants(void)
{
    int answer;
    show_product_available();
    printf("\tQuantos desses produtos voce deseja? \n"
           "\t(1) Apenas um dos produtos. \n"
           "\t(2) Dois dos produtos. \n"
           "\t(3) Todos os tres produtos. \n");
    scanf("%d", answer);
    check_answer(&answer);
    return answer;
}

void check_answer(int *answer)
{
    while (*answer < 1 && *answer > 3)
    {
        printf("\n\tValor invalido!"
               "\n\tDigite um numero valido."
               "\n\tQual opcao voce deseja? ");
        scanf("%d", answer);
    }
}

int show_option_(int answer)
{
    switch (answer)
    {
    case 1:
        return 1;
        break;
    
    default:
        break;
    }
}

int check(order_data client[], int n_client, int n_order)
{
    int answer;
    int product1, product2, product3;
    int amount1, amount2, amount3;
    switch (answer)
    {
    case 1:
    /*
        printf("\tQual produto? ");
        scanf("%d", product1);
        check_answer(&answer);

        printf("\tQual a quantidade? ");
        scanf("%d", &client[n_client].qntd_do_produto[answer][n_order]);

        ask_how_many_products1(); 
        return;
    */
    case 2:
    /*
        printf("\tQual e o primeiro produto? ");
        scanf("%d", &product1);
        check_answer(&product1);

        printf("\tQual a quantidade? ");
        scanf("%d", &amount1);

        printf("\tQual e o segundo produto? \n");
        scanf("%d", &product2);
        check_answer(&product2);

        printf("\tQual a quantidade? ");
        scanf("%d", &amount1);

        ask_how_many_products2();
        return 2, product1, product2;
    */
    case 3:
    /*
        check_answer(&product1);
        check_answer(&product2);
        check_answer(&product3);
        ask_how_many_products3();
        return 3;
    */
    }
}

void ask_how_many_products1(int answer)
{
    int value, product;
    /* value, product = check(answer); */
}

void ask_how_many_products2(int answer)
{
    int value, p1, p2;
    /* value, p1, p2 = check(answer); */
}

void ask_how_many_products3(int answer)
{}

