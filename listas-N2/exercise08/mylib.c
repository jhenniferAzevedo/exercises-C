#include <stdio.h>
#include "header.h"

float CalcularNotaBimestral(DadosDoAluno *aluno, int bimestre)
{
    float NotaBimestral;
    NotaBimestral = (aluno->NotaProva[bimestre] * 6 + aluno->NotaTrabalho[bimestre] * 4) / 10;
    return NotaBimestral;
}

float CalcularNotaFinal(float notaBimestral[], int tam)
{

}