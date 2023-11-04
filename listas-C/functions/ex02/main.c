#include <stdio.h>
#include "header.h"

int main(void)
{
    int cliente = 0;
    float horas[MAX_CLIENTE], taxas[MAX_CLIENTE];

    while (cliente < MAX_CLIENTE)
    {
        printf("\n\tCliente %d"
               "\n\tTotal de horas: ", 
               cliente + 1);
        scanf("%f", &horas[cliente]);

        taxas[cliente] = calcular_taxas(horas, cliente);

        if(taxas[cliente] == -1)
        {
            printf("\n\tEsse valor excede a quantidade max!"
                   "\n\tDigite um novo valor.");
            continue;
        }

        cliente++;
    }

    puts("\nCLIENTE\t HORAS\t TAXA");
    for (cliente = 0; cliente < MAX_CLIENTE; cliente++)
    {
        printf("%d\t %.1f\t $%.2f\n", 
               cliente + 1, 
               horas[cliente], 
               taxas[cliente]);
    }
    printf("TOTAL\t %.1f\t %.2f\n",
           horas[0] + horas[1] + horas[2],
           taxas[0] + taxas[1] + taxas[2]);
    return 0;
}
