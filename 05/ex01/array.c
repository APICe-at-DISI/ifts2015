#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int size = 100;
    int *a = (int *) malloc(size * sizeof(int));
    for(int i = 0; i < size; i = i + 1) {
        a[i] = i * 2;
//        *(a + i) = i * 2;
    }
    for (int i = 0; i < size; i++) {
        // 1. a[i] == *(a + i) -- 2. a + i
        printf("Indirizzo %p, valore %d\n", a + i, a[i]);
    }
    return 0;
}


