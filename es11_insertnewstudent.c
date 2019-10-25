// inserire un nuovo studente in lista ordinata in base alla matricola

#include <stdio.h>
#include "./student.h"

student *initStudents(student *);

int main(int argc, char **argv) {

    if(argc == 4) {        
        student newStudent;
        student *students = (student *) malloc(sizeof(student));
        students = initStudents(students);
        student *temp = students;

        newStudent.nome = argv[1];
        newStudent.matr = atoi(argv[2]);
        newStudent.mean = argv[3][0];
        newStudent.next = NULL;

        while(temp -> next != NULL) {
            if(temp -> matr < newStudent.matr && temp -> next -> matr > newStudent.matr) {
                newStudent.next = temp -> next;
                temp -> next = &newStudent;
                temp = temp -> next;
            }
            
            printf("matr %d\n", temp -> matr);
            temp = temp -> next;
        }

        free(students);

    } else
        printf("Usage: es11_insertnewstudent <nome> <matricola> <sesso>\n");

    return 0;
}

student *initStudents(student *studentsList) {
    student *studentTemp;

    for(int i = 0; i < 4; i++) {
        studentTemp = (student *) malloc(sizeof(student));
        studentTemp -> matr = (i + 1) * 10;
        studentTemp -> nome = (char *) 65 + i;
        studentTemp -> mean = i % 2;
        studentTemp -> next = NULL;
        studentsList = addStudent(studentsList, studentTemp);
    }

    // studentTemp.matr = 10;
    // studentTemp.nome = "apapappap";
    // studentTemp.mean = 1;
    // studentTemp.next = NULL;
    // studentsList = addStudent(studentsList, &studentTemp);
    
    // studentTemp.matr = 20;
    // studentTemp.nome = "dhhdhdhhhddhdh";
    // studentTemp.mean = 0;
    // studentTemp.next = NULL;
    // studentsList = addStudent(studentsList, &studentTemp);

    // studentTemp.matr = 30;
    // studentTemp.nome = "jwbkbdjbk";
    // studentTemp.mean = 1;
    // studentTemp.next = NULL;
    // studentsList = addStudent(studentsList, &studentTemp);

    // studentTemp.matr = 40;
    // studentTemp.nome = "ultimo";
    // studentTemp.mean = 0;
    // studentTemp.next = NULL;
    // studentsList = addStudent(studentsList, &studentTemp);

    return studentsList;
}