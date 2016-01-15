
int main(void)
{
    printf("Inserire il primo valore: ");
    int var1;
    scanf("%d", &var1);
    printf("Inserire il secondo valore: ");
    int var2;
    scanf("%d", &var2);
    printf("%d + %d = %d\n", var1, var2, var1 + var2);
    printf("%d - %d = %d\n", var1, var2, var1 - var2);
    printf("%d * %d = %d\n", var1, var2, var1 * var2);
    if (var2) {
//    if (var2 != 0) {
        printf("%d / %d = %d\n", var1, var2, var1 / var2);
    } else {
        printf("Niente divisioni per zero!\n");
    }
}
