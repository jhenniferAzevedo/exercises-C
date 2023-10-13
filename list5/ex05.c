/* Mostre a média final de cada aluno, de uma turma de 10 alunos, e diga se
ele passou direto (media ≥ 7,0) ou não, dadas as notas de 1º e de 2º bimestres. */

#include <stdio.h>

int main(void)
{
    float nota1, nota2, media;
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("\n\nALUNO %d\n", i + 1);
        printf("\t> quanto voce tirou no primeiro bimestre? ");
        scanf("%f", &nota1);

        printf("\t> quanto voce tirou no segundo bimestre? ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        if (media < 7)
        {
            printf("\n\t>>> oh nao... sua media final foi %.1f, voce tera que fazer a recuperacao.\n", media);
        }
        else
        {
            printf("\n\t>>> parabens!! voce passou direto com %.1f pontos.\n", media);
        }
    }
    return 0;
}