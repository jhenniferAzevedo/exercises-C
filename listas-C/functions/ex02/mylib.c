#include "header.h"

float calcular_taxas(float n_horas[], int n_cliente)
{
    float valor_taxa;
    if (n_horas[n_cliente] <= 3)
    {
        valor_taxa = 2.00;
    }
    else if (n_horas[n_cliente] <=16)
    {
        valor_taxa = 2.00 + ((n_horas[n_cliente] - 3) * 0.50);
    }
    else if (n_horas[n_cliente] <= 24)
    {
        valor_taxa = 10.00;
    }
    else
    {
        valor_taxa = -1;
    }
    
    return valor_taxa;
}