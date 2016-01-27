#include <stdlib.h>
#include <stdio.h>

// void *malloc(int size);

int main(void)
{
    printf("Valore di sizeof(int): %d\n", sizeof(int));
    printf("Valore di sizeof(long): %d\n", sizeof(long));
    printf("Valore di sizeof(double): %d\n", sizeof(double));
    printf("Valore di sizeof(int *): %d\n", sizeof(int *));
    int *a = (int *) malloc(3 * sizeof(int));
    printf("Valore di a: %p\n", a);
    printf("Valore puntato da a: %d\n", *a);
    *a = 22;
    printf("Valore di a: %p\n", a);
    printf("Valore puntato da a: %d\n", *a);
//    *(a + 1) = 33;
    a[1] = 33;
    printf("Valore puntato di a[1]: %d\n", *(a + 1));
}


