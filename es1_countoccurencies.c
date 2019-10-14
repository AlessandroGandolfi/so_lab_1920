// libreria per gestione i/o
#include <stdio.h>

// dichiaro la firma della funzione prima del main per non mandare in errore il compilatore
int countOccurencies(char[], int, char);

// scrivo prima il main delle altre funzioni perché non sono una scimmia
int main(int argc, char **argv) {
    int len; // lunghezza della stringa, completamente inutile ma ok

    char *str = argv[1]; // stringa nella quale si va a controllare le occorrenze del carattere
    char ctrlChar = argv[2][0]; // carattere da trovare

    /*
    char str[] = ""; // stringa nella quale si va a controllare le occorrenze del carattere
    char ctrlChar; // carattere da trovare
    scanf("%c %c", &str, &ctrlChar);
    */

    // calcolo lunghezza stringa
    for(len = 0; str[len] != '\0'; len++);

    // stampo a console il numero di occorrenze del carattere nella stringa
    printf("occorrenze:%d\tlunghezza str:%d\n", countOccurencies(str, len, ctrlChar), len);

    // termina esecuzione programma
    return 0;
}

int countOccurencies(char str[], int length, char c) {
    int count = 0, i = 0;

    // basterebbe solo il primo controllo
    while(str[i] != '\0' && i < length){
        if(str[i] == c)
            count++;
        i++;
    }

    return count;
}