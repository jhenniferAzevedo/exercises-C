#include <stdio.h>
#include "header.h"

void read_data(contact_data contact[])
{
    int counter = 0;
    do
    {
        printf("\nAdicionando contatos a lista de contatos.\n");
        printf("\tNome: ");
        fgets(contact[counter].name, 100, stdin);

        printf("\tEmail: ");
        fgets(contact[counter].email, 50, stdin);

        printf("\tNumero: ");
        scanf("%d", &contact[counter].number);
    } while (0);
}
