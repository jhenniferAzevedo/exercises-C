/* Atividade em sala
Considere uma cidade pequena que tem 5 postos de saúde, numerados como 0, 1, 2, 3 e 4.
Estes postos aplicaram vacinas para covid durantes os vinte primeiros dias dos meses de
janeiro à abril, e registraram o número de vacinas aplicadas a cada dia. Leia os dados
de cada mês e, em cada mês, todos os dados de cada posto.

Mostre na tela os seguinte relatórios:
- todas vacinas do mês de janeiro.
- quantas vacinas do mês de fevereiro no posto 1.
- quantas vacinas aplicadas no primeiro dia de março.
- todas as vacinas aplicadas no posto 4, no dia 20 do mês de abril
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_POSTOS 5
#define QNT_MESES 4
#define QNT_DIAS 20

int main(void)
{
    int posto, mes, dia, relatorioVacinas[QNT_MESES] = {0};
    int vacinas[QNT_POSTOS][QNT_MESES][QNT_DIAS];

    for (posto = 0; posto < QNT_POSTOS; posto++)
    {
        printf("\n* POSTO %d *\n", posto);
        for (mes = 0; mes < QNT_MESES; mes++)
        {
            printf("\n\t> MES %d <\n", mes + 1);
            for (dia = 0; dia < QNT_DIAS; dia++)
            {
                printf("\t--> Quantidade de vacinas do dia %d: ", dia + 1);
                scanf("%d", &vacinas[posto][mes][dia]);

                if (mes == 0 || (mes == 1 && posto == 1) || (mes == 2 && dia == 0))
                {
                    relatorioVacinas[mes] += vacinas[posto][mes][dia];
                }
            }
        }
    }

    /* abril */
    relatorioVacinas[3] = vacinas[3][3][19];

    printf("\n\t> total de vacinas do mes de janeiro: %d\n", relatorioVacinas[0]);
    printf("\t> total de vacinas do mes de fevereiro no posto 1: %d\n", relatorioVacinas[1]);
    printf("\t> total de vacinas do primeiro dia de marco: %d\n", relatorioVacinas[2]);
    printf("\t> total de vacinas do dia 20 do mes de abril no posto 4: %d\n\n", relatorioVacinas[3]);
    system("pause");
    return 0;
}