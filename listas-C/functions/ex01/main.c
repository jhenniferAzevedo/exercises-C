/* Para conferir se o resultado está certo, compile. */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    x = fabs(7.5);
    printf("x = %f\n", x);

    x = floor(7.5);
    printf("x = %f\n", x);

    x = fabs(0.0);
    printf("x = %f\n", x);

    x = ceil(0.0);
    printf("x = %f\n", x);

    x = fabs(-6.4);
    printf("x = %f\n", x);

    x = ceil(-6.4);
    printf("x = %f\n", x);

    x = ceil(-6.4);
    printf("x = %f\n", x);
    return 0;
}
