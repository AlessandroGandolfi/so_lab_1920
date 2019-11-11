#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if(pid) { // padre
        char *str = (char *) malloc(sizeof(char));

        // uso waitpid() per attendere specifico figlio http://man7.org/linux/man-pages/man3/waitpid.3p.html
        // terzo parametro int options
        // WUNTRACED restituisce informazioni per segnalazioni di interruzioni tramite segnali (kill e non) di un figlio
        // WCONTINUED restiuisce informazioni nel caso un figlio stopped venga risvegliato tramite segnale SIGCONT
        // WNOHANG permette al processo chiamante della funzione di continuare l'esecuzione nel caso lo status del processo atteso non sia subito disponibile
        wait(NULL); // padre aspetta che figlio termini per leggere e stampare cosa ha letto

        FILE *fsr = fopen("./lista_nomi.txt", "r");

        fscanf(fsr, "%s", str);

        printf("%s\n", str);
    } else { // figlio
        FILE *fsw = fopen("./lista_nomi.txt", "w"); // file resettato ogni volta che viene aperto (w)

        fprintf(fsw, "ciao\n");

        exit(EXIT_SUCCESS);
    }

    return 0;
}