/* Escreva uma função que receba 3 notas de um aluno e uma letra como parâmetros. 
Se a letra for A, a função retorna a média aritmética das  notas do aluno, se for 
P, retorna a sua média ponderada com os pesos: 5, 3 e 2. */

#include <stdio.h>
#include "header.h"

int main(void)
{
    char opcao;
    float n1, n2, n3, media;

    printf("\nDigite as tres notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    printf("\n(A) Media Aritmetica"
           "\n(P) Media Ponderada"
           "\nQual media voce deseja conferir? ");
    scanf(" %c", &opcao);

    while (opcao != 'a' && opcao != 'A' && opcao != 'p' && opcao != 'P')
    {
        printf("\nDigite uma opcao valida!!"
               "\n(A) Media Aritmetica"
               "\n(P) Media Ponderada \n");
        scanf(" %c", &opcao);
    } 

    media = calcular_media(n1, n2, n3, opcao);
    printf("\nSua media e %.2f\n\n", media);
    return 0;
}
