#include <stdio.h>
#include <math.h>
#include "header.h"

int main(void) 
{
    double a, b, c;

    printf("\nDigite os coeficientes da equacao do 2o grau: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    confere_coeficiente_a(&a);
    calcular_raizes(a, b, c);

    return 0;
}