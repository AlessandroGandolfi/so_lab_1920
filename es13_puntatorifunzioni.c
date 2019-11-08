// puntatori a funzioni
// devono avere la stessa firma della funzione a cui puntano
// dichiarazione
// void (*func)(...);
// utilizzo
// func = {funzione a cui puntare};
// richiamo
// (*func)(...) o func(...)

// programma con 3 parametri, 2 numeri e operazione tra somma o moltiplicazione usando puntatore a funzione
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prodotto(int, int);
int somma(int, int);

int main(int argc, char **argv) {
    if(argc == 4) {
        char *operazione = argv[3];
        int (*funzione) (int, int);
        int risultato = 0;

        funzione = (strcmp(operazione, "prodotto")) ? somma : prodotto;
        
        risultato = funzione(atoi(argv[1]), atoi(argv[2]));

        printf("risultato: %d\n", risultato);
    }

    return 0;
}

int prodotto(int num1, int num2) {
    return num1 * num2;
}

int somma(int num1, int num2) {
    return num1 + num2;
}