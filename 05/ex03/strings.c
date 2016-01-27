#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// gcc -std=c99 matrix.c
int main(void)
{
    char *str = "Dimensione di un char: %d\n";
    printf(str, sizeof(char));
    char *nome = "Pluto";
    printf("Il nome del cane è: %s, di lunghezza %d\n", nome, strlen(nome));
    
    char *test = (char *) malloc(1000 * sizeof(char));
    test[0] = 'i';
    test[1] = 'f';
    test[2] = 't';
    test[3] = 's';
    test[4] = '\0';
    printf("La stringa è: %s, ed è lunga %d\n", test, strlen(test));
    printf("La stringa %s è uguale a %s? %d\n", "ifts", test, strcmp(test, "ifts"));
    return 0;
}