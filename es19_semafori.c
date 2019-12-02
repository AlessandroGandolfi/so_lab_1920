/*
header sys/sem.h

un semaforo é un intero mantenuto dal kernel il cui valore é sempre maggiore o uguale a 0
il processo che fa il controllo sul semaforo cercherá di sottrarre un certo valore intero da quello del semaforo
    se il risultato della sottrazione é negativo allora il processo si blocca

se un proc master deve fare partire piú processi assieme puó settare un semaforo a 1 e diminuirlo quando
    gli altri processi sono in "wait for 0"

semget non alloca un solo semaforo ma ne alloca un array/set
    quando ho bisogno solo di un semaforo avró un array di lunghezza 1
    torna l'identificatore del set di semafori
    non é possibile modificare il numero di semafori in un set una volta creato

semctl viene principalmente usato per l'inizializzazione dei semafori
    flag SETVAL per settarne solo uno
    flag SETALL per settare tutti i semafori dell'array allocato con semget
    flag IPC_RMID per rimuovere l'intero set quando non vengono piú usati dai processi

semop permette di eseguire azioni su piú semafori di uno stesso set/gruppo/array
    é bloccante quando il membro sem_op é minore di zero e il suo valore assoluto 
    é maggiore di quello del semaforo, serve per sincronizzazione (semctl non é bloccante)
    se anche solo uno dei semafori dell'intero set non puó eseguire l'operazione 
        anche il resto le operazioni sul resto dei semafori vengono bloccate

semtimedop come semop ma il processo resta al massimo un certo periodo (timer) in attesa
    se il timer scade l'operazione non viene eseguita e il richiamo torna -1 (errno EAGAIN)

per esempio di sincronizzazione ordinata tra processi per progetto guardo 03-test-pipe-round.c 
    utilizzo token, proc rilascia token a quello successivo con sem_release(s_id, (i == NUM_PROC-1) ? 0 : (i + 1) );
*/