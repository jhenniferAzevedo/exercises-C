#include <stdio.h>
#include <math.h>

void confere_coeficiente_a(double *a, double *b, double *c)
{
    while (*a == 0)
    {
        printf("\nEssa equacao nao e do segundo grau, nos de um valor valido!"
               "\nDigite os coeficientes da equacao do 2o grau: ");
        scanf("%lf %lf %lf", a, b, c);
    }
}

void calcular_raizes(double a, double b, double c)
{
    double x[2];
    double delta = pow(b, 2) - (4 * a * c);

    if ((b == 0) && (c == 0))
    {
        printf("A equacao possui ambas as suas raizes igual a zero.\n\n");
    } 
    else if (delta < 0) 
    {
        printf("A equacao nao possui raizes reais.\n\n");
    } 
    else if (delta == 0) 
    {
        x[0] = x[1] = -b / (2 * a);
        printf("A equacao possui uma raiz dupla: %.2f\n\n", x[0]);
    } 
    else 
    {
        x[0] = (-b + sqrt(delta)) / (2 * a);
        x[1] = (-b - sqrt(delta)) / (2 * a);
        printf("A equacao possui duas raizes reais: %.2f e %.2f\n", x[0], x[1]);
    }
}