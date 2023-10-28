/* faça um programa em linguagem C para encontrar as raízes de uma equação do 2° grau com a fórmula de Bháskara. */

#include <stdio.h>
#include <math.h>
#include "header.h"

int main(void) 
{
    double a, b, c;

    printf("\nDigite os coeficientes da equacao do 2o grau: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    confere_coeficiente_a(&a, &b, &c);
    calcular_raizes(a, b, c);

    return 0;
}