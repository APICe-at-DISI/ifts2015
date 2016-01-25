#include <stdio.h>

void f(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    printf("PRIMA: a = %d, b = %d\n", a, b);
    f(&a, &b);
    printf("DOPO: a = %d, b = %d\n", a, b);
    return 0;
}
