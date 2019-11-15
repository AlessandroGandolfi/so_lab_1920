/*
libreria signal.h

un segnale é una notifica ad un processo che é occorso un certo evento
principali cause:
    - eccezione hardware
    - utente
    - evento software
sono definiti con nomi simbolici con valore intero unico (SIGxxxx)
i valori cambiano a seconda delle implementazioni, quindi é raccomandato usare i nomi simbolici
un segnale viene consegnato ("delivered") ad un processo dopo essere stato generato
il processo che riceve il segnale esegur qualche azione in risposta al segnale
nel lasso di tempo tra la generazione e la consegna del segnale quest'ultimo é pendente ("pending")

la maschera dei segnali viene assegnata ad un processo e contiene i segnali
    la cui ricezione viene bloccata da quel processo, i segnali rimangono in pending durante l'esecuzione del processo

alla ricezione di un segnale possono essere eseguite varie azioni:
    - segnale ignorato
    - processo terminato
    - generazione di un file contenente un core dump file, processo terminato
        il file contiene un'immagine/snapshot della memoria virtuale del processo (utile per debuggare)
    - processo bloccato
    - kaay?
    - esecuzione processo ripresa

SIGABRT generato da proc al richiamo di abort()
SIGALARM generato da kernel al raggiungimento dello 0 di un timer (alarm(), setitimer())
SIGINT termina processo in foreground (ctrl+c)
SIGKILL kill del processo sicura, termina sempre un processo
SIGPIPE generato quando un processo tenta di scrivere su un pipe o un FIFO per il quale non c'è un corrispondente processo lettore
SIGEGV programma tenta un riferimento in memoria non valido

SIGUSR1, SIGUSR2 usati dal programmatore per notificare a vicenda eventi tra processi, mai generati da kernel

void (*signal(int sig, void (*handler)(int))) (int)
signal() api originale, assegna handler di un segnale
il puntatore di ritorno é quello del vecchio handler che gestiva il segnale passato come primo parametro
secondo parametro puntatore a nuovo handler (punt a funzione)
signal({segnale}, SIG_DFL) per far settare l'handler di default del segnale
nel caso non si abbia bisogno di segnali in sezione critica si utilizza una maschera poi da togliere dopo essere usciti da sezione

piú richiami di alarm in stesso processo restituiscono numero di secondi precedente alla fine
non si dovrebbe cambiare handler dopo aver settato un timer a causa di imprevidibilitá di scheduler

sigaction({segnale}, {punt struttura sigaction nuovo handler}, {punt struttura sigaction vecchio handler})
attributi struct sigaction: handler (punt a funzione), sigset_t sa_mask (maschera segnali), int sa_flags (vari flags per diverse azioni)
di default il segnale viene "mascherato" quando viene eseguito l'handler (quindi un'esecuzione di handler alla volta per ogni tipo di segnale)
    a meno che non si utilizzi il flag SA_NODEFER (merged signal se tanti segnali di stesso tipo)
funzioni per settare e modificare maschere: sigemptymask(), sigfillset(), sigaddset(), sigdelset(), sigismember()

strsignal() restituisce stringa di errore

non-async-signal-safe sono funzioni che se ricevono un segnale durante l'esecuzione possono portare a delle
    problematiche di buffer e sincronizzazione 
*/