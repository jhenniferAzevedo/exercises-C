#include <stdio.h>
#include "header.h"

float CalcularNotaBimestral(DadosDoAluno *aluno, int bimestre)
{
    float NotaPorBimestre;
    NotaPorBimestre = (aluno->NotaProva[bimestre] * 6 + 
                       aluno->NotaTrabalho[bimestre] * 4) / 10;
    return NotaPorBimestre;
}

float CalcularNotaFinal(DadosDoAluno *aluno, int TotalBimestres)
{
    int i;
    float ValorFinal = 0;

    for (i = 0; i < TotalBimestres; i++)
    {
        ValorFinal += aluno->NotaBimestral[i];
    }

    ValorFinal /= TotalBimestres;
    return ValorFinal;
}

float CalcularPorcentPresenca(DadosDoAluno *aluno, int TotalBimestres)
{
    int i;
    float Porcent = 0;

    for (i = 0; i < TotalBimestres; i++)
    {
        Porcent += aluno->Frequencia[i];
    }

    Porcent /= TotalBimestres;
    return Porcent;
}

void VerificarStatus(DadosDoAluno *aluno)
{
    if (aluno->NotaFinal >=7 && aluno->PorcentFrequencia >= 75)
    {
        printf("\n\tParabens! Voce foi aprovado.\n");
    }
    else if (aluno->NotaFinal >= 5 && aluno->PorcentFrequencia >= 75)
    {
        printf("\n\tVoce ainda tem uma chance! Boa sorte na recuperacao.\n");
    }
    else
    {
        printf("\n\tOh nao... Voce reprovou. Quem sabe no proximo ano?\n");
    }
}