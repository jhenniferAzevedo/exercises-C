#include <stdio.h>
#include "header.h"

void ler_dados_diarios(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    int n_dia;
    forms.total_clientes = 0;

    for (n_dia = 0; n_dia < MAX_DIAS; n_dia++)
    {
        printf("\nDIA %d\n", n_dia + 1);
        ler_dados_cliente(resp_usuario, forms, n_dia);
    }
}

void ler_dados_cliente(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms, int n_dia)
{
    int n_cliente = 0, opcao;
    do
    {
        printf("\n\tCLIENTE %d\n", n_cliente + 1);
        ask_question1(resp_usuario, n_cliente, n_dia);
        ask_question2(resp_usuario, n_cliente, n_dia);
        
        n_cliente++;
        printf("Ainda ha clientes? ");
        scanf("%d", &opcao);
    } while (n_cliente < MAX_CLIENTES && opcao != 1);
    forms.total_clientes += n_cliente;
}

void ask_question1(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], int n_cliente, int n_dia)
{
    printf("\t> Encontrou o que procurava? ");
    scanf("%d", &resp_usuario[0][n_dia][n_cliente]);
}

void ask_question2(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], int n_cliente, int n_dia)
{
    printf("\t> Ficou satisfeito? ");
    scanf("%d", &resp_usuario[1][n_dia][n_cliente]);
}

void calcular_dados(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    cont_qnts_encontraram(resp_usuario, forms);
    cont_qnts_satisfeitos(resp_usuario, forms);
    cont_ambas_respostas_nao(resp_usuario, forms);
    calcula_porcent(forms);
    cont_satisfeitos_dia_5(resp_usuario, forms);
}

void cont_qnts_encontraram(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    int n_dia, n_cliente;
    for (n_dia = 0; n_dia < MAX_DIAS; n_dia++) {
        for (n_cliente = 0; n_cliente < forms.total_clientes; n_cliente++) {
            if (resp_usuario[0][n_dia][n_cliente]) {
                forms.qnts_encontraram++;
            }
        }
    }
}

void cont_qnts_satisfeitos(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    int n_dia, n_cliente;
    for (n_dia = 0; n_dia < MAX_DIAS; n_dia++) {
        for (n_cliente = 0; n_cliente < forms.total_clientes; n_cliente++) {
            if (resp_usuario[1][n_dia][n_cliente]) {
                forms.qnts_satisfeitos++;
            }
        }
    }
}

void cont_ambas_respostas_nao(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    int n_dia, n_cliente;
    for (n_dia = 0; n_dia < MAX_DIAS; n_dia++) {
        for (n_cliente = 0; n_cliente < forms.total_clientes; n_cliente++) {
            if (resp_usuario[0][n_dia][n_cliente] == 0 &&
                resp_usuario[1][n_dia][n_cliente] == 0)
            {
                forms.ambas_respostas_nao++;
            }
        }
    }
}

void calcula_porcent(form_data forms)
{
    forms.porcent_sims = (forms.qnts_encontraram + forms.qnts_satisfeitos) * 100;
    forms.porcent_sims /= forms.total_clientes;
    forms.porcent_naos = 100 - forms.porcent_sims;
}

void cont_encontraram_no_dia_5(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms)
{
    int n_cliente;
    for (n_cliente = 0; n_cliente < forms.total_clientes; n_cliente++) {
        if (resp_usuario[0][4][n_cliente]) {
            forms.percent_clientes_satisfeitos_5_dia++;
        }
    }
    forms.percent_clientes_satisfeitos_5_dia *= 100;
    forms.percent_clientes_satisfeitos_5_dia /= forms.total_clientes;
}

void mostrar_menu(void)
{
    printf("\nQual relatorio deseja consultar? \n"
           "(0) finalizar\n"
           "(1) todas as respostas do dia \n"
           "(2) percentagem de respostas 'sim' e a percentagem de respostas 'não' \n"
           "(3) percentagem de respostas 'sim' e a percentagem de respostas 'não' \n"
           "(4) consultar as respostas do cliente \n"
           "(5) relatorio geral \n");
}
