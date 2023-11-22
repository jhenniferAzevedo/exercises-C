/* Um grupo de alunos coletou informações climáticas de uma determinada cidade.
Foram realizadas várias medições de temperatura durante o ano e medições mensais
do índice pluviométrico. Elabore um algoritmo que, dadas estas informações, mostre
a média anual de temperatura e a média anual de índice pluviométrico. */

#include <stdio.h>

int main(void)
{
    int cont = 0, pluv;
    float temp, mediaTemp = 0, mediaPluv = 0;

    printf("Digite as temperaturas analizadas e finalize digitando 99.\n\n");
    printf("%do. Temperatura: ", cont + 1);
    scanf("%f", &temp);

    do
    {
        cont++;
        mediaTemp += temp;
        printf(">>> %do. Temperatura: ", cont + 1);
        scanf("%f", &temp);
    } while (temp != 99);
    mediaTemp /= cont;

    printf("\nDigite os indices pluviometricos mensais analizados.\n\n");

    for (cont = 0; cont < 12; cont++)
    {
        printf(">>> Indicie Pluviometrico (mes %d): ", cont + 1);
        scanf("%d", &pluv);
        mediaPluv += pluv;
    }
    mediaPluv /= cont;

    printf("\n>>> Media das Temperaturas: %.2fC.", mediaTemp);
    printf("\n>>> Media dos Indices Pluviometricos: %.2fmm.\n", mediaPluv);
    return 0;
}