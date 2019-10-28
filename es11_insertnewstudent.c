// inserire un nuovo studente in lista ordinata in base alla matricola

#include <stdio.h>
#include "./student.h"

student *initStudents(student *);

int main(int argc, char **argv) {

    if(argc == 4) {
        int addedFlag = 0; // permette di continuare a ciclare per stampare la lista dopo aver aggiunto il nuovo studente, non obbligatorio
        student newStudent;
        student *students = NULL;
        // senza malloc esplode
        students = (student *) malloc(sizeof(student));
        students = initStudents(students);
        
        newStudent.nome = argv[1];
        newStudent.matr = atoi(argv[2]);
        newStudent.mean = argv[3][0];
        newStudent.next = NULL;

        while(students != NULL) {
            // dopo il primo inserimento non esegue piú i controlli
            if(!addedFlag) {
                // se non eseguo questo controllo va in segmentation fault quando punta students -> next -> matr dell'ultimo elemento
                if(students -> next != NULL) {
                    // inserimento in mezzo a lista
                    if(students -> matr < newStudent.matr && students -> next -> matr > newStudent.matr) {
                        newStudent.next = students -> next;
                        students -> next = &newStudent;
                        printf("matr %d\n", students -> matr);
                        addedFlag++;

                        students = students -> next;
                    // inserimento primo elemento
                    } else if(students -> matr > newStudent.matr) { 
                        newStudent.next = students;
                        students = &newStudent;
                        printf("matr %d\n", students -> matr);
                        addedFlag++;

                        students = students -> next;
                    }
                // inserimento ultimo elemento
                } else if(students -> matr < newStudent.matr) {
                    // non uso addStudent perché ritornerebbe alla testa della lista
                    students -> next = &newStudent;
                    printf("matr %d\n", students -> matr);
                    addedFlag++;
                
                    students = students -> next;
                }
            }
            
            printf("matr %d\n", students -> matr);
            students = students -> next;
        }

        free(students); // non obbligatoria in quanto la funzione finisce subito dopo

    } else
        printf("Usage: es11_insertnewstudent <nome> <matricola> <sesso>\n");

    return 0;
}

student *initStudents(student *studentsList) {
    student *studentTemp;

    for(int i = 0; i < 4; i++) {
        if(i) { // aggiunta di nuovo elemento dal secondo in poi
            studentTemp = (student *) malloc(sizeof(student));
            studentTemp -> matr = (i + 1) * 10;
            studentTemp -> nome = (char *) 65 + i;
            studentTemp -> mean = i % 2;
            studentTemp -> next = NULL;
            studentsList = addStudent(studentsList, studentTemp);
        } else { // valorizzazione primo elemento di lista giá presente a inizializzazione con malloc
            studentsList -> matr = (i + 1) * 10;
            studentsList -> nome = (char *) 65 + i;
            studentsList -> mean = i % 2;
            studentsList -> next = NULL;
        }
    }

    return studentsList;
}