#include <stdio.h>

float power(float base, float expoente);

int main(void)
{
    float a, b;

    printf("\nDigite o valor da base e do expoente: ");
    scanf("%f %f", &a, &b);
    
    while (b < 0)
    {
        printf("Apenas expoentes positivos!\n");
        printf("\nDigite o valor da base e do expoente: ");
        scanf("%f %f", &a, &b);
    } 
    
    printf("O resultado final e %.1f.\n", power(a, b));
    return 0;
}

float power(float base, float expoente)
{
    int i;
    float result = 1;

    if (expoente > 0)
    {
        for (i = 0; i < expoente; i++)
        {
            result *= base;
        }
    }

    return result;
}
