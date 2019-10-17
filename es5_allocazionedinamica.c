// malloc (Memory ALLOCation)
// unico parametro, indica numero di byte che si vorrebbe allocare in memoria tramite SO, di solito chiamato "size" (tipo size_t)
// restituisce puntatore a zona di memoria di "size" byte a meno che non si usi un cast
// malloc usa globale errno in lib per comunicare a chiamante l'errore di out of memory (ENOMEM) o superato il limite di un certo valore di memoria (RLIMIT_AS o RLIMIT_DATA)
// implementazione malloc in es3
#include <stdlib.h>

// gestione errori
#include <errno.h>
int main() {
    int *buf;   // puntatore generico (void *)
                // puntatere int (int *)
    int len = 438;

    buf = (int *) malloc(sizeof(int) * len); // buf conterrá indirizzo di memoria di array di 438 interi

    // alternativa a malloc, piú conveniente per array
    // primo parametro lunghezza
    // secondo parametro numero byte di tipo
    // buf = (int *) calloc(len, sizeof(int));

    // realloc usata con zona di memoria precedentemente usata con malloc o calloc
    // primo parametro puntatore di zona
    // secondo parametro nuova size, se piú grande di quello originale i dati restano invariati
    // restituisce nuovo puntatore

    if(buf != NULL) {
        // punta a secondo int di array
        *(buf + 1);
        // oppure
        buf[1];

        // il programmatore é responsabile del rilasciamento di memoria
        // la memoria se non rilasciata rimane allocata fino alla fine dell'esecuzione del programma
        // possibili memory leak se non si rilasciano le variabili
        free(buf);
    } else {
        // gestione errore

        // out of memory
        if(errno == ENOMEM) {
            
        }
    }
}