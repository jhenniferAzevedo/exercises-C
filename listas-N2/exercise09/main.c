#include <stdio.h>

int reorder(int a, int b, int c);

int main(void)
{
    int x, y, z;

    printf("digite tres numeros: ");
    scanf("%d %d %d", &x, &y, &z);

    x, y, z = reorder(x, y, z);

    printf("\nX = %d"
           "\nY = %d"
           "\nZ = %d",
           x, y, z);
    return 0;
}

int reorder(int a, int b, int c)
{
    int change;

    if (a > b)
    {
        change = a;
        a = b;
        b = change;
    }
    
    if (a > c)
    {
        change = a;
        a = c;
        c = change;
    }

    if (c < b)
    {
        change = c;
        c = b;
        b = change;
    }

    return a, b, c;
}
