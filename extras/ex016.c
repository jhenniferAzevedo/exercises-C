/* Considere uma cidade pequena que tem 5 postos de saúde, numerados como 0, 1, 2, 3 e 4.
Estes postos aplicaram vacinas para covid durantes os vinte primeiros dias dos meses de janeiro 
à abril, e registraram o número de vacinas aplicadas a cada dia. Faça um programa em linguagem C 
que leia o número de vacinas aplicadas a cada dia e mostre um dos seguintes relatórios:
   - Por posto: dado o número do posto, mostre o número total de vacinas aplicadas neste posto.
   - Por dia: dado o dia e o mês, mostre o número total de vacinas aplicadas neste dia.
   - Por mês: mostre o número total de vacinas aplicadas no mês.
Depois, perguntar ao usuário se deseja imprimir outro relatório. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_MAX_POSTOS 5
#define QNT_MAX_MESES 4
#define QNT_MAX_DIAS 20

int main(void)
{
    int posto, mes, dia, resposta;
    int vacinas[QNT_MAX_POSTOS][QNT_MAX_MESES][QNT_MAX_DIAS];

    /* Variáveis contadoras */
    int vacinas_por_posto[QNT_MAX_POSTOS] = {0};
    int vacinas_por_mes[QNT_MAX_MESES] = {0};
    int vacinas_por_dia[QNT_MAX_DIAS] = {0};

    for (posto = 0; posto < QNT_MAX_POSTOS; posto++)
    {
        printf("\n* POSTO %d *\n", posto);
        for (mes = 0; mes < QNT_MAX_MESES; mes++)
        {
            printf("\n\t> MES %d <\n", mes + 1);
            for (dia = 0; dia < QNT_MAX_DIAS; dia++)
            {
                printf("\t--> Quantidade de vacinas do dia %d: ", dia + 1);
                scanf("%d", &vacinas[posto][mes][dia]);

                vacinas_por_dia[dia] += vacinas[posto][mes][dia];
                vacinas_por_mes[mes] += vacinas[posto][mes][dia];
                vacinas_por_posto[posto] += vacinas[posto][mes][dia];
            }
        }
    }

    system("cls");

    // Relatórios
    printf("\n\tOPCOES DE RELATORIO\n");
    printf("(1) total de vacinas por posto\n");
    printf("(2) total de vacinas por mes\n");
    printf("(3) total de vacinas por dia\n");
    printf("(4) finaliza as verificacoes de relatorios\n");

    printf("\nQual relatorio voce deseja ver? ");
    scanf("%d", &resposta);

    while (resposta != 4)
    {
        switch (resposta)
        {
        case 1:
            printf("De qual posto? ");
            scanf("%d", &posto);
            printf("\n>>> Total de vacinas do posto %d: %d\n", posto, vacinas_por_posto[posto]);
            break;

        case 2:
            printf("De qual mes? ");
            scanf("%d", &mes);
            printf("\n>>> Total de vacinas do mes %d: %d\n", mes, vacinas_por_mes[mes - 1]);
            break;

        case 3:
            printf("De qual dia? ");
            scanf("%d", &dia);
            printf("\n>>> Total de vacinas do dia %d: %d\n", dia, vacinas_por_dia[dia - 1]);
            break;

        case 4: break;
        default:
            printf("\nvalor invalido! digite um numero valido.");
        }

        printf("\nQual relatorio voce deseja ver? ");
        scanf("%d", &resposta);
    }

    printf("\nFinalizando...\n\n");
    system("pause");
    return 0;
}