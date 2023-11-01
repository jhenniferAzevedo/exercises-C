#include <stdio.h>
#include "header.h"

int main(void)
{
    int bimestre, resposta;
    DadosDoAluno aluno;

    do
    {
        printf("\nSera que voce passou de ano? Vamos descobrir!\n");
        for (bimestre = 0; bimestre < MAX_BIM; bimestre++)
        {
            printf("\n\t%do BIMESTRE\n", bimestre + 1);

            printf("\t>>> Nota da prova: ");
            scanf("%f", &aluno.NotaProva[bimestre]);

            printf("\t>>> Nota do trabalho: ");
            scanf("%f", &aluno.NotaTrabalho[bimestre]);

            printf("\t>>> Frequencia (%%): ");
            scanf("%f", &aluno.Frequencia[bimestre]);

            aluno.NotaBimestral[bimestre] = CalcularNotaBimestral(&aluno, bimestre);
        }

        aluno.NotaFinal = CalcularNotaFinal(&aluno, MAX_BIM);
        aluno.PorcentFrequencia = CalcularPorcentPresenca(&aluno, MAX_BIM);

        printf("\n\tRelatorios");
        for (bimestre = 0; bimestre < MAX_BIM; bimestre++)
        {
            printf("\n\t- Nota do %do bimestre: %.1f", 
                    bimestre + 1, aluno.NotaBimestral[bimestre]);
        }
        printf("\n\t- Nota final: %.1f", aluno.NotaFinal);
        printf("\n\t- Porcentagem de presencas: %.2f%%\n", aluno.PorcentFrequencia);

        VerificarStatus(&aluno);

        printf("\nAinda ha algum aluno?"
               "\n(1) sim"
               "\n(0) nao \n");
        scanf("%d", &resposta);
    } while (resposta);

    return 0;
}