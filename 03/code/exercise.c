
int main(void)
{
    int times;
    printf("Inserire un numero intero positivo: ");
    scanf("%d", &times);
    int s = 0;
    for (; times > 0; times--) {
        int v;
        printf("Inserisci un intero: ");
        scanf("%d", &v);
        s = s + v;
    }
    printf("La somma dei numeri inseriti è: %d\n", s);
}