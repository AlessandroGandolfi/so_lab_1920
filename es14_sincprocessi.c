#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// definisce macro standard che possono essere utilizzate per interpretare un wait status
#include <sys/wait.h>

// WIFEXITED(status) restituisce true se il figlio é terminato normalmente
// WEXITSTATUS(status) restituisce l'exit status del figlio
// WIFSIGNALED(status) restituisce true se il figlio è stato ucciso da un segnale
// WTERMSIG(status) restituisce il numero del segnale che ha causato la terminazione del figlio
// WIFSTOPPED(status) restituisce true se il figlio è stato bloccato da un segnale
// WSTOPSIG(status) restituisce il numero del segnale che ha bloccato il figlio
// WIFCONTINUED(status) restituisce true se il figlio è stato risvegliato da un segnale SIGCONT

int main() {
    pid_t pid = fork();
    
    if(pid) { // padre
        char *str = (char *) malloc(sizeof(char));

        // uso waitpid() per attendere specifico figlio http://man7.org/linux/man-pages/man3/waitpid.3p.html
        // terzo parametro int options
        // WUNTRACED restituisce informazioni per segnalazioni di interruzioni tramite segnali (kill e non) di un figlio
        // WCONTINUED restiuisce informazioni nel caso un figlio stopped venga risvegliato tramite segnale SIGCONT
        // WNOHANG permette al processo chiamante della funzione di continuare l'esecuzione nel caso lo status del processo atteso non sia subito disponibile
        //      restituisce immadiatamente 0 se il figlio specificato con pid non ha cambiato stato
        //      ECHILD se si specifica pid non appartenente a un figlio 
        //      es in 11a-test_WNOHANG.c
        wait(NULL); // padre aspetta che figlio termini per leggere e stampare cosa ha letto

        FILE *fsr = fopen("./lista_nomi.txt", "r");

        fscanf(fsr, "%s", str);

        printf("%s\n", str);
        
        fclose(fsr);
    } else { // figlio
        FILE *fsw = fopen("./lista_nomi.txt", "w"); // file resettato ogni volta che viene aperto (w)

        fprintf(fsw, "ciao");

        fclose(fsw);

        exit(EXIT_SUCCESS);
    }

    return 0;
}