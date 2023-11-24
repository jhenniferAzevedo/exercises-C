#include <stdio.h>
#include "header.h"

double valor_absoluto(double x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}