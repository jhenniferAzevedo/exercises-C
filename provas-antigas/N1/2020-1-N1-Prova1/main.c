#include <stdio.h>

#define ATLETAS_MAX 10
#define SEMANAS_MAX 8
#define MAX 100

int main(void)
{
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
