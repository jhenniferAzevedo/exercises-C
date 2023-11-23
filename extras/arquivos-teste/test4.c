/* testing */
#include <stdio.h>

int func(int num)
{
    int add = num + num, mult = num * num;
    return add, mult;
}

int main(int argc, char const *argv[])
{
    int test = 10, a, b;
    a, b = func(test);
    printf("a = %d e b = %d \n", a, b);
    return 0;
}
