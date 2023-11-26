#include <stdio.h>

int fatorial(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }

    return (x * fatorial(x - 1));
}

int main()
{
    int num;
    printf("Digite um numero para descobrir seu fatorial: ");
    scanf("%d", &num);
    printf("Fatorial: %d. \n", fatorial(num));
    return 0;
}
