#include <math.h>
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

complex complex_new(double r, double i) {
    complex new;
    new.r = r;
    new.i = i;
    return new;
}

double complex_modulo(complex a) {
    return sqrt(a.i * a.i + a.r * a.r); // bisogna includere math.h per utilizzo sqrt()
                                        // man7.org per manuale, usare -lm per corretta compilazione/collegamento con libreria
}

double complex_getReal(complex a) {
    return a.r;
}

double complex_getImaginary(complex a) {
    return a.i;
}

complex complex_sum(complex a, complex b) {
    complex c;
    c.i = a.i + b.i;
    c.r = a.r + b.r;
    return c;
}

complex complex_sub(complex a, complex b) {
    complex c;
    c.i = a.i - b.i;
    c.r = a.r - b.r;
    return c;
}

complex complex_prod(complex a, complex b) {
    complex c;
    c.r = a.r * b.r - a.i * b.i;
    c.i = a.i * b.i - a.r * b.r;
    return c;
}

// es5
// dopo aver richiamato la funzione dovrá essere usata la free() sulla variabile contenente il valore restituito
complex *complex_sum_ptr(const complex *a, const complex *b) {
    complex *c = (complex *) malloc(sizeof(complex));
    c->r = a->r + (*b).r; // a->r = (*a).r
    c->i = a->i + b->i;
    return c; 
}