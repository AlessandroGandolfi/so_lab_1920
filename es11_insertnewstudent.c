// inserire un nuovo studente in lista ordinata in base alla matricola

#include <stdio.h>
#include "./student.h"

student *initStudents(student *);

int main(int argc, char **argv) {

    if(argc == 4) {
        int flag = 0;   
        student newStudent;
        student *students = NULL;
        students = (student *) malloc(sizeof(student));
        students = initStudents(students);
        
        newStudent.nome = argv[1];
        newStudent.matr = atoi(argv[2]);
        newStudent.mean = argv[3][0];
        newStudent.next = NULL;

        while(students != NULL) {
            if(!flag) {
                if(students -> matr < newStudent.matr && students -> next -> matr > newStudent.matr) {
                    newStudent.next = students -> next;
                    students -> next = &newStudent;
                    printf("matr %d\n", students -> matr);
                    flag++;

                    students = students -> next;
                } else if(students -> matr > newStudent.matr) {
                    newStudent.next = students;
                    students = &newStudent;
                    printf("matr %d\n", students -> matr);
                    flag++;

                    students = students -> next;
                } else if(students -> next == NULL && students -> matr < newStudent.matr) {
                    students -> next = &newStudent;
                    printf("matr %d\n", students -> matr);
                    flag++;

                    students = students -> next;
                }
            }
            
            printf("matr %d\n", students -> matr);
            students = students -> next;
        }

        free(students);

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
        } else { // valorizzazione primo elemento di lista giá presente
            studentsList -> matr = (i + 1) * 10;
            studentsList -> nome = (char *) 65 + i;
            studentsList -> mean = i % 2;
            studentsList -> next = NULL;
        }
    }

    return studentsList;
}