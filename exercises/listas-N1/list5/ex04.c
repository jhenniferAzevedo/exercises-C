/* Mostre para cada pessoa, de um conjunto de 15 pessoas,
se está acima do peso, abaixo do peso ou peso ideal.
- Peso ideal para homens: IMC de 19 a 25
- Peso ideal para mulheres: IMC de 18 a 24,5
- IMC = P/H2, onde P é o peso em kg e H é a altura em metros */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int genero, i;
    float peso, altura, imc;

    for (i = 0; i < 15; i++)
    {
        printf("\n\nPESSOA %d\n", i + 1);
        printf("\t> voce e (1) homem ou (2) mulher? ");
        scanf("%d", &genero);

        printf("\t> qual e o seu peso em kg? ");
        scanf("%f", &peso);

        printf("\t> qual e sua altura em metros? ");
        scanf("%f", &altura);

        imc = peso / (pow(altura, 2));

        if (genero == 1)
        {
            if (imc < 19)
            {
                printf("\nvoce esta abaixo do peso.\n");
            }
            else if (imc <= 25)
            {
                printf("\nvoce esta com peso o ideal.\n");
            }
            else
            {
                printf("\nvoce esta acima do peso.\n");
            }
        }
        else
        {
            if (imc < 18)
            {
                printf("\nvoce esta abaixo do peso.\n");
            }
            else if (imc <= 24.5)
            {
                printf("\nvoce esta com o peso ideal.\n");
            }
            else
            {
                printf("\nvoce esta acima do peso\n");
            }
        }
    }

    return 0;
}