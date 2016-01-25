unsigned long fattoriale(unsigned long);

int main(void)
{
    printf("%lu\n", fattoriale(5));
}

unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}