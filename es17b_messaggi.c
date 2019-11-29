/*
le code di messaggi sono simili ai pipe con 2 differenze:
    - i messaggi sono delimitati, i processi comunicano in unitá di messaggi e non stream byte indefiniti
    - ogni messaggio contiene un attributo di tipo intero che ne definisce il tipo

la comunicazione per mezzo di code di messaggi é message-oriented

i messaggi si possono solo leggere interamente e uno alla volta

in strutture per definire messaggi non ha senso inserire puntatori perché passando messaggi tra 
    processi, il proc destinatario non ha accesso alle aree di memoria del proc mittente
    quindi per passare stringhe non uso malloc ma char[n] per memorizzazione differente

flag IPC_NOWAIT per non bloccare esecuzione send, receive (puó causare errori)

msgget() restituisce l'identificatore di una coda di messaggi
int msgget(key_t key, int msgflg)
    primo parametro chiave
    secondo parametro maschera di bit per definire permessi coda
        IPC_CREAT crea coda se non esistente
        IPC_EXCL usata con IPC_CREAT, errore EEXIST se coda giá esistente

msgsnd() scrive un messaggio in un coda di messaggi
int msgsnd( int msqid, const void *msgp, size_t msgsz, int msgflg)
    primo parametro identificatore coda
    secondo parametro puntatore struttura messaggio
    terzo parametro numerto bytes struttura messaggio (senza contare mtype)
    quarto parametro maschera bit per controllo send, solo IPC_NOWAIT definito

msgrcv() prende un messaggio da una coda, riotrna numero di byte copiati in campo mtext
ssize_t msgrcv(int msqid, void *msgp, size_t maxmsgsz, long msgtyp, int msgflg)
    primo parametro identificatore coda
    secondo parametro puntatore struttura messaggio
    terzo parametro grandezza consentita di messaggio ricevuto, se nessun messaggio viene ricevuto E2BIG
    quarto parametro tipo di messaggio da ricevere
        0 primo messaggio coda
        > 0 tipo di messaggio specificato
        < 0 coda di prioritá in base a mtype (piú prioritá mtype minore, es -300 messaggi ricevuti con tipo <= 300)
    quinto parametro maschera controllo receive, IPC_NOWAIT, MSG_NOERROR
*/