/* testing */
#include <stdio.h>

typedef struct aaa
{
    int y, x[2];
} aaa;

int func_int(aaa this)
{
    int num1, num2;
    num1 = this.x[0] * 5;
    num2 = this.y * 10;
    return num1, num2;
}

void func_void(aaa *this)
{
    int a, b;
    a, b = func_int(*this);
    printf("\nx: %d e y: %d \n", a, b);
}

void print(aaa this)
{
    printf("\nx[0] = %d \nx[1] = %d\n", this.x[0], this.x[1]);
}

int main(int argc, char const *argv[])
{
    aaa testing;
    testing.x[0] = 10;
    testing.x[1] = 10;
    testing.y = 10;

    print(testing);
    func_void(&testing);
    return 0;
}

