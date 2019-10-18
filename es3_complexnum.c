// libreria per printf
#include <stdio.h>

// definizione struttura e firme funzioni
#include "./complex.h"

int main() {
    complex n1, n2, sum;

    n1 = complex_new(32.3, 1.0);
    n2 = complex_new(0., 0.);
    sum = complex_sum(n1, n2);

    printf("La somma é %f + %f.i\n", complex_getReal(sum), complex_getImaginary(sum));
}