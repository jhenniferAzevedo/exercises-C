/* Elabore um algoritmo que dadas as medidas dos lados de um triângulo, diga se é um triângulo equilátero, 
isósceles ou escaleno. Se as medidas não corresponderem a um triângulo, mostre uma mensagem de erro. */

#include <stdio.h>

int main(void)
{
    int ladoA, ladoB, ladoC;
    printf("Quanto mede cada lado do triangulo? (separado por espaco): ");
    scanf("%d%d%d", &ladoA, &ladoB, &ladoC);

    if (ladoA + ladoB > ladoC && ladoA + ladoC > ladoB && ladoB + ladoC > ladoA)
    {
        if (ladoA == ladoB && ladoA == ladoC)
        {
            printf(">>> O tirangulo e equilatero.\n");
        }
        else
        {
            if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC)
            {
                printf(">>> O triangulo e isosceles.\n");
            }
            else
            {
                printf(">>> O triangulo e escaleno.\n");
            }
        }
    }
    else
    {
        printf("\nERROR! Esse triangulo nao existe.\n");
    }
    
    return 0;
}
