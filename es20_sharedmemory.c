/*
la memoria condivisa permette a due o piú processi di condividere la stessa regione di memoria fisica (in RAM)

le modifiche di un processo a quest'area sono immediatamente disponibili al resto di processi che ci fa accesso

non é mediata dal kernel, bisogna implementare qualche tipo di sincronizzazione

un processo quindi avrá propria area di memoria assegnata piú l'accesso a quella condivisa

stessi concetti per il resto degli ipc

shmget() crea un nuovo segmento di SM o ritorna l'identificatore di un segmento esistente
    da non usare con puntatori (stesso discorso di accesso a indirizzo di altro processo)

per "dare accesso" dell'area condivisa ad un processo uso l'shmat()
    execve esegue detach a sua esecuzione, in progetto bisogna fare attach dopo esecuzione execve
    figlio eredita id mem condivisa di scacchiera
    torna punt a void, bisogna usare cast (struct shmseg *)

per "rimuovere accesso" dell'area condivisa ad un processo uso l'shmdt()

shmctl() per cancellare il segmento di memoria condivisa
    viene effettivamente eliminata solo quando non ha nessun processo attaccato (ipcs -m, nattch a 0)
*/