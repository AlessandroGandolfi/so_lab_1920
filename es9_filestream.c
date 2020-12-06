// file-stream, tipo di dato FILE (maiuscolo come costanti simboliche anche se non lo é)
// definito in librerie con typedef, tecnicamente struttura con molti campi

// fopen() apre stream di file
// FILE *fopen(const char *pathname, const char *mode)
// restituisce puntatore a stream appena aperto
// primo parametro stringa con path di un file
// secondo parametro modalitá di apertura di stream
// sola lettura "r", stream a inizio file, errore se file non esiste
// lettura e scrittura "r+", stream a inizio file, errore se file non esiste
// sola scrittura "w", tronca file a lunghezza 0 (cancella file se giá esistente) o lo crea se non esiste, stream a inizio file
// lettura e scrittura "w+", come "w" ma anche in lettura
// concatenare/appendere "a", file creato se non esistente, stream a fondo file
// lettura e concatenazione "a+", come "a" con lettura, dipende da piattaforma la posizione di inizio per la lettura
// specificare che il file binario suffisso "b" (es. lettura di un file binario "rb")
// chiudo fs con fclose() quando non ne ho piú bisogno, fs da chiudere come parametro
// feof() check di fine file passando fs come parametro

// per file testuali
// int getc(FILE* fs), getchar()
// leggono un carattere da un fs
// getc restituisce il valore in bit (tra 0 e 255) del prossimo carattere o condizioni/eventi verificati per valori < 0 o > 255, EOF cost simb per fine file
// getchar legge da stdin (fs "standard input" come val 0 in es8, default da tastiera), restituisce int ma senza parametri
// getc(stdin) = getchar()

// putc(), putchar()
// scrivono un carattere in un fs
// putc(stdout) = putchar()

// fscanf()
// lettura di una parola da un fs

// fprintf()
// stampo messaggio formattato in un fs passato come primo argomento

#include <stdio.h>

int main(int argc, char **argv) {
    if(argc == 2) {
        FILE *fs = fopen(argv[1], "r");

        if(fs) {// fs != NULL
            int c;

            while((c = getc(fs)) != EOF) // stampo ogni carattere fino a quando non finisce il file
                printf("%c", c);

            printf("\n");

            fclose(fs);
        } else 
            perror(argv[1]); // stampa a video stringa parametro piú errore "precostruito" generato da ultima chiamata a funzione di lib stdio
    } else
        printf("Usage: test_fopen <pathname>\n");

    return 0;
}