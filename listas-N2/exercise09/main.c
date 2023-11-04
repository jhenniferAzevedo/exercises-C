#include <stdio.h>

void reorder(int a, int b, int c);

int main(void)
{
    int x, y, z;

    printf("digite tres numeros: ");
    scanf("%d %d %d", &x, &y, &z);

    reorder(x, y, z);
    return 0;
}

void reorder(int a, int b, int c)
{
    int change;

    /* se b < a, entao a e b trocam de valor */
    if (a > b)
    {
        change = a;
        a = b;
        b = change;
    }
    
    /* se c < a, entao a e c trocam de valor */
    if (a > c)
    {
        change = a;
        a = c;
        c = change;
    }

    /* se a > c, entao c e a trocam de valor */
    if (c < a)
    {
        change = c;
        c = a;
        a = c;
    }
    
    /* se b > c, entao c e b trocam de valor */
    if (c < b)
    {
        change = c;
        c = b;
        b = c;
    }

    printf("\nA = %d"
           "\nB = %d"
           "\nC = %d",
           a, b, c);
}