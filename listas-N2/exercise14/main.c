#include <stdio.h>
#include "header.h"

int main(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i;
    
    printf("\nAntes da troca. \na[10] = { ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("}\n");

    move_right(a, 2);
    printf("\nDepois da troca para direita. \na[10] = { ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("}\n");

    move_left(a, 5);
    printf("\nDepois da troca para direita. \na[10] = { ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("}\n");
    return 0;
}
