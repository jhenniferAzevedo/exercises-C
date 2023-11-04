#include <stdio.h>
#include "header.h"

#define QNT_HORTALICAS 2
#define QNT_SEMANAS 1
#define QNT_PRODUTORES 5

int main(void)
{
    int op, semana, produtor, hortalica, alface = 0, repolho = 1,
                                         semanas_sem_entrega = 0;
    int hortalicas_por_semana[QNT_HORTALICAS][QNT_SEMANAS] = {{0}};
    int hortalicas_por_produtor[QNT_HORTALICAS][QNT_PRODUTORES] = {{0}};
    int numero_de_entregas[QNT_HORTALICAS][QNT_PRODUTORES][QNT_SEMANAS];
    int cont_total_hortalicas = 0, total[QNT_HORTALICAS] = {0};

    /* Leitura dos dados */
    for (semana = 0; semana < QNT_SEMANAS; semana++)
    {
        printf("\n* SEMANA %d *\n", semana + 1);
        for (produtor = 0; produtor < QNT_PRODUTORES; produtor++)
        {
            printf("\n\t* PRODUTOR %d *\n", produtor + 1);
            printf("\t> quantidade de alfaces: ");
            scanf("%d", &numero_de_entregas[alface][produtor][semana]);
            printf("\t> quantidade de repolhos: ");
            scanf("%d", &numero_de_entregas[repolho][produtor][semana]);

            /* Soma das variáveis contadoras de cada relatório */
            for (hortalica = 0; hortalica < QNT_HORTALICAS; hortalica++)
            {
                hortalicas_por_semana[hortalica][semana] +=
                    numero_de_entregas[hortalica][produtor][semana];
                hortalicas_por_produtor[hortalica][produtor] +=
                    numero_de_entregas[hortalica][produtor][semana];
                total[hortalica] += numero_de_entregas[hortalica][produtor][semana];
                cont_total_hortalicas += total[hortalica];
            }

            printf("\nAinda ha produtores? \n(1) sim \n(0) nao\n");
            scanf("%d", &op);

            if (op == 0)
            {
                break;
            }
        }

        if (hortalicas_por_semana[alface][semana] == 0 &&
            hortalicas_por_semana[repolho][semana] == 0)
        {
            semanas_sem_entrega++;
        }
    }

    /* Relatórios */
    do
    {
        switch (menu_de_relatorios())
        {
        case 1:
            printf("De qual semana? ");
            scanf("%d", &semana);
            printf("\n\t> Relatorio da Semana %d\n", semana);
            printf("\tTotal de alfaces entregues: %d\n",
                   hortalicas_por_semana[alface][semana - 1]);
            printf("\tTotal de repolhos entregues: %d\n",
                   hortalicas_por_semana[repolho][semana - 1]);
            break;

        case 2:
            printf("De qual produtor? ");
            scanf("%d", &produtor);
            printf("\n\t Relatorio do Produtor %d\n", produtor);
            printf("\tTotal de alfaces entregues: %d\n",
                   hortalicas_por_produtor[alface][produtor - 1]);
            printf("\tTotal de repolhos entregues: %d\n",
                   hortalicas_por_produtor[repolho][produtor - 1]);
            break;

        case 3:
            printf("A quantidade total de alface e de repolho entregues neste "
                   "periodo foi de %d alfaces e %d hortalicas.",
                   total[alface], total[repolho]);
            if (cont_total_hortalicas < 500)
            {
                printf("\nRisco de desabastecimento!");
            }
            else
            {
                if (total[alface] > 1300 || total[repolho] > 1200)
                {
                    printf("\nSuper producao!");
                }
            }

            if (semanas_sem_entrega == 0)
            {
                printf("\nNao houve nenhuma semana sem entrega.\n");
            }
            else
            {
                printf("\nA quantidade de semanas sem entrega foi: %d\n",
                       semanas_sem_entrega);
            }
            break;

        case 4:
            break;
        default:
            printf("\nvalor invalido! Digite um valor valido\n");
        }
    } while (op != 4);
    
    printf("\nEncerrando o programa...\n");
    return 0;
}