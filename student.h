#include <stdlib.h>

// FIFO
typedef struct _student {
    unsigned int matr;
    char *nome;
    float mean;
    struct _student *next; // puntatore a studente dopo
} student;

student *addStudent(student *, student *);
student *removeStudent(student *, student **);

// ritorna testa della nuova lista
// primo parametro riferimento a testa lista attuale
// secondo parametro riferimento a studente da inserire
student *addStudent(student *h, student *s) {
    // nuova fine della lista
    s -> next = NULL;

    // controllo lista vuota
    if(h != NULL) {
        student *temp = h;  // elemento corrente del passo iterativo
                            // inizializzato a testa

        // ciclo per arrivare al fondo della lista
        while(temp -> next != NULL)
            temp = temp -> next;
        
        // aggiungo elemento a coda
        temp -> next = s;
    } else {
        // nel caso la lista sia vuota aggiungo subito il nuovo valore
        h = s;
    }
    
    return h;
}

// rimuove studente in testa
// ritorna testa della nuova lista
// primo parametro riferimento a testa lista attuale
// secondo parametro puntatore a struttura student da rimuovere

// voglio ritornare un altro valore oltre la testa della lista tramite il return
// uso puntatore di puntatore, se cambio variabile in funzione cambia anche in funzione che fa la chiamata
// es: student *a; remove({testa}, &a);
student *removeStudent(student *h, student **s) {
    student *temp = NULL; // usato per fare passaggio di testa da primo studente a secondo per poi rimuovere il primo

    if(h != NULL) {
        temp = h -> next; // la nuova testa diventa il secondo elemento della lista
        h -> next = NULL; // rimuovo il primo elemento
        *s = h; // passaggio puntatore a studente rimosso
    } else
        *s = NULL; // nessuno studente rimosso, lista giá vuota

    // return nuova testa
    return temp;
}