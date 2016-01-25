#include "fattoriale.h"

unsigned long fattoriale(unsigned long a)
{
    if (a == 0) {
        return 1;
    }
    return a * fattoriale(a - 1);
}
