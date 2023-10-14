/* Ler 20 valores reais, somar cada valor lido com uma constante fornecida pelo usuário e, logo após, mostrar os resultados. */

#include <stdio.h>

int main(void)
{
    int i;
    float num[20], constante;

    printf("somar numeros a uma constante.\n");
    printf("> constante: ");
    scanf("%f", &constante);

    for (i = 0; i < 20; i++)
    {
        printf("> numero real: ");
        scanf("%f", &num[i]);
    }

    printf("\n* RESULTADOS *\n");
    for (i = 0; i < 20; i++)
    {
        printf("\t>>> %.1f + %.1f = %.1f\n", num[i], constante, num[i] + constante);
    }

    return 0;
}