#include <stdio.h>

double power(double base, int expoente);

int main(void)
{
    double a;
    int b;

    printf("\nDigite o valor da base: ");
    scanf("%lf", &a);
    
    printf("Digite o valor do expoente: ");
    scanf("%d", &b);
    
    while (b < 0)
    {
        printf("Apenas expoentes positivos!\n");

        printf("Digite o valor da base: ");
        scanf("%lf", &a);

        printf("Digite o valor do expoente: ");
        scanf("%d", &b);
    } 
    
    printf("O resultado final e %.1f.\n", power(a, b));
    return 0;
}

double power(double base, int expoente)
{
    int i;
    double result = 1;

    if (expoente > 0)
    {
        for (i = 0; i < expoente; i++)
        {
            result *= base;
        }
    }

    return result;
}
