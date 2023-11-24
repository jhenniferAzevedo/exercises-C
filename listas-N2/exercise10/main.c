#include <stdio.h>

int calcula(int x, int y);

int main(void)
{
    int a, b;

    printf("\nDigite dois valores: ");
    scanf("%d %d", &a, &b);

    a, b = calcula(a, b);
    printf("soma: %d \n"
           "subtracao: %d \n",
           a, b);
    return 0;
}

int calcula(int x, int y)
{
    int change = x;
    x = x + y;
    y = change - y;
    return x, y;
}