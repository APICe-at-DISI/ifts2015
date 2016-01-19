/*
 * int -> %d -> interi
 * long -> %ld -> interi più grossi
 * float -> %f -> con virgola
 * double -> %lf -> con virgola più precisi
 * 
 * unsigned int -> %u -> come int, ma solo positivi (e un bit più preciso)
 * unsigned long -> %ul -> come int, ma solo positivi (e un bit più preciso)
 * 
 * Scrivere numeri:
 * int -> numero in base 10 (e.g. 45), numero in base 8 (e.g. 010 = 8 decimale), numero in base 16 (e.g. 0xF = 15)
 * long = numero in base 10 (seguito da L se troppo grosso)
 * float = numero in base 10 seguito da f (e.g. 10f), oppure numero con virgola seguito da f (e.g. 0.45f)
 * double = numero con virgola (e.g. 3.45)
 * 
 * 
 * 
 */
int main(void) {
    long a = 0xFFFFFFFFL;
    int b = (int) a; //cast
    printf("Come double: %ld\n come int: %d\n", a, b);
}
