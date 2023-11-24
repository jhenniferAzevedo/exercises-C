#include <stdio.h>
#include "header.h"

void init_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void read_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &array[i]);
    }
} 
