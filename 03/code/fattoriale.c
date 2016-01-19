int fattoriale(int a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}

unsigned long fattorialeLong(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}

int getInput(void)
{
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    return num;
}

int main(void)
{
    float d;
    for (int i = 0; i < 100000; i++){
        d = d + 0.00003;
    }
    printf("%lf\n", d);
    int input = getInput();
    printf("Il fattoriale (long) è: %ld\n", fattorialeLong((unsigned long) input));
    printf("Il fattoriale (int) è: %d\n", fattoriale(input));
}
