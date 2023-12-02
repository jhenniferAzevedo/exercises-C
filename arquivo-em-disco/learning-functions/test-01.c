#include <stdio.h>

int main(void)
{
    int i, e, n;
    FILE *arq;

    if ((arq = fopen("vet.dat", "a+b")) == NULL )
        return 0;
    
    do
    {
        printf("\033[33m"
               "\n(0) sair"
               "\n(1) gravar"
               "\n(2) ler"
               "\033[0m"
               "\nOp: ");
        scanf("%d", &i);

        if (i == 1)
        {
            printf("\nDigite o numero: ");
            scanf("%d", &n);
            
            /* Vai para o final */
            fseek(arq, 0, SEEK_END);
            fwrite(&n, sizeof(int), 1, arq);
        } 
        
        else if (i == 2)
        {
            printf("\nDigite o elemento: ");
            scanf("%d", &e);
            
            if ((fseek(arq, (e-1)*sizeof(int), SEEK_SET) == 0) &&
                (fread(&n, sizeof(int), 1, arq) > 0))
                printf("Elemento %d = %d\n\n", e, n);

            else
                printf("\033[31m" "Elemento inexistente. \033[0m \n\n");
        }

    } while (i == 1 || i == 2);

    printf("\n");
    return 0;
}
