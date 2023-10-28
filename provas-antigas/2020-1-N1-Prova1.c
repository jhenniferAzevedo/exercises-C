/* Atividade Avaliativa N1 – 2020/1 17/11/2020 *1A*
10 atletas foram monitorados por 8 semanas. Para cada atleta foram registrados sua idade, 
várias medições do nível de oxigênio no sangue e medições semanais de frequência cardíaca. 
Elabore um algoritmo que, para cada atleta, mostre seu nível médio de oxigênio no sangue e 
a maior frequência cardíaca registrada durante o período de monitoramento. No final mostre 
ainda quantos tiveram a média de oxigênio no sangue abaixo de 96 e a percentagem de atletas 
com mais de 25 anos e a percentagem com menos de 16 anos. obs.: Na leitura das medições de 
nível de oxigênio no sangue, utilize o valor -1 para indicar que a sequência de medições 
finalizou (o valor -1 na entrada é o código para a parada da estrutura de repetição e não 
deve ser processado). Considere que os valores de nível de oxigênio e frequência cardíaca 
são valores reais. */

#include <stdio.h>

int main(void)
{
    const int ATLETAS_MAX = 10, SEMANAS_MAX = 8, MAX = 100;

    int atleta, semana, nivOxigenio[MAX][ATLETAS_MAX], contOx,
        freqCardiaca[SEMANAS_MAX][ATLETAS_MAX], idade[ATLETAS_MAX], 
        maiorFreqCardiaca[ATLETAS_MAX], contOxMenor96 = 0,
        porcentIdadesMaior25 = 0, porcentIdadesMenor16 = 0;
    float mediaNivOxigenio[ATLETAS_MAX];

    for (atleta = 0; atleta < ATLETAS_MAX; atleta++)
    {
        printf("\n* ATLETA %d *\n", atleta + 1);
        printf("\t>>> idade: ");
        scanf("%d", &idade[atleta]);

        if (idade[atleta] > 25) { porcentIdadesMaior25++; }
        else if (idade[atleta] < 16) { porcentIdadesMenor16++; }

        contOx = 0;
        printf("\n\tMEDICOES DO NIVEL DE OXIGENIO (finalize com -1)\n");
        printf("\t> nivel de oxigenio (%d): ", contOx + 1);
        scanf("%d", &nivOxigenio[contOx][atleta]);

        mediaNivOxigenio[atleta] = 0;
        do
        {
            mediaNivOxigenio[atleta] += nivOxigenio[contOx][atleta];
            contOx++;
            printf("\t> nivel de oxigenio (%d): ", contOx + 1);
            scanf("%d", &nivOxigenio[contOx][atleta]);
        } while (nivOxigenio[contOx][atleta] != -1);
        mediaNivOxigenio[atleta] /= contOx;

        if (mediaNivOxigenio[atleta] < 96) { contOxMenor96++; }

        maiorFreqCardiaca[atleta] = 0;
        printf("\n\tMEDICOES SEMANAIS DA FREQUENCIA CARDIACA\n");
        for (semana = 0; semana < SEMANAS_MAX; semana++)
        {
            printf("\t> frequencia cardiaca (%d): ", semana + 1);
            scanf("%d", &freqCardiaca[semana][atleta]);
            
            if (freqCardiaca[semana][atleta] > maiorFreqCardiaca[atleta])
            {
                maiorFreqCardiaca[atleta] = freqCardiaca[semana][atleta];
            }
        }

        printf("\n\n>>> sua media dos niveis de oxigenio: %.1f\n", mediaNivOxigenio[atleta]);
        printf(">>> sua maior frequencia cardiaca: %d\n\n", maiorFreqCardiaca[atleta]);
    }
    porcentIdadesMaior25 = (porcentIdadesMaior25 * 100) / ATLETAS_MAX;
    porcentIdadesMenor16 = (porcentIdadesMenor16 * 100) / ATLETAS_MAX;

    printf("\n>>> total de medias de oxigenio abaixo de 96: %d\n", contOxMenor96);
    printf(">>> porcentagem de atletas com mais de 25 anos: %d%%\n", porcentIdadesMaior25);
    printf(">>> porcentagem de atletas com menos de 16 anos: %d%%\n", porcentIdadesMenor16);
    return 0;
}


/*
inputs 
- idade
- várias medições do nível de oxigênio
- medições semanais de frequência cardíaca

outputs para cada atleta
- média do nível de oxigênio
- maior frequência cardíaca

outputs finais
- total de médias de oxigênio abaixo de 96
- proncentagem de atletas com mais de 25 anos
- proncentagem de atletas com menos de 16 anos
*/