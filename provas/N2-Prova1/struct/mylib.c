#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void read_data(register_data registration[], counter_data counter)
{
    int n_register = 0, result;
    do
    {
        printf("\n\tCADASTRO (%d)\n", n_register + 1);
        ask_vehicle_code(registration, n_register);
        ask_color_code(registration, n_register);
        result = ask_how_many_vehicle(registration, counter, &n_register);
        n_register++;
    } while (n_register < 25 && result != 0);
    counter.total_registers = n_register;
}
