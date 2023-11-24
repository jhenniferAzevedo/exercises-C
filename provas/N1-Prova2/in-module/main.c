#include <stdio.h>
#include "header.h"

int main(void)
{
    counters_data contador = {0};
    read_data(&contador);
    show_reports(contador);
    return 0;
}
