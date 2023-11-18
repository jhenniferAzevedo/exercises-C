#include <stdio.h>
#include "header.h"

int main(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i;
    
    printf("\nAntes da troca. \n");
    print_array(a, 10);

    move_right(a, 2);
    printf("\nDepois da troca para direita. \n");
    print_array(a, 10);

    move_left(a, 5);
    printf("\nDepois da troca para direita. \n");
    print_array(a, 10);
    return 0;
}
