#include <stdio.h>

void fibonacci(int max)
{
    int x[max];
    x[0] = 0;
    x[1] = 1;
    
    printf("\n%s", "Sequencia fibonacci: {");
    for (int i = 2; i < max; i++)
    {
        x[i] = x[i - 1] + x[i - 2];
        if (i < (max - 1)) {
            printf("%d, ", x[i]);
            continue;
        }
        printf("%d.} \n", x[i]);
    }
}

/*
    0
    primeiro 1
    0 + 1 = 1
    1 + 1 = 2
    1 + 2 = 3
    2 + 3 = 5
    3 + 5 = 8
    8 + 5 = 13
    ...
*/

int main()
{
    int num;
    
    printf("Deseja ver quantos numeros da sequencia fibonacci? ");
    scanf("%d", &num);
    /*
    printf("Fibonacci: %d. \n", fibonacci(num));
    */
    fibonacci(num);
    return 0;
}

/* 
 * 
 * 
 * 
 */
