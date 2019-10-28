// inserire in una nuova lista tutti gli studenti con matricola pari di un'altra lista dove rimarranno solo i dispari

#include <stdio.h>
#include "./student.h"

student *initStudents(student *);

int main(int argc, char **argv) {

    student *students = (student *) malloc(sizeof(student));
    student *matrPari = NULL;

    // utilizzo per ricollegare nodi dispari in lista originale
    student *prev = students;

    // testate di liste per stamparle in seguito, non obbligatorie
    student *hStud = students;
    student *hPari;

    students = initStudents(students);

    while(students != NULL) {
        if(!(students -> matr % 2)) {
            if(matrPari) {
                prev -> next = students -> next;
                matrPari -> next = students;
                matrPari = matrPari -> next;
            } else {
                prev -> next = students -> next;
                matrPari = students;
                hPari = matrPari;
            }
        } 
        
        prev = students;
        students = students -> next;
    }
    
    // stampo liste divise
    while(hStud != NULL) {
        printf("lista disp matr %d\n", hStud -> matr);
        hStud = hStud -> next;
    }

    while(hPari != NULL) {
        printf("lista pari matr %d\n", hPari -> matr);
        hPari = hPari -> next;
    }

    return 0;
}

student *initStudents(student *studentsList) {
    student *studentTemp;

    for(int i = 0; i < 10; i++) {
        if(i) { // aggiunta di nuovo elemento dal secondo in poi
            studentTemp = (student *) malloc(sizeof(student));
            studentTemp -> matr = (i + 1);
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