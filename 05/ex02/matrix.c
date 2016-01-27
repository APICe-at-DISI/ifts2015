#include <stdlib.h>
#include <stdio.h>

// gcc -std=c99 matrix.c
int main(void)
{
    int sx = 5;
    int sy = 8;
    int **matrix = (int **) malloc(sx * sizeof(int *));
    for (int i = 0; i < sx; i = i + 1) {
        matrix[i] = (int *) malloc(sy * sizeof(int));
    }
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            matrix[i][j] = (i + 1) * j;
        }
    }
    matrix[0][0] = 144;
    for (int i = 0; i < sx; i++) {
        for (int j = 0; j < sy; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < sx; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}