#ifndef FATTORIALE_C
#define FATTORIALE_C

unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}
#endif
