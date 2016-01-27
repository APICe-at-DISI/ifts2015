#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct umano {
    char *nome;
    char *cognome;
    int anni;
} umano;

void printUmano(umano *soggetto)
{
    printf("%s %s ha %d anni.\n", soggetto -> nome, soggetto -> cognome, soggetto -> anni);
}

umano *creaUmano(char *nome, char *cognome, int anni) {
    umano *risultato = (umano*) malloc(sizeof(umano));
    risultato -> nome = nome;
//    (*risultato).cognome = cognome;
//    risultato[0].cognome = cognome;
    risultato -> cognome = cognome;
    risultato -> anni = anni;
    return risultato;
}

int main(void)
{
    umano *mestesso = creaUmano("Danilo", "Pianini", 100);
    printUmano(mestesso);
    return 0;
}