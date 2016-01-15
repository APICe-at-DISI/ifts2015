int main(void)
{
    printf("Inserire elevamento a potenza: ");
    int num;
    int pow;
    scanf("%d^%d", &num, &pow);
    int res = 1;
    for (; pow; pow--) {
        // res += num
        // res -= num
        // res /= num
        res *= num; // res = res * num
    }
    printf("risultato = %d\n", res);
}
