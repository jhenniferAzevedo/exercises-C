/* Declare três matrizes quadradas (a, b e c). Então leia ou gere aleatoriamente
os números nas duas matrizes a e b. Após isso multiplique-as uma pela outra e mostre
o resultado da multiplicação (a matriz c irá receber o resultado). Lembre-se de
verificar se as matrizes possuem dimensões compatíveis para a multiplicação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 3

int main(void)
{
    int i, j, k, a[TAM_MAX][TAM_MAX], b[TAM_MAX][TAM_MAX], c[TAM_MAX][TAM_MAX] = {0};
    srand(time(NULL));

    printf("\nMATRIZ A\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            a[i][j] = rand() % 20;
            printf("[%d]  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ B\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            b[i][j] = rand() % 20;
            printf("[%d]  ", b[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZE C\n");
    for (i = 0; i < TAM_MAX; i++)
    {
        for (j = 0; j < TAM_MAX; j++)
        {
            for (k = 0; k < TAM_MAX; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("[%d]  ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* Como cheguei nesse resultado? 
multiplicar as linhas de A por cada coluna de B
--> exemplo:
A
    [0,0] [0,1]
    [1,0] [1,1]
( *2* x 2) --> *2* quantidade de linhas de A

B
    [0,0] [0,1] [0,2]
    [1,0] [1,1] [1,2]
( 2 x *3* ) --> *3* quantidade de colunas de B

--> a matriz c terá a dimensão [qntLinhaA] x [qntColunaB]

C
    [0,0] [0,1] [0,2]
    [1,0] [1,1] [1,2]
( *2* x *3* )   -->   linha de A x coluna de B

--> agora é só multiplicar cada coluna de A por cada linha de B

C
c(0,0) = a(0,0)*b(0,0) + a(0,1)*b(1,0)
c(0,1) = a(0,0)*b(0,1) + a(0,1)*b(1,1)
c(0,2) = a(0,0)*b(0,2) + a(0,1)*b(1,2)
c(1,0) = a(1,0)*b(0,0) + a(1,1)*b(1,0)
c(1,1) = a(1,0)*b(0,1) + a(1,1)*b(1,1)
c(1,2) = a(1,0)*b(0,2) + a(1,1)*b(1,2)

--> em resumo
c(i,j) += a(i,k)*b(k,j);

se quiser comparar a compatibilidade das matrizes, é só pedir
pro usurário digitar a dimensão ou gerar aleatoriamente e colocar
a condição antes de começar a atribuir valores à matriz.
 */