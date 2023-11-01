#include <stdio.h>
#include "header.h"

int main(void)
{
    int bimestre, resposta;
    DadosDoAluno aluno;
    aluno.PorcentFrequencia = 0;

    do
    {
        printf("\nVerificando situacao do aluno\n");
        for (bimestre = 0; bimestre < MAX_BIM; bimestre++)
        {
            printf("\n\t%do BIMESTRE\n", bimestre + 1);

            printf("\t>>> Nota da prova: ");
            scanf("%f", &aluno.NotaProva[bimestre]);

            printf("\t>>> Nota do trabalho: ");
            scanf("%f", &aluno.NotaTrabalho[bimestre]);

            printf("\t>>> Frequencia: ");
            scanf("%f", &aluno.FrequenciaBimestral);

            aluno.PorcentFrequencia += aluno.FrequenciaBimestral[bimestre];
            aluno.NotaBimestral[bimestre] = CalcularNotaBimestral(&aluno, bimestre);
        }

    } while (resposta);
    
    kkkkk

    return 0;
}

/*
    Inputs
    > nota das 4 provas para cada um dos 4 bimestres
    > frequencia do aluno

    Outputs
    > as 4 notas bimestrais
    > a nota final
    > porcentagem de presenças
    > "aprovado", "reprovado" ou "fara recuperação"
*/