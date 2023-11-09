#include <stdio.h>

int main(void)
{
    char op;
    int temp, cont, contDias = 0, sinalTemp = 0, sinalPh = 0, sinalPh8 = 0;
    float ph, tempMedia, contTempMedia = 0;

    printf("\n* INICIO DO PERIODO DE AUDITORIA *");
    do
    {
        printf("\tDia %d", contDias + 1);
        contDias++;
        tempMedia = 0;

        printf("\t>>> valor do ph: ");
        scanf("%f", &ph);

        for (cont = 0; cont < 24; cont++)
        {
            printf("\t>>> valor da temperatura: ");
            scanf("%d", &temp);
            tempMedia += temp;
        }

        if (ph < 6 || ph > 8)
        {
            printf("\tAlerta de PH!");
            sinalPh++;
            if (ph > 8)
            {
                sinalPh8++;
            }
        }

        if (temp > 90 && temp <= 110)
        {
            printf("\tNecessita-se de resfriamento.");
        }
        else
        {
            if (temp > 110)
            {
                printf("\tAlerta de temperatura!");
                sinalTemp++;
            }
        }

        tempMedia /= cont;
        printf("%.2f", tempMedia);

        if (tempMedia > 95)
        {
            contTempMedia++;
        }

        printf("\n\n\tDeseja continuar? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("\n>>> O total de dias do periodo de auditoria: %d", contDias);
    printf("\n>>> O total de sinal(is) de alerta emitido(s) por causa do PH acima de 8,0: %d", sinalPh8);
    printf("\n>>> O total de sinal(is) de alerta emitido(s) por causa da temperatura acima de 110°C: %d", sinalTemp);
    printf("\n>>> A quantidade de dias que tiveram temperatura media acima de 95°C: %d\n", contTempMedia);

    if (sinalPh == 0 && sinalTemp == 0)
    {
        printf("\tAprovado!!\n");
    }
    return 0;
}