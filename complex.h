// esempio struttura numero complesso
typedef struct _complex {
    double i; // parte immaginaria
    double r; // parte reale
} complex;

// firme funzioni
complex complex_new(double, double);
double complex_modulo(complex);
double complex_getReal(complex);
double complex_getImaginary(complex);
complex complex_sum(complex, complex);
complex complex_sub(complex, complex);
complex complex_prod(complex, complex);

// es5
complex *complex_sum_ptr(const complex *, const complex *);