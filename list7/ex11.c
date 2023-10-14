/* Uma equipe médica está monitorando 400 pacientes que durante 1 ano receberam uma dieta
experimental. A equipe registrou a idade e o sexo de cada paciente e mensalmente eram medidos
para todos os pacientes o nível de colesterol e o nível de vitamina C (valores de colesterol
e vitamina C são do tipo real). Elabore um algoritmo que, após receber os dados de entrada,
informe quantos pacientes tem menos de 25 anos, quantos pacientes tiveram sua média de colesterol
entre 40 e 100, quantas mulheres tiveram a média do seu nível de vitamina C acima de 4, quantos
homens tiveram todas as suas medidas de nível de vitamina C acima de 3. */

#include <stdio.h>
#include <string.h>

#define QNT_MAX_PACIENTES 2
#define QNT_MAX_MESES 12

int main(void)
{
    char sexo_paciente;
    int paciente, mes, idade, vitaminac_abaixo_de_3_M; 
    float colesterol_mensal_por_paciente, vitaminac_mensal_por_paciente;
    float media_colesterol_por_paciente = 0, media_vitaminac_por_paciente = 0;

    /* Variáveis contadoras para cada saída */
    int idade_abaixo_de_25 = 0, colesterol_entre_40_e_100 = 0;
    int media_vitaminac_acima_de_4_F = 0, todas_vitaminasc_acima_de_3_M = 0;

    for (paciente = 0; paciente < QNT_MAX_PACIENTES; paciente++)
    {
        printf("\n* PACIENTE %d *\n", paciente + 1);
        printf("\t> sexo (M)asculino ou (F)eminino: ");
        scanf(" %c", &sexo_paciente);

        printf("\t> idade: ");
        scanf("%d", &idade);

        if (idade < 25)
        {
            idade_abaixo_de_25++;
        }

        printf("\n\tMEDICOES MENSAIS DO NIVEL DE COLESTEROL\n");
        for (mes = 0; mes < 12; mes++)
        {
            printf("\t> nivel de colesterol (mes %d): ", mes + 1);
            scanf("%f", &colesterol_mensal_por_paciente);
            media_colesterol_por_paciente += colesterol_mensal_por_paciente;
        }

        media_colesterol_por_paciente /= mes;
        if (media_colesterol_por_paciente > 40 && media_colesterol_por_paciente < 100)
        {
            colesterol_entre_40_e_100++;
        }

        vitaminac_abaixo_de_3_M = 0;
        printf("\n\tMEDICOES MENSAIS DO NIVEL DE VITAMINA C\n");
        for (mes = 0; mes < 12; mes++)
        {
            printf("\t> nivel de vitamina C (mes %d): ", mes + 1);
            scanf("%f", &vitaminac_mensal_por_paciente);
            media_vitaminac_por_paciente += vitaminac_mensal_por_paciente;

            if ((sexo_paciente == 'M' || sexo_paciente == 'm') && vitaminac_mensal_por_paciente <= 3)
            {
                vitaminac_abaixo_de_3_M++;
            }
        }
        media_vitaminac_por_paciente /= mes;

        if ((sexo_paciente == 'F' || sexo_paciente == 'f') && media_vitaminac_por_paciente > 4)
        {
            media_vitaminac_acima_de_4_F++;
        }
        else
        {
            if (vitaminac_abaixo_de_3_M == 0)
            {
                todas_vitaminasc_acima_de_3_M++;
            }
        }
    }

    printf("\n\t* QUANTIDADE DE *\n");
    printf("  > pacientes com menos de 25 anos: %d.\n", idade_abaixo_de_25);
    printf("  > pacientes que tiveram sua media de colesterol entre 40 e 100: %d.\n", colesterol_entre_40_e_100);
    printf("  > mulheres que tiveram a media do seu nivel de vitamina C acima de 4: %d.\n", media_vitaminac_acima_de_4_F);
    printf("  > homens que tiveram todas as suas medidas do nivel de vitamina C acima de 3: %d.\n", todas_vitaminasc_acima_de_3_M);
    return 0;
}
