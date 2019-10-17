// FIFO
typedef struct {
    unsigned int matr;
    char *nome;
    float mean;
    struct student *next; // collegamento a studente dopo
} student;

// ritorna testa della nuova lista
// primo parametro riferimento a testa lista attuale
// secondo parametro riferimento a studente da inserire
student *add(student *h, student *s) {

}

// rimuove studente in testa
// ritorna testa della nuova lista
// primo parametro riferimento a testa lista attuale
student *remove(student *h) {

}