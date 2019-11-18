/*
int pipe(int filedes[2])
primo parametro array di lunghezza due (se piú legge solo prime due dati)
crea un nuovo pipe, alloca un array (filedes) con due descrittori di file aperti
uno in lettura alla pos 0 e uno in scrittura alla pos 1
si possono usare le solite funzioni degli stream per scrivere e leggere sulla pipe
si usano per mettere in comunicazione due processi, prima si usa una sc pipe 
    e poi fork che copierá i descrittori del padre nel figlio
essendo le pipe leggibili in un solo verso, un processo chiude il proprio descrittore in lettura
    e l'altro chiude il proprio descrittore in scrittura (usando close())
i descrittori inutilizzati devono essere chiusi per notificare gli altri processi
uso malloc per leggere da pipe (02-test-pipe-single.c)
i descrittori di lettura si chiudono solo quando quelli di scrittura sono giá stati chiusi

eof se ci sono solo descrittori in lettura e non in scrittura
SIGPIPE se ci sono solo descrittori in scrittura e non in lettura
*/