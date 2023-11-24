#include <stdio.h>
#include "header.h"

float calcular_media(float a, float b, float c, char op)
{
    float media;

    switch (op)
    {
    case 'a':
    case 'A':
        media = (a + b + c) / 3;
        break;
    
    case 'p':
    case 'P':
        media = (a * 5 + b * 3 + c * 2) / 10;
        break;
    }
    
    return media;
}