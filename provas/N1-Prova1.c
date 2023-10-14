/* Na fabricação de um determinado produto químico, existe a necessidade de auditorias periódicas
para análise de risco. Durante uma auditoria, o auditor faz medidas de temperatura e de PH do
produto durante sua fabricação por um número indeterminado de dias. A cada dia afere-se o PH
um vez e afere-se a temperatura a cada hora. O PH desejável é de 6,0 a 8,0 e a temperatura
normal é no máximo 90°C.

Escreva um algoritmo que, para cada dia de auditoria, receba como entrada o PH e as medidas de
temperaturas. Caso o PH esteja fora do desejável, deve-se emitir um sinal de alerta. Caso a
temperatura esteja acima do normal e até 110°C, emita uma solicitação de resfriamento. Caso a
temperatura ultrapasse 110°C, emita um sinal de alerta.

No final de um dia de auditoria, mostre a temperatura média deste dia e pergunte ao auditor se
quer continuar a auditoria por mais um dia.

Ao final do período de auditoria, mostre o seguinte relatório:
    * Número de dias do período;
    * Quantas vezes um sinal de aleta foi emitido por causa do PH acima de 8,0;
    * Quantas vezes um sinal de aleta foi emitido por causa da temperatura acima de 110°C;
    * Quantos dias tiveram temperatura média acima de 95°C;
    * Emitir a mensagem “Aprovado” caso não tenha ocorrido nenhum sinal de alerta.
Obs.:
- Fazer declaração de todas as variáveis
- Usar "fimse", "fimpara", ..., para finalizar os blocos
- Usar a endentação para organizar o código */

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