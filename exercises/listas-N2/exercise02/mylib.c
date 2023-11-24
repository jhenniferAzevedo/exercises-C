#include <stdio.h>
#include "header.h"

void menu(void)
{
    printf("(1) adicao \n"
           "(2) subtracao \n"
           "(3) multiplicacao \n"
           "(4) divisao \n"
           "(5) trocar numero \n"
           "(6) finalizar \n");
}

void addition(double x, double y)
{
    printf("\n> %.2lf + %.2lf = %.2lf\n\n", x, y, x + y);
}

void subtraction(double x, double y)
{
    printf("\n> %.2lf - %.2lf = %.2lf\n\n", x, y, x - y);
}

void multiplication(double x, double y)
{
    printf("\n> %.2lf * %.2lf = %.2lf\n\n", x, y, x * y);
}

void division(double x, double y)
{
    printf("\n> %.2lf / %.2lf = %.2lf\n\n", x, y, x / y);
}

void change_number(double *x, double *y)
{
    printf("\nDigite os novos valores: ");
    scanf("%lf %lf", x, y);
}