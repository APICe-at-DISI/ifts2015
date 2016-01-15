int main(void)
{
    printf("Inserire elevamento a potenza: ");
    int num;
    int pow;
    scanf("%d^%d", &num, &pow);
    int i; // contatore
    int res = 1; // risultato parziale
    for (i = 0; i < pow; i = i + 1) {
        res = res * num;
    }
    printf("risultato = %d\n", res);
}
