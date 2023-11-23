/* testing */
#include <stdio.h>

void question(int *answer);
void check_answer(int *answer);

int main(int argc, char const *argv[])
{
    int resp;

    question(&resp);
    check_answer(&resp);
    printf("Parabens! Voce digitou o numero %d. \n", resp);

    return 0;
}

void check_answer(int *answer)
{
    while (*answer < 1 || *answer > 5)
        question(answer);
}

void question(int *answer)
{
    printf("\nDigite um numero de 1 a 5: ");
    scanf("%d", answer);
    check_answer(answer);
}


