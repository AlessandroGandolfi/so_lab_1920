// inserire in una nuova lista tutti gli studenti con matricola pari di un'altra lista dove rimarranno solo i dispari

#include <stdio.h>
#include <time.h>
#include "./student.h"

student *initStudents(student *);

int main(int argc, char **argv) {

    student *students = (student *) malloc(sizeof(student));
    student *matrPari = NULL;

    // utilizzo per ricollegare nodi dispari in lista originale
    student *prev = students;

    // testate di liste per stamparle in seguito, non obbligatorie
    student *hDisp = students;
    student *hPari;

    students = initStudents(students);

    // stampa lista originale
    student *hOrig = students;
    while(hOrig != NULL) {
        printf("lista orig matr %d\n", hOrig -> matr);
        hOrig = hOrig -> next;
    }

    printf("------------------\n");

    while(students != NULL) {
        // controllo per vedere se la matricola del nodo corrente é pari o meno
        if(!(students -> matr % 2)) {
            if(matrPari) { // da secondo elemento in poi
                matrPari -> next = students;
                matrPari = matrPari -> next;
                // link del nodo precedente a quello successivo dato che devo rimuovere quello corrente (generazione lista dispari)
                prev -> next = students -> next;
            } else { // primo elemento in lista nuova
                matrPari = students;
                hPari = matrPari;
                prev -> next = students -> next;
            }
        } else 
            // il precedente deve sempre essere l'ultimo DISPARI, quindi faccio passaggio solo quando trovo nodo corrente dispari
            prev = students;
        
        students = students -> next;
    }

    // ultimo puntatore next di lista pari a NULL
    matrPari -> next = NULL;
    
    // stampa liste divise
    while(hDisp != NULL) {
        printf("lista disp matr %d\n", hDisp -> matr);
        hDisp = hDisp -> next;
    }

    printf("------------------\n");

    while(hPari != NULL) {
        printf("lista pari matr %d\n", hPari -> matr);
        hPari = hPari -> next;
    }

    return 0;
}

student *initStudents(student *studentsList) {
    srand(time(NULL));
    student *studentTemp;

    for(int i = 0; i < 10; i++) {
        if(i) { // aggiunta di nuovo elemento dal secondo in poi
            studentTemp = (student *) malloc(sizeof(student));
            studentTemp -> matr = rand() % 20;
            studentTemp -> nome = (char *) 65 + i;
            studentTemp -> mean = i % 2;
            studentTemp -> next = NULL;
            studentsList = addStudent(studentsList, studentTemp);
        } else { // valorizzazione primo elemento di lista giá presente a inizializzazione con malloc
            studentsList -> matr = (i + 1);
            studentsList -> nome = (char *) 65 + i;
            studentsList -> mean = i % 2;
            studentsList -> next = NULL;
        }
    }

    return studentsList;
}