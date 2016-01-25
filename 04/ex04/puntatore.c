#include <stdio.h>

int main(void)
{
    int a = 8;
    int *b = &a;
    int c = *b;
    printf("Valore di a: %d\n", a); // 8
    printf("Valore di c: %d\n", c); // BOH!
    printf("Valore di b: %p\n", b); // Uguale a dopo
    printf("Indirizzo in memoria di a: %p\n", &a); // Uguale a prima
    printf("Indirizzo in memoria di b: %p\n", &b); // Uguale a prima?
    printf("Indirizzo in memoria di c: %p\n", &c); // Nuovo? =&a? 
    printf("Domandona: %d\n", *((int *)((long) c))); 
    return 0;
}