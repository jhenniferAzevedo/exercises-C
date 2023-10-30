#include <stdio.h>
#include "header.h"

int main(void)
{
    short resp;
    double a, b;

    printf("\n>>> Calculadora <<<\n");
    printf("Digite os dois valores: ");
    scanf("%lf %lf", &a, &b);

    do
    {
        printf("\nQue operacao deseja realizar? \n");
        menu();
        scanf("%hd", &resp);

        switch (resp)
        {
        case 1:
            addition(a, b);
            break;

        case 2:
            subtraction(a, b);
            break;

        case 3:
            multiplication(a, b);
            break;

        case 4:
            division(a, b);
            break;

        case 5:
            change_number(&a, &b);
            break;

        case 6:
            printf("\nEncerrando...\n\n");
            break;

        default:
            printf("\nOpcao invalida!!");
        }
    } while (resp != 6);
    return 0;
}