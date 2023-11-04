#include <stdio.h>


int menu_de_relatorios(void)
{
    int resp;
    printf("\nRELATORIOS\n"
           "(1) relatorio por semana\n"
           "(2) relatorio por produtor\n"
           "(3) relatorio de analise de abastecimento\n"
           "(4) finalizar\n\n"
        "Qual relatorio voce deseja conferir? ");
    scanf("%d", &resp);
    return resp;
}

void relatorio_por_semana(int *semana)
{
    printf("De qual semana? ");
    scanf("%d", semana);
    printf("\n\t> Relatorio da Semana %d\n", *semana);
}