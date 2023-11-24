/* Refaça a prova do dia 13-09 utilizando arrays. Além disso, acrescente o relatório:
    - Dado o dia de auditoria, mostre o PH e as medidas de temperatura aferidas neste dia.
    - Após, forneça a opção do usuário consultar outro dia se ele quiser.
 */

#include <stdio.h>
#include <stdlib.h>

#define QNT_DIAS 3
#define QNT_HORAS 5

int main(void)
{
    char op;
    int hora, dia, contT95 = 0;
    int alertaT = 0, alertaPH = 0, alertaPH8 = 0;
    int temperatura[QNT_DIAS][QNT_HORAS], ph[QNT_DIAS];
    float mediaTemperatura[QNT_DIAS] = {0};

    // Leitura dos dados de cada dia
    dia = 0;
    do
    {
        mediaTemperatura[dia] = 0;

        // Ler o valor do PH
        printf("\n\nDIA DE AUDITORIA %d\n", dia + 1);
        printf("> Valor do ph: ");
        scanf("%d", &ph[dia]);

        if (ph[dia] < 6 || ph[dia] > 8)
        {
            printf("Alerta de PH!\n");
            alertaPH++;

            if (ph[dia] > 8)
            {
                alertaPH8++;
            }
        }

        // Ler o valor das temperaturas
        for (hora = 0; hora < QNT_HORAS; hora++)
        {
            printf("> Valor da temperatura: ");
            scanf("%d", &temperatura[dia][hora]);
            mediaTemperatura[dia] += temperatura[dia][hora];

            if (temperatura[dia][hora] > 90 && temperatura[dia][hora] <= 110)
            {
                printf("Necessita-se de resfriamento.\n");
            }
            else
            {
                if (temperatura[dia][hora] > 110)
                {
                    printf("Alerta de temperatura!\n");
                    alertaT++;
                }
            }
        }

        mediaTemperatura[dia] /= hora;
        printf("\nMEDIA DAS TEMPERATURAS: %.1f", mediaTemperatura[dia]);

        if (mediaTemperatura[dia] > 95)
        {
            contT95++;
        }

        dia++;
        printf("\n\nDeseja continuar com as auditorias? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    // Relatorio final do periodo de auditoria
    printf("\nRELATORIO GERAL\n");
    printf("> Total de dias do periodo de auditoria: %d\n", dia);
    printf("> Total de sinal(is) de alerta emitido(s) por causa do PH acima de 8,0: %d\n", alertaPH8);
    printf("> Total de sinal(is) de alerta emitido(s) por causa da temperatura acima de 110°C: %d\n", alertaT);
    printf("> Quantidade de dias que tiveram a temperatura media acima de 95°C: %d\n", contT95);

    if (alertaPH == 0 && alertaT == 0)
    {
        printf("\nAPROVADO!!");
    }

    // Relatórios do dia que o usuário quiser
    dia = 0;
    printf("\n\nDeseja consultar algum dia? (s) ou (n): ");
    scanf(" %c", &op);

    while (op != 'n')
    {
        printf("Digite o dia de auditoria para consulta: ");
        scanf("%d", &dia);

        printf("\nPH: %d", ph[dia - 1]);
        printf("\nTemperaturas:\n");

        for (hora = 0; hora < QNT_HORAS; hora++)
        {
            printf("> %d hora(s): %d\n", hora, temperatura[dia - 1][hora]);
        }

        printf("\ndeseja consultar outro dia? (s) ou (n): ");
        scanf(" %c", &op);
    }

    system("pause");
    return 0;
}