#include <stdio.h>
#include "header.h"

void move_right(int array[], int element)
{
    int change;
    change = array[element + 1];
    array[element + 1] = array[element];
    array[element] = change;
}

void move_left(int array[], int element)
{
    int change;
    change = array[element - 1];
    array[element - 1] = array[element];
    array[element] = change;
}

void print_array(int array[], int size)
{
    printf("a[10] = { ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("}\n");
}