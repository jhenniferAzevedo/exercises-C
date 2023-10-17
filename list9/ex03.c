/* 10 atletas foram monitorados por 8 semanas. Para cada atleta foram registrados sua idade e medições semanais de frequência cardíaca e do nível de oxigênio no sangue. Elabore um algoritmo que, dado o número de um atleta, mostre um relatório com seus dados, seu nível médio de oxigênio no sangue e a maior frequência cardíaca registrada durante o período de monitoramento. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_ATLETAS 10
#define QNT_SEMANAS 8

int main(void)
{
    char op;
    int atleta, semana, resposta, idade[QNT_ATLETAS];
    float nivOxigenio[QNT_ATLETAS][QNT_SEMANAS], freqCardiaca[QNT_ATLETAS][QNT_SEMANAS];
    float mediaNivOxigenio[QNT_ATLETAS] = {0}, maiorFreqCardiaca[QNT_ATLETAS] = {0};

    // Ler os dados dos atletas
    for (atleta = 0; atleta < QNT_ATLETAS; atleta++)
    {
        printf("\nMONITORIA DO %do ATLETA\n", atleta + 1);
        printf("\t> idade do atleta: ");
        scanf("%d", &idade[atleta]);

        for (semana = 0; semana < QNT_SEMANAS; semana++)
        {
            printf("\n\t--> SEMANA %d\n", semana + 1);
            printf("\t> frequência cardiaca: ");
            scanf("%f", &freqCardiaca[atleta][semana]);

            if (freqCardiaca[atleta][semana] > maiorFreqCardiaca[atleta])
            {
                maiorFreqCardiaca[atleta] = freqCardiaca[atleta][semana];
            }

            printf("\t> nivel de oxigenio no sangue: ");
            scanf("%f", &nivOxigenio[atleta][semana]);
            mediaNivOxigenio[atleta] += nivOxigenio[atleta][semana];
        }
        mediaNivOxigenio[atleta] /= semana;
    }

    // Relatório dos atletas
    do
    {
        printf("\ndeseja conferir o relatorio de qual atleta? ");
        scanf("%d", &resposta);

        printf("\nvai querer analisar todas as medicoes do nivel de oxigenio e da frequencia cardiaca? (s) ou (n): ");
        scanf(" %c", &op);

        printf("\n\tRELATORIO DO ATLETA %d\n", resposta);

        if (op == 's')
        {
            for (semana = 0; semana < QNT_SEMANAS; semana++)
            {
                printf("\n\t--> semana %d\n", semana + 1);
                printf("\t  frequência cardiaca: %.1f\n", freqCardiaca[resposta - 1][semana]);
                printf("\t  nivel de oxigenio: %.1f\n\n", nivOxigenio[resposta - 1][semana]);
            }
        }

        printf("\t--> nivel medio de oxigenio no sangue: %.1f\n", mediaNivOxigenio[resposta - 1]);
        printf("\t--> maior frequencia cardiaca: %.1f\n\n", maiorFreqCardiaca[resposta - 1]);

        printf("\tainda quer fazer outras verificações? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    system("pause");
    return 0;
}