#define MAX_BIM 4
typedef struct DadosDoAluno
{
    float NotaProva[MAX_BIM],
        NotaTrabalho[MAX_BIM],
        NotaBimestral[MAX_BIM],
        Frequencia[MAX_BIM],
        PorcentFrequencia,
        NotaFinal;
} DadosDoAluno;

/* Retorna o valor da nota bimestral com base a nota da prova e do trabalho. */
float CalcularNotaBimestral(DadosDoAluno *, int);

/* Retorna o valor da nota final com base as quatro notas bimestrais. */
float CalcularNotaFinal(DadosDoAluno *, int);

/* Retorna a poprcentagem de presença do aluno com base os quatro bimestres */
float CalcularPorcentPresenca(DadosDoAluno *, int);

/* Verifica e mostra pro usuario se ele passou, fara recuperacao ou esta reprovado */
void VerificarStatus(DadosDoAluno *);
