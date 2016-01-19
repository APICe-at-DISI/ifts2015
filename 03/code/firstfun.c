int somma(int a, int b)
{
    return a + b;
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
    int times = getInput();
    int s = 0;
    printf("I numeri inseriti d'ora in poi saranno sommati\n");
    for (; times > 0; times--) {
        int v = getInput();
        s = somma(s, v);
    }
    printf("La somma dei numeri inseriti è: %d\n", s);
}
