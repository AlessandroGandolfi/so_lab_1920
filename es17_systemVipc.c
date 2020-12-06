/*
semafori:
    - usati per sincronizzazione processi
    - valore intero mantenuto dal kernel, visibile a processi con permessi necessari

shared memory:
    - segmento di memoria condiviso da vari processi
    - modifiche a valori immediatamente disponibili ad altri processi

ipcs --> elenca le risorse IPC definite
ipcs –l --> elenco dei limiti definiti per le risorse IPC
ipcmk --> crea una nuova risorsa IPC
ipcrm --> elimina una risorsa IPC

data una key, la system call get del meccanismo ipc usato crea un nuovo oggetto con la key specificata
    o restituisce l'identificatore di un oggetto ipc

IPC_EXCL flag per dichiarare quale processo é il creatore dell'oggetto ipc
nel caso l'oggetto sia giá stato creato la get restituisce l'errore EEXIST

la system call ctl esegue operazioni di controllo sugli oggetti ipc
alcune operazioni sono comuni a tutti gli oggetti mentre altre sono specifiche
IPC_RMID, comune, cancella l'oggetto
    cancellazione immediata per code messaggi e semafori con relativo contenuto
    per memoria condivisa la cancellazione avviene solo dopo che tutti i processi che la stanno utilizzando eseguono il detach

kernel persistence: 
    - gli oggetti continuano ad esistere fino alla loro esplicita cancellazione (requisito esame) o shutdown sistema
    - condivisione oggetti tra processi
    - limiti di sistema sul massimo numero di oggetti creabili
    - "connectionless", il kernel non tiene traccia dei proc connessi agli oggetti

le keys sono rappresentate dal tipo key_t
la get mappa la key sull'identificatore interno dell'oggetto
identificatore unico per ogni nuovo oggetto
con stessa key si avrá sempre lo stesso identificatore

per generare una key:
    - scelta casuale intero in header file comune
    - utilizzo costante IPC_PRIVATE come valore della key, produzione chiave unica sicura
    - funzione ftok probabile chiave sicura

con IPC_PRIVATE gli altri flag IPC_CREAT e IPC_EXCL non sono necessari
utile quando oggetto ipc viene creato prima di fork da padre, figlio eredita identificatore oggetto 

ftok genera una chiave in base al pathname e l'intero passati come parametri
in caso di diversi richiami con gli stessi parametri, la chiave sará sempre uguale
*/