#include <stdio.h>
#include "header.h"

int main(void) {
    int vetor[10];
    init_array(vetor, 10);
    print_array(vetor, 10);
    read_array(vetor, 10);
    print_array(vetor, 10);
    return 0;
}
