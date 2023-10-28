/* Um grupo de alunos coletou informações climáticas de uma determinada cidade.
Foram realizadas várias medições de temperatura durante o ano e medições mensais
do índice pluviométrico. Elabore um algoritmo que, dadas estas informações, mostre
a média de temperatura anual e mostre o mês de maior índice pluviométrico. */

#include <stdio.h>

int main(void)
{
    int cont = 0, pluv, maiorPluv = 0;
    float temp, mediaTemp = 0;

    printf("Digite as temperaturas analizadas e finalize digitando 99.\n\n");
    printf("> Temperatura: ");
    scanf("%f", &temp);

    do
    {
        mediaTemp += temp;
        printf("> Temperatura: ");
        scanf("%f", &temp);
        cont++;
    } while (temp != 99);

    printf("\n");
    mediaTemp /= cont;

    printf("Digite os indices pluviometricos mensais analizados.\n\n");

    for (cont = 0; cont < 12; cont++)
    {
        printf("> Indicie Pluviometrico do Mes %d: ", cont + 1);
        scanf("%d", &pluv);

        if (pluv > maiorPluv)
        {
            maiorPluv = pluv;
        }
    }

    printf("\n");
    printf("\n>>> Media das temperaturas: %.1fC", mediaTemp);
    printf("\n>>> Maior indice pluviometrico: %dmm.\n", maiorPluv);
    return 0;
}