/* Elabore um algoritmo que informe o tipo de um triângulo (equilátero, isósceles ou escaleno) 
dado os valores dos lados. Não esquecer de verificar se os valores fornecidos correspondem 
realmente é um triângulo (um lado não pode ser maior que a soma dos outros dois). Repita, 
quantas vezes o usuário quiser. */

#include <stdio.h>

int main(void)
{
    char op;
    int a, b, c;

    do
    {
        printf("\tQuanto mede cada lado do triangulo? (separado por espaco): ");
        scanf("%d%d%d", &a, &b, &c);

        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && a == c)
            {
                printf("\t>>> O tirangulo e equilatero.\n");
            }
            else
            {
                if (a == b || a == c || b == c)
                {
                    printf("\t>>> O triangulo e isosceles.\n");
                }
                else
                {
                    printf("\t>>> O triangulo e escaleno.\n");
                }
            }
        }
        else
        {
            printf("\n\tERROR! Esse triangulo nao existe.\n");
        }
        printf("\n\n\tDeseja conferir com outros valores? \n\t(s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');
    
    printf("fim.\n");
    return 0;
}