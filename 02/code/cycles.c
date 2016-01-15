int main(void)
{
    int volte;
    printf("Inserire numero: ");
    scanf("%d", &volte);
    int i = 0;
    while(i != volte) {
        printf("Ciao per la %desima volta!\n", i + 1);
        i = i + 1;
    }
    int j;
    for (j = 0; j != volte; j = j + 1) {
        printf("Ciao per la %desima volta!\n", j + 1);
    }
}

/* volte = 2
 * j = 2
 */